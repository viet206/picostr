#ifndef ___Pico_String___
#define ___Pico_String___

#include "config.h"

#define PICOSTR_VER "0.0.1"

#define fn_copy buf_copy

#define PTR_SIZE (int)sizeof(void*)
#define INT_SIZE (int)sizeof(int)
#define STR_SIZE (int)sizeof(pico_str_t)

typedef struct {
	char* str;
	len_t len;
	int pad;
}pico_str_t;

typedef pico_str_t* str_t;

#define str_lit(s,len) &(pico_str_t){s,len}

void buf_copy(raw_t dst,raw_t src,len_t size);
void buf_zero(raw_t buf,len_t size);

str_t str_new(raw_t buf,char* cstr,len_t len);
str_t view_new(raw_t buf,char* cstr,len_t len);
int str_cmpz(str_t dst,str_t src,len_t len);
void str_upper(str_t s);
void str_lower(str_t s);
int str_2int(str_t s);

#endif
