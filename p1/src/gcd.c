const int a = 128, b = 96;
void main()
{
    int i, j, temp;
    
    i = a; 
    j = b;

    while (i%j)
    {
	temp = i;
	i = j;
	j = temp%i;
    }
    
    printf("The gcd of %d and %d is %d\n", a, b, j);
}


