/*
 * @file    util_str.h
 * @author  thomas.zhu@dediprog.com
 * @version V1.0.0
 * @date    20-Oct-2020
 * @brief   String operation.
 *
 */

#include "util_str.h"
#include <string.h>

#define UPCASE(c)				(IS_az(c)?((c) - 'a' + 'A'):(c))
#define IS_AF(b)				( ((b)>='A') && ((b)<='F') )
#define IS_af(b)				( ((b)>='a') && ((b)<='f') )
#define IS_NUM(b)				( ((b)>='0') && ((b)<='9') )
#define IS_HEX(b)				( IS_AF(b) || IS_af(b) || IS_NUM(b) )
#define IS_ASCII(b)				( ((b)>=0x20) && ((b)<=0x7F) )
#define IS_AZ(b)				( ((b)>='A') && ((b)<='Z') )
#define IS_az(b)				( ((b)>='a') && ((b)<='z') )
#define IS_CHAR(b)				( IS_AZ(b) || IS_az(b) )


int32_t str_n_cmp(const char * s1, const char * s2)
{
	while(*s1 && *s2)
	{
		if(UPCASE(*s1) != UPCASE(*s2))
			return 1;
		s1++;
		s2++;
	}
	if(UPCASE(*s1) != UPCASE(*s2))
		return 1;
	return 0;
}

void get_path(const char *_cstring, char *path)
{
	const char *p = _cstring + strlen(_cstring) - 1;
	while(*p != '/')
		p--;
	memcpy(path,_cstring,p - _cstring);
	path[p - _cstring] = '\0';
}

const char* get_file_name( const char *_cstring )
{
	const char *p = _cstring + strlen(_cstring) - 1;
	while(*p != '/')
		p--;
	return p + 1;
}

static size_t _lr_bit(char ch_value)
{
	switch(ch_value)
	{
	case 'k':
	case 'K':
		return 10;
	case 'm':
	case 'M':
		return 20;
	case 'g':
	case 'G':
		return 30;
	}
	return 0;
}

int s2i(const char *_cstring)
{
	bool bNegative = false;
	int result = 0;
	if(*_cstring == '\0') return result;
	if(*_cstring == '-')
	{
		bNegative = true;
		_cstring ++;
	}
	while(IS_NUM(*_cstring))
	{
		result *= 10;
		result += c2i(*_cstring);
		_cstring++;
	}
	result <<= _lr_bit(*_cstring);
	if(bNegative == true)
		result *= -1;
	return result;
}

int64_t s2ll(const char *_cstring)
{
	bool bNegative = false;
	int64_t result = 0ll;
	if(*_cstring == '\0') return result;
	if(*_cstring == '-')
	{
		bNegative = true;
		_cstring ++;
	}
	while(IS_NUM(*_cstring))
	{
		result *= 10;
		result += c2i(*_cstring);
		_cstring++;
	}
	result <<= _lr_bit(*_cstring);
	if(bNegative == true)
		result *= -1;
	return result;
}

uint32_t s2h(const char *_cstring)
{
	uint32_t result = 0;
	while(IS_HEX(*_cstring))
	{
		result <<= 4;
		result += c2h(*_cstring);
		_cstring++;
	}
	return result;
}

uint32_t h2s(uint32_t hex, char* string)
{
	char *pstr = string;
	int32_t digit = 7;
	
	for( ; digit >= 0; digit--)
		if(( hex >> (digit * 4))&0xF)
			break;
	if(digit < 0) *pstr++ = 0;
	for( ; digit >= 0; digit--)
		*pstr++ = h2c(( hex >> (digit * 4))&0xF);
	*pstr = '\0';
	
	return (uint32_t)(pstr - string);
}

int i2s(int integer, char *_string)
{
	if(integer == 0)
	{
		*_string = '0';
		return 1;
	}
	else
	{
		int s_sz = 0;
		int start_dig = 1000000000;
		while((integer / start_dig) == 0)
			start_dig /= 10;
		while(start_dig)
		{
			*_string++ = i2c(integer / start_dig);
			integer %= start_dig;
			start_dig /= 10;
			s_sz++;
		}
		return s_sz;
	}
}

void u8_array2s(const uint8_t *buf, size_t length, char *_string)
{
	uint8_t temp;
	while(length--)
	{
		temp = (*buf)>>4;
		*_string++ = h2c(temp);
		temp = (*buf)&0xF;
		*_string++ = h2c(temp);
		buf++;
	}
	*_string = '\0';
}

size_t s2u8_array(const char* _cstring, uint8_t *h_array, size_t length)
{
	size_t n_u8 = 0;
	if( strlen(_cstring) % 2 ) return 0;
	while(IS_HEX(*_cstring) && length)
	{
		*h_array += c2h(*_cstring);
		*h_array <<= 4;
		_cstring ++;
		*h_array += c2h(*_cstring);
		_cstring ++;
		h_array ++;
		length--;
		n_u8++;
	}
	return n_u8;
}

size_t MEM_GetNoBlankLength(const uint8_t *buffer, size_t length, size_t unit_length)
{
	uint8_t *zero_buf = dp_malloc(unit_length);
	memset(zero_buf,0,unit_length);
	//buffer += (length - unit_length);
	while(length)
	{
		if(memcmp(buffer + length - unit_length,zero_buf,unit_length) != 0)
			break;
		length -= unit_length;
	}
	dp_free(zero_buf);
	return length;
}
