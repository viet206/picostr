#include <stdlib.h>
#include <stdio.h>
#include "picostr.h"

int main() {
	char buf[64] = {0};

	str_t str1 = str_new(buf,"Hello Pico String",18);

	puts(str1->str);

	char* buf2 = malloc(64);

	str_t str2 = str_new(buf2,"My Heap Memory",15);

	puts(str2->str);
}
