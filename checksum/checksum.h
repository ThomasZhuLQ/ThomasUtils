/*
 * @file    checksum.h
 * @author  thomas.zhu@dediprog.com
 * @version V1.0.0
 * @date    20-Oct-2020
 * @brief   Header for calculate checksum.
 *
 */
 
#ifndef _CHECKSUM_H_
#define _CHECKSUM_H_

/*****************************************************************************/
/*     Calculate a 8bit checksum.                                            */
/*                                                                           */
/* Parameter list:                                                           */
/*   buffer(in):                                                             */
/*      Buffer pointer.                                                      */
/*   length(in):                                                             */
/*      Number of bytes of the buffer.                                       */
/*   seed(in):                                                               */
/*      Initialized value of the checksum.                                   */
/* Return:                                                                   */
/*   The checksum value.                                                     */
/*****************************************************************************/
uint32_t checksum_u8(const uint8_t* buffer, size_t length, uint32_t seed);

/*****************************************************************************/
/*     Calculate a 32bit checksum.                                           */
/*                                                                           */
/* Parameter list:                                                           */
/*   buffer(in):                                                             */
/*      Buffer pointer.                                                      */
/*   length(in):                                                             */
/*      Number of bytes of the buffer.                                       */
/*   seed(in):                                                               */
/*      Initialized value of the checksum.                                   */
/* Return:                                                                   */
/*   The checksum value.                                                     */
/*****************************************************************************/
uint32_t checksum_u32(const uint32_t* buffer, size_t length, uint32_t seed);

#endif
