
int   ctoi(char tab[4])
{
    int   value;

    value = tab[0] << 6 | tab[1] << 4 | tab[2] << 2 | tab[3];
    return (value);
}
