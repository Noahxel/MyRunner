/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** This code will concatenate two strings
*/

int my_strlen(char const *str);

char *my_strcat(char *dest , char const *src)
{
    int nbdest = my_strlen(dest);
    int cmt = 0;

    while (src[cmt] != '\0') {
        dest[nbdest] = src[cmt];
        cmt++;
        nbdest++;
    }
    dest[nbdest] = '\0';
    return (dest);
}
