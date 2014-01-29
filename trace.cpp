/* 
 *
 *   AmesianX in POWERHACKER.NET
 *
 */


#include "./trace.h"
#include <stdio.h>

//#define __DEBUG__

void PSPDebugTrace (const char *format, ...) {
	va_list	opt;
	char    buff[2048];
	int     bufsz;
	FILE    *fd;  

	va_start(opt, format);
	bufsz = vsnprintf( buff, (size_t) sizeof(buff), format, opt);
	va_end(opt);

	fd = fopen("ms0:/anisePSP/anisePSP_log.txt", "a+");

	if(fd == NULL)
	{
		return;
	}

	fwrite((const void *)buff, bufsz, 1, fd);

	fclose(fd);
}
