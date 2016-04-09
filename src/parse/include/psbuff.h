#ifndef CYPARSE_BUFF_H
#define CYPARSE_BUFF_H

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------*/
/**
 * @brief ソース解析用バッファのクリアを行う             *
 */
/* ------------------------------------------------------*/
void psbuff_clear();


/* ------------------------------------------------------*/
/**
 * @brief ソース解析用バッファに字句を追加する           * 
 *                                                       *
 * @param line   カレントソースライン                    *
 * @param strlex 字句文字列                              * 
 */
/* ------------------------------------------------------*/
void psbuff_append(int line, const char* strlex);

/* ------------------------------------------------------*/
/**
 * @brief ソース解析用バッファを取得する                 * 
 *                                                       *
 * @return ソース解析用バッファ蓄積文字列                *
 */
/* ------------------------------------------------------*/
const char* psbuff_get_string();

/* ------------------------------------------------------*/
/**
 * @brief ソース解析用バッファの読み出し位置を取得する   * 
 *                                                       *
 * @return ソース解析用バッファ蓄積文字列                *
 */
/* ------------------------------------------------------*/
struct linescope
{
    int begin;
    int end;
};
const struct linescope* psbuff_get_linescope();



char* psbuff_realloc(const char* ptr1, const char* ptr2);

#ifdef DEBUG
    #define dprintf(prefix, format, ...) \
                printf(" + %-30s: " format, prefix, __VA_ARGS__)
#else
    #define dprintf(prefix, format, ...)
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
