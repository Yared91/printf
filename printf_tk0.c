#include "main.h"
/**
 * _printf - function that produces output
 * @format: string literal input
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
int chara_index = 0;
va_list valist;
if (format == NULL)
{
return (-1);
}
va_start(valist, format);
while (*format)
{
if (*format != '%')
{
write(1, format, 1);
chara_index++;
}
else
{
format++;
if (*format == '\0')
break;
if (*format == 'c')
{
char a = va_arg(valist, int);
write(1, &a, 1);
chara_index++;
}
else if (*format == 's')
{
char *str = va_arg(valist, char*)
; int str_len = 0;
while (str[str_len] != '\0')
str_len++;
write(1, str, str_len);
chara_index += str_len;
}
else if (*format == '%')
{
write(1, format, 1);
chara_index++;
}
format++;
}
}
va_end(valist);
return (chara_index);
}
