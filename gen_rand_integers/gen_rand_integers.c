/**
 * Program to make a file with random integers 
 * */

#include <stdio.h>
#include <stdlib.h>

#define LB printf("\n")

int main(void)
{
	/* Local Declarations */
	int	lb;
	int	ub;
	int	range;
	int	rnd_num;
	int	tot_count;
	int	wrt_count;
	int	lin_count;
	FILE*	sp_write;

	/* Open stream */
	if ((sp_write = fopen("values.txt", "w")) == NULL)
	{
		LB;
		printf("ERROR: Could not create values.txt");
		LB;
		exit(101);
	}

	LB; printf("This program generates and writes random integers to a file.");
	LB; printf("Please specify the range in which you want to generate random integers.");

	LB; printf("lower bound = ");
	while (scanf("%d", &lb) != 1)
		{LB; printf("Invalid input");}

	LB; printf("upper bound = ");
	while (scanf("%d", &ub) != 1)
		{LB; printf("Invalid input");}

	LB; printf("How many numbers do you want to generate? ");
	while (scanf("%d", &tot_count) != 1)
		{LB; printf("Invalid input");}

	range = ub - lb;

	lin_count = 0;
	wrt_count = 0;
	while (wrt_count < tot_count)
	{
		rnd_num = (rand() % range) + lb;
		fprintf(sp_write,"%7d", rnd_num);
		wrt_count++;

		if ((wrt_count % 10) == 0)
		{
			fprintf(sp_write, "\n");
			lin_count++;
		}
		else
			fprintf(sp_write, " ");
	}

	/* Close stream */
	if (fclose(sp_write) == EOF)
	{
		LB; printf("ERROR: Could not close values.txt"); LB;
		exit(102);
	}

	LB; printf("Count of numbers written to the file = %d", wrt_count);;
	LB; printf("Count of lines inserted in the file = %d", lin_count);

	/* Exit Program */
	LB; LB;
	return;
}

