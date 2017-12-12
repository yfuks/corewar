
int   ctoi(char tab[4])
{
    int   value;

    value = (tab[0] << 24 & 0xFF000000)
        | (tab[1] << 16 & 0xFF0000)
        | (tab[2] << 8 & 0xFF00)
        | (tab[3] & 0xFF);
    return (value);
}
