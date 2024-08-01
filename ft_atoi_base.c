#include <unistd.h>
#include <stdio.h>

// Helper function to get the length of the string
int ft_strlen(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Helper function to check if a character is in a string and return its index
int ft_strchr_index(char *str, char c) {
    int index = 0;
    while (str[index] != '\0') {
        if (str[index] == c) {
            return index;
        }
        index++;
    }
    return -1;
}

// Helper function to validate the base
int ft_valid_base(char *base) {
    int len = ft_strlen(base);
    if (len <= 1) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        char c = base[i];
        if (c == '+' || c == '-' || ft_strchr_index(base + i + 1, c) != -1) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a string in a given base to an integer
int ft_atoi_base(char *str, char *base) {
    if (!ft_valid_base(base)) {
        return 0;
    }

    int base_len = ft_strlen(base);
    int result = 0;
    int sign = 1;
    int index = 0;

    // Skip leading whitespace
    while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13)) {
        index++;
    }

    // Handle optional sign
    if (str[index] == '-' || str[index] == '+') {
        if (str[index] == '-') {
            sign = -1;
        }
        index++;
    }

    // Convert the number
    int digit_value;
    while (str[index] != '\0') {
        digit_value = ft_strchr_index(base, str[index]);
        if (digit_value == 0) {
            break;
        }
        result = result * base_len + digit_value;
        index++;
    }

    return result * sign;
}

int main() {
    // Test cases
    // printf("Testing with decimal base (0123456789):\n");
    printf("String '42' in decimal: %d\n", ft_atoi_base("42", "0123456789"));
    // printf("String '-42' in decimal: %d\n", ft_atoi_base("-42", "0123456789"));
    // printf("String '0' in decimal: %d\n", ft_atoi_base("0", "0123456789"));

    // printf("Testing with binary base (01):\n");
    // printf("String '101010' in binary: %d\n", ft_atoi_base("101010", "01"));
    // printf("String '-101010' in binary: %d\n", ft_atoi_base("-101010", "01"));
    // printf("String '0' in binary: %d\n", ft_atoi_base("0", "01"));

    // printf("Testing with hexadecimal base (0123456789ABCDEF):\n");
    // printf("String '2A' in hexadecimal: %d\n", ft_atoi_base("2A", "0123456789ABCDEF"));
    // printf("String '-2A' in hexadecimal: %d\n", ft_atoi_base("-2A", "0123456789ABCDEF"));
    // printf("String '0' in hexadecimal: %d\n", ft_atoi_base("0", "0123456789ABCDEF"));

    // printf("Testing with custom base (poneyvif):\n");
    // printf("String 'one' in custom base: %d\n", ft_atoi_base("one", "poneyvif"));
    // printf("String '-one' in custom base: %d\n", ft_atoi_base("-one", "poneyvif"));
    // printf("String 'o' in custom base: %d\n", ft_atoi_base("o", "poneyvif"));

    // printf("Testing with invalid bases:\n");
    // printf("Empty base: %d\n", ft_atoi_base("42", ""));
    // printf("Base with one character (0): %d\n", ft_atoi_base("42", "0"));
    // printf("Base with duplicate characters (01234567890): %d\n", ft_atoi_base("42", "01234567890"));
    // printf("Base with + character (012+3456789): %d\n", ft_atoi_base("42", "012+3456789"));
    // printf("Base with - character (012-3456789): %d\n", ft_atoi_base("42", "012-3456789"));

    return 0;
}

