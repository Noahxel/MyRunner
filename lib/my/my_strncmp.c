/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** to long 4 mouli
*/

int my_strncmp_return(int cmts1, int cmts2)
{
    if (cmts1 < cmts2)
        return (-1);
    if (cmts1 > cmts2)
        return (1);
    if (cmts1 == cmts2)
        return (0);
}

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;
    int cmts1 = 0;
    int cmts2 = 0;

    for (;n = 0 || (s1[i] != '\0' && s2[i] != '\0'); i++, n--) {
        if (s1[i] == s2[i])
            cmts1 = cmts1;
        if (s1[i] < s2[i])
            cmts2 += (s2[i] - s1[i]);
        if (s1[i] > s2[i])
            cmts1 += (s1[i] - s2[i]);
    }
    my_strncmp_return(cmts1, cmts2);
}
