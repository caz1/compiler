const int range = 30;
void main()
{
    int i, j, temp;
    int isPrime[range];
   
    i = 0;
    while (i != range)
    {
	isPrime[i] = 1;
	i = i + 1;
    }

    i = 2;
    isPrime[0] = 0;
    isPrime[1] = 0;

    while (i != range)
    {
	j = 2 * i;
	while (j < range)
	{
	    isPrime[j] = 0;
	    j = j + i;
	}
	i = i + 1;
     }

    
    //printf("The prime numbers smaller than %d:\n", range);
    i = 0;
    while (i != range)
    {
	if (isPrime[i] != 0);
		// printf("%d\t", i);
	i = i + 1;
    }
    //printf("\n");
}

