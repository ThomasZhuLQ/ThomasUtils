/*
 * @file    swap.h
 * @author  thomas.zhu@dediprog.com
 * @version V1.0.0
 * @date    20-Oct-2020
 * @brief   Header for swap 16bit, 32bit, 64bit.
 *
 */

#ifndef _SWAP_H_
#define _SWAP_H_

/*****************************************************************************/
/*     Swap a 16 bit data.                                                   */
/*                                                                           */
/* Parameter list:                                                           */
/*   val(in):                                                                */
/*      Data need to swap.                                                   */
/* Return:                                                                   */
/*   The swapped result.                                                     */
/*****************************************************************************/
uint16_t swap16(uint16_t val);

/*****************************************************************************/
/*     Swap the data buffer as 16bit.                                        */
/*                                                                           */
/* Parameter list:                                                           */
/*   buffer(in/out):                                                         */
/*      Data buffer need to swap.                                            */
/*   length(in):                                                             */
/*      Number of bytes of the data buffer.                                  */
/*****************************************************************************/
void swap16_buf(void *buffer, size_t length);

/*****************************************************************************/
/*     Swap a 32 bit data.                                                   */
/*                                                                           */
/* Parameter list:                                                           */
/*   val(in):                                                                */
/*      Data need to swap.                                                   */
/* Return:                                                                   */
/*   The swapped result.                                                     */
/*****************************************************************************/
uint32_t swap32(uint32_t val);

/*****************************************************************************/
/*     Swap the data buffer as 32bit.                                        */
/*                                                                           */
/* Parameter list:                                                           */
/*   buffer(in/out):                                                         */
/*      Data buffer need to swap.                                            */
/*   length(in):                                                             */
/*      Number of bytes of the data buffer.                                  */
/*****************************************************************************/
void swap32_buf(void *buffer, size_t length);

/*****************************************************************************/
/*     Swap a 64 bit data.                                                   */
/*                                                                           */
/* Parameter list:                                                           */
/*   val(in):                                                                */
/*      Data need to swap.                                                   */
/* Return:                                                                   */
/*   The swapped result.                                                     */
/*****************************************************************************/
uint64_t swap64(uint64_t val);

/*****************************************************************************/
/*     Swap the data buffer as 64bit.                                        */
/*                                                                           */
/* Parameter list:                                                           */
/*   buffer(in/out):                                                         */
/*      Data buffer need to swap.                                            */
/*   length(in):                                                             */
/*      Number of bytes of the data buffer.                                  */
/*****************************************************************************/
void swap64_buf(void *buffer, size_t length);

#endif