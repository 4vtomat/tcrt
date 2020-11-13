#include "stdlib.h"

void itoa(int num, char* buf, int base)
{
	char* tmp = buf;
	char* all = "0123456789";
	int sign = 0;
	if(num < 0) {
		sign = 1;
		num = -num;
	} else if(num == 0) {
		buf[0] = '0';
		return;
	}

	while(num) {
		*(tmp++) = all[num % base];
		num /= base;
	}
	if(sign) *(tmp++) = '-';

	tmp--;
	while(buf < tmp) {
		char c = *buf;
		*buf = *tmp;
		*tmp = c;
		buf++;
		tmp--;
	}
}
