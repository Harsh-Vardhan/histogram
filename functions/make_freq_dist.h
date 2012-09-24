/**
 * Make frequency distribution table
 * */

void	make_freq_dist(int sample_size, int count_datapts, int datapts[count_datapts], int freq[count_datapts])
{
	/* Local Declarations */
	int	index;
	int	count_scanned_values = 0;
	int	count_valid_values = 0;
	int	num;
	FILE*	sp_read;
	FILE*	sp_scanned;
	FILE*	sp_valid;

	/* Initialize frequency for all datapoints to be zero */
	for (index = 0; index < count_datapts; index++)
		freq[index] = 0;

	/* Open stream to read from */
	if ((sp_read = fopen("values.txt", "r")) == NULL)
	{
		LB; printf("ERROR: Failed to open values.txt for reading");
		LB; printf("Program terminated...!");
		LB; LB;
		exit(101);
	}

	/* Open stream to write all values scanned */
	if ((sp_scanned = fopen("scanned_values.txt", "w")) == NULL)
	{
		LB; printf("ERROR: Failed to open scanned_values.txt for writing");
		LB; printf("Program terminated...!");
		LB; LB;
		exit(101);
	}

	/* Open stream to write all valid values found, i.e., sample */
	if ((sp_valid = fopen("valid_values.txt", "w")) == NULL)
	{
		LB; printf("ERROR: Failed to open valid_values.txt for writing");
		LB; printf("Program terminated...!");
		LB; LB;
		exit(101);
	}

	/* Read upto sample_size from the file and update frequency for each datapoint */
	while ((count_valid_values < sample_size) && (fscanf(sp_read, "%d", &num) != EOF))
	{
		fprintf(sp_scanned,"%7d", num);
		count_scanned_values++;

		if ((count_scanned_values % 10) == 0)
			fprintf(sp_scanned, "\n");
		else
			fprintf(sp_scanned, " ");


		index = 0;
		while(index < count_datapts)
		{
			if (datapts[index] == num)
			{
				fprintf(sp_valid,"%7d", num);
				count_valid_values++;

				if ((count_valid_values % 10) == 0)
					fprintf(sp_valid, "\n");
				else
					fprintf(sp_valid, " ");

				freq[index]++;
			}

			index++;
		}
	}

	/* Close all open streams */
	if (fclose(sp_read) == EOF)
	{
		LB; printf("ERROR: Failed to close values.txt");
	}

	LB; printf("Scanned %d values", count_scanned_values);
	LB; printf("Found %d valid values ", count_valid_values);

	/* Exit Function */
	return;
}

