#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...)
{
	va_list args;
	int i=0;
	if (format == NULL)
		return -1;
	va_start(args,format);
	while(*format)
	{
		if( *format == '%')
		{
			format ++;
			switch (*format)
			{
			case 'c':
			{
			char c = va_arg(args, int);
			write(1,&c,1);
			i++;
			break;
			}
			case 's':
			{
			char* str = va_arg(args, char*);
			int l=0;
			while(str[l] != '\0'){
			l++;
			}
			write(1,str,l);
			i++;
			break;
			}
			case '%':
			write(1,format,1);
			i++;
			break;
			case '\0':
			break;
			default:
			format --;
			write(1,format,1);
			i++;
			break;
			}
		}
		else
		{
		write(1,format,1);
		i ++;
		}
	format ++;
	}
	va_end(args);
	return i;
}		
