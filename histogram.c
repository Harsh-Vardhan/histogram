/**
 * Take a sample of values from a file and generate frequency distribution 
 * table and a histogram, for datapoints specified by the user
 * */

#define LB printf("\n")
#define FLUSH while (getchar() != '\n')

#include <stdio.h>
#include <stdlib.h>
/* Function Declarations */
#include "functions/read_datapts.h"
#include "functions/make_freq_dist.h"
#include "functions/make_histogram.h"

int main(void)
{
	/* Local Declarations */
	int	count_datapts = 0;
	int	sample_size = 0;

	LB; printf("This program will generate a frequency distribution and a histogram");

	LB; printf("Sample size = ");
	scanf("%d", &sample_size);

	printf("Number of datapoints = ");
	scanf("%d", &count_datapts);

	int	datapts[count_datapts];
	int	freq[count_datapts];

	/* Read datapoints */
	read_datapts(count_datapts, datapts);

	/* Make frequency distribution */
	make_freq_dist(sample_size, count_datapts, datapts, freq);

	/* Make histogram */
	make_histogram(count_datapts, datapts, freq);

	/* Exit Program */
	LB; LB;
	return;
}

