//引数リストから1byteずつcpにコピー
void *vmemcpy(void *cp, va_list org, size_t size) 
{
	va_list dat;
	unsigned char byte;

	//org を dat コピー, orgへの副作用を無くす
	va_copy(dat, org);

	while(size--) {
		byte = va_arg(dat, unsigned char);
		cp[size] = byte;
	}

	return cp;
}

int finput(FILE *source, const char *format, ...)
{
    va_list arg;
    char buff[1024];
    int result;

    fgets(buff, sizeof(buff) - 1, source);

    va_start(arg, format);
    result = vsscanf(buff, format, arg);
    va_end(arg);

	return result;
}
