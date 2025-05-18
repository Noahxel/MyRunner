/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** This script will return N or P depends on the value of the inputed number
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
        my_putchar('\n');
    } else {
        my_putchar('N');
        my_putchar('\n');
    }
    return (0);
}
