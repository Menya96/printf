#include "main.h"

int _printf(const char *format, ...)
{
	char buffer [BUFFER_SIZE]; //declare  a buffer of size 1024
	int index = 0; //initialize the buffer index to 0

	int char_printed = 0; //Initialize characters printed variable
	va_list list_of_args;

	if(format == NULL)
		return -1;

	va_start(list_of_args, format);

	while (*format)
	{
		if (*format != '%') //if the format isn't a % sign
		{
			write(1, format, 1); //write char to std output
			char_printed++;
		}

		else  //if char is % sign
		{
			format++; //skip the % sign and check the next character
			if (*format == '\0')
				break;

			if (*format == '%') //checks for %%
			{
				write(1, format,1);
				char_printed++;
			}
			else if (*format == 'c') //Handles 'c' (chaacter)
			{
				char c = va_arg(list_of_args, int);
				write(1, &c, 1);
				char_printed++;
			}

			else if (*format == 'd') //Prints an integer in decimal
			{
				int num  = va_arg(list_of_args, int); //gets next agument as an int
				char num_str[20]; //declare a string to store the number
				sprintf(num_str, "%d", num); //convert num to string
				int len = 0;
				
			
				if (index + len < BUFFER_SIZE )
				{
					strcpy(buffer, num_str); //copy string into buffer
					index += len;
					write(1, buffer, index);
					_printf(buffer);
					
				}
				else //if buffer full
				{
					write(1, buffer, index);
					index = 0;
					strcpy(buffer, num_str);
					index = len;
				}
				
			}
			else if (*format == 'i') // print integer in hexadecimal
			{
				int num = va_arg(list_of_args, int);
				char num_str[20];
				sprintf(num_str, "%i", num);
				int len = strlen(num_str);

				if (index + len < BUFFER_SIZE)
				{
					strcpy(buffer, num_str);
					index += len;
					write(1, buffer, len);
				}
				else
				{
					write(1, buffer, index);
					index = 0;
					strcpy(buffer, num_str);
					index = len;
				}
			}

			else if (*format == 's')
			{
				char *str = va_arg(list_of_args, char*);
				int str_len = 0;

				//calculate length of the string
				while (str[str_len] != '\0') 
				str_len++;

				write(1, str, str_len);
				char_printed += str_len;
			}
			
		}
		format++;
	}

	va_end(list_of_args); // closes arg list
	return char_printed;
	
}


int main(){
	_printf("tonny\n");
	_printf("%c\n", 'b');
	_printf("%s\n", "string");
	_printf("%d\n", 5000);
	_printf("%i hex of 45\n", 5);
	_printf("%%\n");
	
	

	return 0;

}