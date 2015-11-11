const int a = 1;
const int b = 2;
const int c=  1;

void main()
{
    int i, j, temp, a, b;
    //printf("input two integers:");
    //scanf("%d%d", &a, &b);  
    a = 2 *(1 +3);
	a = 2+(1*3);
	a = 2%(1*3);
	a = 3*(3 *4);	

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
    
    //printf("The gcd of %d and %d is %d\n", a, b, j);
}


