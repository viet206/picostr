#include "picostr.h"

#define arr_new(buf,name) \
	arr_t name = (arr_t) buf

/* assignment operator */
#define arr_aop(arr,idx,str) \
	arr[idx] = str
