char  my_tolower(char c)
{
	if (c >= 'A' && c <= 'Z') {
		c = 'a' + (c - 'A');
	}	
	return c;
}
