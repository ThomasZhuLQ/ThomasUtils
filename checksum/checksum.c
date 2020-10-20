/*
 * @file    checksum.c
 * @author  thomas.zhu@dediprog.com
 * @version V1.0.0
 * @date    20-Oct-2020
 * @brief   Calculate checksum.
 *
 */

 #include "checksum.h"

uint32_t checksum_u8(const uint8_t*buffer, size_t length, uint32_t seed)
{
	while(length--)
	{
		seed += *buffer;
		buffer++;
	}
	return seed;
}

uint32_t checksum_u32(const uint32_t* buffer, size_t length, uint32_t seed)
{
	assert((length % sizeof(uint32_t)) == 0);
	length /= sizeof(uint32_t);
	while(length--)
	{
		seed += *buffer;
		buffer++;
	}
	return seed;
}