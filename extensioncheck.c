// return 1 si .ber et 0 si mauvaise extension

int check(const char *s)
{
	int i;
	while(s[i] != '.')
		i++;
	i = i + 1;
	if ((s[i] == 'b') && (s[i+1] == 'e') && (s[i+2] == 'r'))
		return(1);
	return (0);
}