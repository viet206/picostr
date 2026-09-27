#include "picostr.h"

str_t str_new(raw_t buf,char* cstr,int len) {
	str_t restrict s = (str_t) buf;
	s->len = len;
	s->str = (char*) s + STR_SIZE;
	fn_copy(s->str,cstr,len);
	return s;
}

str_t view_new(raw_t buf,char* cstr,int len) {
	str_t restrict s = (str_t) buf;
	s->len = len;
	s->str = cstr;
	return s;
}

int str_cmpz(str_t dst,str_t src,int len) {
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
