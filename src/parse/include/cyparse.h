#ifndef CYPARSE_H
#define CYPARSE_H

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------*/
/**
 * @brief Cソース解析                                    *
 *                                                       *
 * @param cSourceFile 解析するCソースファイル            *
 *                                                       *
 * @return  0  解析成功                                  *
 * @return -1  解析失敗                                  *
 * @return -2  ソース読み出しエラー                      *
 */
/* ------------------------------------------------------*/
int cflowSrcParse(const char* cSourceFile);


/* ------------------------------------------------------*/
/**
 * @brief Cソース解析(標準入力)                          *
 *                                                       *
 * @return  0  解析成功                                  *
 * @return -1  解析失敗                                  *
 * @return -2  ソース読み出しエラー                      *
 */
/* ------------------------------------------------------*/
int cflowStdinParse();

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
