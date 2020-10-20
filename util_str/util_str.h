/*
 * @file    util_str.h
 * @author  thomas.zhu@dediprog.com
 * @version V1.0.0
 * @date    20-Oct-2020
 * @brief   Header for string operation.
 *
 */

#ifndef _UTIL_STR_H_
#define _UTIL_STR_H_

/*****************************************************************************/
/*     Compare two string with no case sensitive.                            */
/*                                                                           */
/* Parameter list:                                                           */
/*   s1(in):                                                                 */
/*      CString buffer 1.                                                    */
/*   s2(in):                                                                 */
/*      CString buffer 2.                                                    */
/* Return:                                                                   */
/*   0 same. Others not same.                                                */
/*****************************************************************************/
int32_t str_n_cmp(const char * s1, const char * s2);

/*****************************************************************************/
/*     Truncate path from CString.                                           */
/*                                                                           */
/* Parameter list:                                                           */
/*   _cstring(in):                                                           */
/*      CString buffer.                                                      */
/*   path(out):                                                              */
/*      String buffer of path.                                               */
/*****************************************************************************/
void get_path(const char *_cstring, char *path);

/*****************************************************************************/
/*     Find file name in CString.                                            */
/*                                                                           */
/* Parameter list:                                                           */
/*   _cstring(in):                                                           */
/*      CString buffer.                                                      */
/* Return:                                                                   */
/*   Pointer of the file name cstring.                                       */
/*****************************************************************************/
const char* get_file_name( const char *_cstring);


/*****************************************************************************/
/*     Char to integer.                                                      */
/*****************************************************************************/
#define c2i(c)		((c) - '0')
/*****************************************************************************/
/*     Integer to char.                                                      */
/*****************************************************************************/
#define i2c(i)		((i) + '0')
/*****************************************************************************/
/*     Char to hex.                                                          */
/*****************************************************************************/
#define c2h(c)		(IS_NUM(c)?((c) - '0'):(IS_AF(c)?((c) - 'A' + 10):((c) - 'a' + 10)))
/*****************************************************************************/
/*     Hex to char.                                                          */
/*****************************************************************************/
#define h2c(h)		(((h) < 10)?((h) + '0'):(h - 10 + 'A'))


/*****************************************************************************/
/*     CString convert to 32bit integer.                                     */
/*                                                                           */
/* Parameter list:                                                           */
/*   _cstring(in):                                                           */
/*      CString buffer.                                                      */
/* Return:                                                                   */
/*   Integer converted.                                                      */
/*****************************************************************************/
int s2i(const char* _cstring);

/*****************************************************************************/
/*     CString convert to 64bit integer.                                     */
/*                                                                           */
/* Parameter list:                                                           */
/*   _cstring(in):                                                           */
/*      CString buffer.                                                      */
/* Return:                                                                   */
/*   Integer converted.                                                      */
/*****************************************************************************/
int64_t s2ll(const char *_cstring);

/*****************************************************************************/
/*     CString convert to 32bit hex.                                         */
/*                                                                           */
/* Parameter list:                                                           */
/*   _cstring(in):                                                           */
/*      CString buffer.                                                      */
/* Return:                                                                   */
/*   Hex converted.                                                          */
/*****************************************************************************/
uint32_t s2h(const char* _cstring);

/*****************************************************************************/
/*     32bit hex convert to string.                                          */
/*                                                                           */
/* Parameter list:                                                           */
/*   hex(in):                                                                */
/*      32bit hex data.                                                      */
/*   _string(out):                                                           */
/*      String buffer to save the converted buffer.                          */
/* Return:                                                                   */
/*   String buffer length.                                                   */
/*****************************************************************************/
uint32_t h2s(uint32_t hex, char* _string);

/*****************************************************************************/
/*     32bit integer convert to string.                                      */
/*                                                                           */
/* Parameter list:                                                           */
/*   integer(in):                                                            */
/*      32bit dec data.                                                      */
/*   _string(out):                                                           */
/*      String buffer to save the converted buffer.                          */
/* Return:                                                                   */
/*   String buffer length.                                                   */
/*****************************************************************************/
int i2s(int integer, char *_string);

/*****************************************************************************/
/*     Convert 8bit hex array to string.                                     */
/*                                                                           */
/* Parameter list:                                                           */
/*   buffer(in):                                                             */
/*      Pointer of data buffer.                                              */
/*   length(in):                                                             */
/*      Number of bytes of data buffer.                                      */
/*   _string(out):                                                           */
/*      String buffer to save the converted buffer.                          */
/*****************************************************************************/
void u8_array2s(const uint8_t *buffer, size_t length, char *_string);

/*****************************************************************************/
/*     Convert 8bit hex array to string.                                     */
/*                                                                           */
/* Parameter list:                                                           */
/*   _cstring(in):                                                           */
/*      CString buffer to convert.                                           */
/*   h_array(out):                                                           */
/*      Pointer of hex data buffer.                                          */
/*   length(in):                                                             */
/*      Number of bytes of hex buffer.                                       */
/* Return:                                                                   */
/*   Number of hex buffer converted.                                         */
/*****************************************************************************/
size_t s2u8_array(const char* _cstring, uint8_t *h_array, size_t length);

size_t MEM_GetNoBlankLength(const uint8_t *buffer, size_t length, size_t unit_length);

#endif
