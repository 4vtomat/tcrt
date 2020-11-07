unsigned strlen(char* s)
{
	unsigned len = 0;
	while(*s) {
		s++;
		len++;
	}
	return len;
}
