char *reverse(char a[])
{
    static char r[1002];

    int l = strlen(a);
    for (int i = 0; i < l; i++)
    {
        if (r[l - 1] == '\n')
        {
            r[l - 1] = '\0';
        }
        r[i] = a[l - 1 - i];
    }
    return (char *)r;
}