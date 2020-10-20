/*
 * @file    crc.h
 * @author  thomas.zhu@dediprog.com
 * @version V1.0.0
 * @date    20-Oct-2020
 * @brief   Header for calculate crc.
 *
 */
 
#ifndef _CRC_H_
#define _CRC_H_

/*****************************************************************************/
/*     Calculate a 16bit CRC.                                                */
/*                                                                           */
/* Parameter list:                                                           */
/*   buffer(in):                                                             */
/*      Buffer pointer.                                                      */
/*   length(in):                                                             */
/*      Number of bytes of the buffer.                                       */
/*   seed(in):                                                               */
/*      Initialized value of the crc.                                        */
/* Return:                                                                   */
/*   The crc value.                                                          */
/*****************************************************************************/
uint16_t crc_u16(const void* buffer, size_t length, uint16_t seed);

#endif /* CRC16_H_ */
