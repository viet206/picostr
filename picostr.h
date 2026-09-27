#ifndef ___Pico_String___
#define ___Pico_String___

#define PICOSTR_VER "0.0.1"

#define fn_copy buf_copy

#define PTR_SIZE (int)sizeof(void*)
#define INT_SIZE (int)sizeof(int)
#define STR_SIZE (int)sizeof(pico_str_t)

typedef struct {
	char* str;
	int len;
	int pad;
}pico_str_t;

typedef pico_str_t* str_t;
typedef char* raw_t;
typedef unsigned long long usize;
typedef unsigned short uint2;

#define str_lit(s,len) &(pico_str_t){s,len}

void buf_copy(raw_t dst,raw_t src,int size);
void buf_zero(raw_t buf,int size);

str_t str_new(raw_t buf,char* cstr,int len);
str_t view_new(raw_t buf,char* cstr,int len);
int str_cmpz(str_t dst,str_t src,int len);
void str_upper(str_t s);
void str_lower(str_t s);

#define str_open(obj) (obj)->str

#endif
