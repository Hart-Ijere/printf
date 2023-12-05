#include <stdio.h>
#include <stdarg.h>
#include "main"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // Variable to keep track of characters printed

    while (*format) {
        if (*format == '%') {
            // Handle format specifier
            switch (*(++format)) {
                case 'd':
                    // Handle integer
                    count += fprintf(stdout, "%d", va_arg(args, int));
                    break;
                case 's':
                    // Handle string
                    count += fprintf(stdout, "%s", va_arg(args, char*));
                    break;
                // Add more cases for other specifiers

                default:
                    // Handle unknown specifier or %
                    count += fputc('%', stdout);
                    break;
            }
        } else {
            // Regular character
            count += fputc(*format, stdout);
        }

        format++;
    }

    va_end(args);
    return count;
}
}
