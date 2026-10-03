#include <stdlib.h>
#include <stdio.h>
#include "picostr.h"

int main() {
	char buf[64] = {0};
	static char buf3[64] = {0};

	str_t str1 = str_new(buf,"Hello Pico String",18);

	puts(str1->str);

	char* buf2 = malloc(64);

	str_t str2 = str_new(buf2,"My Heap Memory",15);

	puts(str2->str);

	int d = str_2int(str_lit("-A3C5B6",7));

	str_t s3 = str_sub(buf3,str2,2,7);

	printf(s3->str);

	printf("%d",d);

	free(buf2);
}
