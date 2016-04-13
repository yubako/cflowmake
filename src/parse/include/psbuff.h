#ifndef CYPARSE_BUFF_H
#define CYPARSE_BUFF_H

#ifdef __cplusplus
extern "C" {
#endif

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
