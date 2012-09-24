/**
 * Read and store datapoints input by user 
 * */

void	read_datapts(int count_datapts, int datapts[count_datapts])
{
	/* Local Declarations */
	int	index = 0;

	LB; printf("Enter the datapoints you want to track below");
	LB; printf("\n**Index = %d", index);

	for (index=0; index < count_datapts; index++)
	{
		printf("\ndatapts[%d] = ", index);
		scanf("%d", &datapts[index]);
	}

	/* Exit Function */
	return;
}

