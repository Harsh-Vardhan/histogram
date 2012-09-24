/**
 * Make histogram for a given frequency distribution
 * \param	count_datapts	size of variable array freq[]
 * \param	datapts		array that contains datapoints for creating the histogram
 * \param	freq[]		array that contains frequency for each datapoint
 * */

void	make_histogram(int count_datapts, int datapts[count_datapts], int freq[count_datapts])
{
	/* Local Declarations */
	int	index = 0;
	int	i;

	LB; printf("Value\tFrequency\tHistogram");
	LB; printf("-----\t---------\t---------");
	while (index < count_datapts)
	{
		LB; printf("%4d\t%4d\t\t", datapts[index], freq[index]);

		for (i = 1; i <= freq[index]; i++)
			printf("*");

		index++;
	}

	/* Exit Function */
	return;
}

