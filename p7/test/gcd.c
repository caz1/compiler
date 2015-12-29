extern int input;
extern int output;

extern void get();
extern void print();

void main()
{
    int i, j, temp, a, b;
    
    get();
    a = input;
    get();
    b = input;
    //scanf("%d%d", &a, &b);  

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
    
    output = j;
    print();
    //printf("The gcd of %d and %d is %d\n", a, b, j);
}


