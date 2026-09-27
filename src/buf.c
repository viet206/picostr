#include "picostr.h"

void buf_copy(raw_t dst, raw_t src,len_t size) {
        while (size >= (int)sizeof(usize)) {
                *((usize*)dst) = *((usize*)src);
                dst += sizeof(usize);
                src += sizeof(usize);
                size -= sizeof(usize);
        }

        while (size >= 2) {
                *((uint2*)dst) = *((uint2*)src);
                dst += 2;
                src += 2;
                size -= 2;
        }

        if (size > 0) *dst++ = *src++;
}

void buf_zero(raw_t buf,len_t size) {
	while ( size >= (int)sizeof(usize)) {
		*((usize*)buf) = 0;
		buf += sizeof(usize);
		size -= sizeof(usize);
	}

	while ( size >= 2 ) {
		*((uint2*)buf) = 0;
		buf += sizeof(usize);
		size -= 2;
	}

	if ( size > 0 ) *buf = 0;
}
