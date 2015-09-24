
void main()
{
    int i, j, temp, a, b;
    printf("input two integers:");
    scanf("%d%d", &a, &b);  
    
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

    while (i%j)
    {
	temp = i;
	i = j;
	j = temp%i;
    }
    
    printf("The gcd of %d and %d is %d\n", a, b, j);
}


