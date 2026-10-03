#include "picostr.h"

str_t str_new(raw_t buf,char* cstr,len_t len) {
	str_t restrict s = (str_t) buf;
	s->len = len;
	s->str = (char*) s + STR_SIZE;
	fn_copy(s->str,cstr,len);
	return s;
}

str_t view_new(raw_t buf,char* cstr,len_t len) {
	str_t restrict s = (str_t) buf;
	s->len = len;
	s->str = cstr;
	return s;
}

int str_cmpz(str_t dst,str_t src,len_t len) {
	char* restrict pdst = dst->str;
	char* restrict psrc = src->str;

	for (int i = 0 ; i <= len ; ++i ) {
		if ( pdst[i] != psrc[i] ) {
			return 0;
		}
	}

	return 1;
}

void str_upper(str_t s) {
	char* p = s->str;

	while ( *p != '\0' ) {
		if ( *p >= 'a' && *p <= 'z' ) {
			if ( *p == ' ' ) ++p;
			*p -= 32;
		}
		++p;
	}
}

void str_lower(str_t s) {
	char* p = s->str;

	while ( *p != '\0' ) {
		if ( *p >= 'A' && *p <= 'Z' ) {
			if ( *p == ' ' ) ++p;
			*p += 32;
		}
		++p;
	}
}

int str_2int(str_t s) {
	int reslut = 0;
	int i = 0;
	int num_signed = 0;
	char* num = s->str;
	
	if ( num[i] == '-' ) {
		num_signed = 1;
		++i;
	}else if ( num[i] == '+' ) ++i;

	for ( ; i < s->len ; ++i ) {
		if ( num[i] >= '0' && num[i] <= '9' ) {
			reslut = reslut * 10 + ( num[i] - '0' );
		}
	}

	if ( num_signed == 1 ) {
		reslut = -(reslut);
	}
	return reslut;
}

str_t str_sub(raw_t buf,str_t s,int form,int to) {
	str_t str = (str_t) buf;
	str->len = to - form;
	str->str = (char*) buf + STR_SIZE;
	char* p = str->str;

	fn_copy(p,s->str + form,str->len);
	p[str->len] = '\0';
	return str;
}
