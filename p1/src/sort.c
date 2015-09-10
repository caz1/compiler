
void main()
{
    const int a[] = {1, 3, 5, 2+5, 3, 10, 7*2-1, 7%4, 6, 9};
    int i, j, max, temp, length;

    length = 10;
    i = 0;
    printf("Before sorting:\n");
    while (i != length)
    {
	printf("%d\t", a[i]);
	i = i + 1;
    }
    printf("\n");

    

    i = 0; 
    j = 0;
    while (i < length)
    {
	j = i + 1;
	max = i;
	while (j < length)
	{
	    if (a[max] < a[j]) max = j;
	    j = j + 1;
	}
	if (max != j)
	{
	    temp = a[max];
	    a[max] = a[i];
	    a[i] = temp;
	}
	i = i + 1;
    }

    i = 0;
    printf("After sotring:\n");
    while (i < length)
    {
 	printf("%d\t", a[i]);
	i = i + 1;
    }
    printf("\n");
}

