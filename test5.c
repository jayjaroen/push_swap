#include <stdio.h>

int char_to_digit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    return -1; // Invalid character
}

int ft_atoi_base(const char *str, int str_base) {
    if (str_base < 2 || str_base > 16) {
        return 0; // Invalid base, return 0
    }

    int result = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str != '\0') {
        int digit = char_to_digit(*str);
        if (digit == -1 || digit >= str_base) {
            return 0; // Invalid character for the base, return 0
        }
        result = result * str_base + digit;
        str++;
    }

    return result * sign;
}

int main() {
    const char *number1 = "10"; // binary number "10"
    const char *number2 = "1A"; // hexadecimal number "1A"
    const char *number3 = "-101"; // binary number "-101"

    int base = 2; // binary base

    int result1 = ft_atoi_base(number1, base);
    printf("Number %s in base %d is %d\n", number1, base, result1);

    base = 16; // hexadecimal base
    int result2 = ft_atoi_base(number2, base);
    printf("Number %s in base %d is %d\n", number2, base, result2);

    int result3 = ft_atoi_base(number3, base);
    printf("Number %s in base %d is %d\n", number3, base, result3);

    return 0;
}
// char to_lower(char c)
// {
//     if (c >= 'A' && c <= 'Z')
//         return (c + ('a' - 'A'));
//     return (c);
// }

// int get_digit(char c, int digits_in_base)
// {
//     int max_digit;
//     if (digits_in_base <= 10)
//         max_digit = digits_in_base + '0';
//     else
//         max_digit = digits_in_base - 10 + 'a';

//     if (c >= '0' && c <= '9' && c <= max_digit)
//         return (c - '0');
//     else if (c >= 'a' && c <= 'f' && c <= max_digit)
//         return (10 + c - 'a');
//     else
//         return (-1);
// }

// int ft_atoi_base(const char *str, int str_base)
// {
//     int result = 0;
//     int sign = 1;
//     int digit;

//     if (*str == '-')
//     {
//         sign = -1;
//         ++str;
//     }

//     while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
//     {
//         result = result * str_base;
//         result = result + (digit * sign);
//         ++str;
//     }
//     return (result);
// }

// int main()
// {
//     const char *number1 = "10"; // binary number "10"
//     const char *number2 = "1A"; // hexadecimal number "1A"
//     const char *number3 = "-101"; // binary number "-101"

//     int base = 2; // binary base

//     int result1 = ft_atoi_base(number1, base);
//     printf("Number %s in base %d is %d\n", number1, base, result1);

//     base = 16; // hexadecimal base
//     int result2 = ft_atoi_base(number2, base);
//     printf("Number %s in base %d is %d\n", number2, base, result2);

//     int result3 = ft_atoi_base(number3, base);
//     printf("Number %s in base %d is %d\n", number3, base, result3);

//     return 0;
// }