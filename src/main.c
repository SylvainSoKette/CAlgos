#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateRandomIntArray(int elements, int max_value)
{
	int r;
	int* array = malloc(sizeof(int) * elements);

	srand(time(NULL));

	for (int i = 0; i < elements; i++)
	{
		array[i] = rand() % max_value;
	}

	return array;
}

void displayIntArray(int* array, int const array_size)
{
	for (int i = 0; i < array_size; i++)
	{
		if (i == 0)
		{
			printf("[%d, ", array[i]);
		}
		else if (i == array_size -1)
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
	int numbers_to_generate;
	int* random_numbers;

	numbers_to_generate = 255;
	random_numbers = generateRandomIntArray(numbers_to_generate, 256);
	displayIntArray(random_numbers, numbers_to_generate);

	free(random_numbers);

	return 0;
}
