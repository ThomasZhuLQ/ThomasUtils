/*
 * @file    swap.h
 * @author  thomas.zhu@dediprog.com
 * @version V1.0.0
 * @date    20-Oct-2020
 * @brief   Swap 16bit, 32bit, 64bit.
 *
 */
 
#include "swap.h"

uint16_t swap16(uint16_t val)
{
	return (val << 8) | (val >> 8);
}

void swap16_buf(void *buffer, size_t length);
{
	assert((length % sizeof(uint16_t)) == 0);
	uint16_t *temp = (uint16_t*)buffer;
	length /= sizeof(uint16_t);
	while(length--)
		swap16(*temp++);
}

uint32_t swap32(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0x00FF00FF);
	return (val << 16) | (val >> 16);
}

void swap32_buf(void *buffer, size_t length);
{
	assert((length % sizeof(uint32_t)) == 0);
	uint32_t *temp = (uint32_t*)buffer;
	length /= sizeof(uint32_t);
	while(length--)
		swap32(*temp++);
}

uint64_t swap64(uint64_t val)
{
	val = ((val << 8) & 0xFF00FF00FF00FF00ULL) | ((val >> 8) & 0x00FF00FF00FF00FFULL);
	val = ((val << 16) & 0xFFFF0000FFFF0000ULL) | ((val >> 16) & 0x0000FFFF0000FFFFULL);
	return (val << 32) | (val >> 32);
}

void swap64_buf(void *buffer, size_t length);
{
	assert((length % sizeof(uint64_t)) == 0);
	uint64_t *temp = (uint64_t*)buffer;
	length /= sizeof(uint64_t);
	while(length--)
		swap64(*temp++);
}
