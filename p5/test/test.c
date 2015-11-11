const int a = 	1 + (1 + 1), b = 2;

void main()
{
    int i, j, temp;

    if (a > b)
    {
	i = a; 
    	j = b;
    }
    else
    {
   	i = b;
	j = a;
    }

    while (i%j != 1-1)
    {
	temp = i;
	i = j;
	j = temp%i;
    }
}
