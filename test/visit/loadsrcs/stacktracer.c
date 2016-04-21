/* dladdrを使うためのGNU拡張を使用(rdynamic指定でコンパイルされてる必要がある) */
#define _GNU_SOURCE 
#include <dlfcn.h>

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdint.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#include "stacktracer.h"


static function_call_stack_data stack[4096];
static int stack_count = 0;
static function_call_stack_data data;
extern void* __builtin_frame_address(unsigned int level);
static int fd_stack_dump;
static char writebuff[512];

static void stacktracer_initialize() {

    fd_stack_dump = create_dump_file();
    if ( fd_stack_dump == -1 ) {
        abort();
    }
}

static void stacktracer_destruct() {

}

void __cyg_profile_func_enter(void* func_addr, void* call_site) {

    data.func_addr = func_addr;
    data.call_site = call_site;
    data.frame_addr  = (void*)__builtin_frame_address(0);
    data.call_frame_addr = (void*)__builtin_frame_address(1);
    data.stack_size  = data.call_frame_addr - data.frame_addr;
    function_stack_push(&data);

    /* stack before */
    sprintf(writebuff, "\n\n -- %s (%p) using stack %u(0x%x) byte - before ", 
            get_function_name(func_addr), func_addr, data.stack_size, data.stack_size );
    output(writebuff, strlen(writebuff));
    dump_stack_binary(data.frame_addr, data.call_frame_addr);
}


void __cyg_profile_func_exit(void* func_addr, void* call_site) {

    function_call_stack_data *data = function_stack_pop();

    /* stack after */
    sprintf(writebuff, "\n\n -- %s (%p) - after ", get_function_name(func_addr), func_addr);
    output(writebuff, strlen(writebuff));
    dump_stack_binary(data->frame_addr, data->call_frame_addr);
}

/**
 * @brief 実際にファイルに出力する
 */
void output_dumpfile(const char* buff, size_t size) {

    write(fd_stack_dump, buff, size);
}
void (*output)(const char* buff, size_t size) = output_dumpfile;



/**
 * @brief アドレスから関数名を取得する
 *
 */
const char* get_function_name(const void* funcaddr) {

    static Dl_info dli;
    if ( dladdr( funcaddr, &dli ) == 0 ) {
        return "";
    }

    if ( dli.dli_sname ) {
        return dli.dli_sname;
    }

    return "";
}

/**
 * @brief アドレス表示するべきアドレスかを判定する
 *
 * 1列32byte区切りとする
 *
 */
int  is_dump_address( const void* addr ) {

    if ( (uint64_t)addr % (uint64_t)0x20){
        return 0;
    }
    return 1;
}

/**
 * @brief アドレス表示位置までスキップする
 */
void skip_to_dumpaddr(const void* addr) {

    static const uint32_t* ptr;
    static char            buff[512];
    static size_t          size;

    ptr = addr;

    /* 引数値がアドレス表示位置の場合は何も表示しない */
    if ( is_dump_address(ptr) ) return;

    while ( ! is_dump_address(ptr) ) ptr --;
    size = sprintf(buff, "\n%p: ", ptr);
    while ( ptr != addr ) {
        size += sprintf(buff + size, "%8s ", " ");
        ptr ++;
    }
    output(buff, size);
}

/**
 * @brief 開始と終了位置を指定して指定アドレスをダンプする
 */
void dump_stack_binary( const void* from, const void* to) {

    static const uint32_t* ptr;
    static size_t wsize;

    if ( !from || !to ) return;

    ptr = (uint32_t*)from;
    skip_to_dumpaddr(ptr);

    for ( ptr = from; ptr <= (uint32_t*)to; ptr ++ ) {
        wsize = 0;
        if ( is_dump_address(ptr) ) {
            wsize += sprintf(writebuff + wsize, "\n%p: ", ptr);
        }
        wsize += sprintf(writebuff + wsize, "%08x ", *ptr);
        output(writebuff, wsize);
    }
}


/**
 * @brief スタックダンプを出力するファイルを作成する 
 */
int create_dump_file() {

    const char* fname = "stack_dump.log";
    int fd = open(fname, O_CREAT | O_WRONLY, 0666);
    if ( fd == -1 ) {
        printf("cannot open %s, %s", fname, strerror(errno));
        fflush(stdout);
        return -1;
    }
    return fd;
}


/**
 * @brief スタックを空にする
 */
void function_stack_clear() {
    stack_count = 0;
}

/**
 * @brief スタックが空かどうかを調べる
 */
int function_stack_is_empty() {

    return ( !stack_count );
}

/**
 * @brief 関数コールスタックに詰む
 */
void function_stack_push(function_call_stack_data* data) {

    memcpy(stack + stack_count, data, sizeof(function_call_stack_data));
    stack_count ++;
}

/**
 * @brief 関数コールスタックの先頭を参照する
 *
 */
function_call_stack_data* function_stack_peek() {

    if ( function_stack_is_empty() ) {
        return NULL;
    }
    return &stack[stack_count - 1];
}


/**
 * @brief 関数コールスタックの先頭を取得し、スタックから削除する
 */
function_call_stack_data* function_stack_pop() {

    if ( function_stack_is_empty() ) {
        return NULL;
    }

    stack_count --;
    return &stack[stack_count];
}





