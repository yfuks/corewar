short   ctos(char tab[2])
{
    short   value;

    value = (tab[0] << 8 & 0xFF00)
        | (tab[1] & 0xFF);
    return (value);
}
