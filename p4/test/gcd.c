
void main()
{
    int i, j, temp, a, b;

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

    if (a > 1)
		if (a > 2)
			a = 3;
		else a = 1;
	
    while (i%j != 0)
    {
		temp = i;
		i = j;
		j = temp%i;
    }
	int c;
	b();
// prinf("the gcd of %d and %d is %d \n", i, j, temp);
}


