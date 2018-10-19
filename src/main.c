#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateRandomIntArray(int n, int max)
{
	int r;
	int* array = malloc(sizeof(int) * n);

	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % max;
	}

	return array;
}

void displayIntArray(int* array, int const arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (i == 0)
		{
			printf("[%d, ", array[i]);
		}
		else if (i == arraySize -1)
		{
			printf("%d]", array[i]);
		}
		else
		{
			printf("%d, ", array[i]);
		}
	}
}

int main(int argc, char* argv)
{
	int numbersToGenerate;
	int* randomNumbers;

	numbersToGenerate = 255;
	randomNumbers = generateRandomIntArray(numbersToGenerate, 256);
	displayIntArray(randomNumbers, numbersToGenerate);

	free(randomNumbers);

	return 0;
}
