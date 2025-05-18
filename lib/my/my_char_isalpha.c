/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** check if the char is a letter
*/

int my_char_isalpha(char a)
{
    if ((a > 122 || a < 97) && (a > 90) || (a < 65))
        return (0);
    else
        return (1);
}
