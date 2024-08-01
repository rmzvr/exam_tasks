#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int ft_strchr(char *str, char c) {
    while (*str) {
        if (*str == c) {
            return 1;
        }
        str++;
    }
    return 0;
}

int ft_valid_base(char *base) {
    int len = ft_strlen(base);
    if (len <= 1) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
		char c = base[i];
        if (c == '+' || c == '-' || ft_strchr(base + i + 1, c)) {
            return 0;
        }
    }
    return 1;
}

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putnbr_base(int nbr, char *base) {
    if (!ft_valid_base(base)) {
        return;
    }

    unsigned int base_len = ft_strlen(base);
    unsigned int num;

    if (nbr < 0) {
        ft_putchar('-');
        num = -nbr;
    } else {
        num = nbr;
    }

    unsigned int temp_num = num;
    int num_len = 1;
    while (temp_num >= base_len) {
        temp_num /= base_len;
        num_len++;
    }

    char result[num_len];
    result[num_len] = '\0';
    int i = num_len - 1;
    while (num >= base_len) {
        result[i--] = base[num % base_len];
        num /= base_len;
    }
    result[i] = base[num];

    i = 0;
    while (result[i] != '\0') {
        ft_putchar(result[i]);
        i++;
    }
}

int main() {
    // printf("Testing with decimal base (0123456789):\n");
    // printf("42 in decimal: ");
    // ft_putnbr_base(42, "0123456789");
    // printf("\n-42 in decimal: ");
    // ft_putnbr_base(-42, "0123456789");
    // printf("\n0 in decimal: ");
    // ft_putnbr_base(0, "0123456789");
    // printf("\n");

    // printf("Testing with binary base (01):\n");
    // printf("42 in binary: ");
    // ft_putnbr_base(42, "01");
    // printf("\n-42 in binary: ");
    // ft_putnbr_base(-42, "01");
    // printf("\n0 in binary: ");
    // ft_putnbr_base(0, "01");
    // printf("\n");

    // printf("Testing with hexadecimal base (0123456789ABCDEF):\n");
    // printf("42 in hexadecimal: ");
    // ft_putnbr_base(42, "0123456789ABCDEF");
    // printf("\n-42 in hexadecimal: ");
    // ft_putnbr_base(-42, "0123456789ABCDEF");
    // printf("\n0 in hexadecimal: ");
    // ft_putnbr_base(0, "0123456789ABCDEF");
    // printf("\n");

    // printf("Testing with custom base (poneyvif):\n");
    // printf("42 in custom base: ");
    // ft_putnbr_base(42, "poneyvif");
    // printf("\n-42 in custom base: ");
    // ft_putnbr_base(-42, "poneyvif");
    // printf("\n0 in custom base: ");
    // ft_putnbr_base(0, "poneyvif");
    // printf("\n");

    // printf("Testing with invalid bases:\n");
    // printf("Empty base: ");
    // ft_putnbr_base(42, "");
    // printf("\nBase with one character (0): ");
    // ft_putnbr_base(42, "0");
    // printf("\nBase with duplicate characters (01234567890): ");
    // ft_putnbr_base(42, "01234567890");
    // printf("\nBase with + character (012+3456789): ");
    // ft_putnbr_base(42, "012+3456789");
    // printf("\nBase with - character (012-3456789): ");
    // ft_putnbr_base(42, "012-3456789");
    // printf("\n");

    return 0;
}

