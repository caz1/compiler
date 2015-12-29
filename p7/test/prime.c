extern int output;
extern void print();
const  int range = 30;
void main()
{
    int i, j, temp;
    const int ccc[10] = {1, 2, 3};	
    int isPrime[30];
    i = 0;
    while (i != range || j == i)
    {
	isPrime[i] = 1;
	i = i + 1;
    }
    {
    	int i = 2;
    	output = i;
    	print();
    }
    i = 2;
    isPrime[0] = 0;
    isPrime[1] = 0;

    while (! i == range)
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
	if (isPrime[i] != 0)
	{
		output = i;
		print();
	}
	if (i == 11)
		break;	// printf("%d\t", i);
	i = i + 1;
    }
}

