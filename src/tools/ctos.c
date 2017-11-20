short   ctos(char tab[2])
{
    short   value;

    value = tab[0] << 2 | tab[1];
    return (value);
}
