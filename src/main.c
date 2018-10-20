#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	int size;
	int* data;
} t_intArray;

int* generateRandomIntArray(int size, int max_value)
{
	int r;
	int* data;

	data = malloc(sizeof(int) * size);
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		data[i] = rand() % max_value;
	}

	return data;
}

void displayIntArray(t_intArray array)
{
	int i;

	for (i = 0; i < array.size; i++)
	{
		if (i == 0)
		{
			printf("[%d, ", array.data[i]);
		}
		else if (i == array.size -1)
		{
			printf("%d]", array.data[i]);
		}
		else
		{
			printf("%d, ", array.data[i]);
		}
	}
}

void bubbleSortIntArray(t_intArray array)
{

}

enum SORT_TYPE
{
	SORT_BUBBLE,
	SORT_SELECTION,
	SORT_INSERT
};

void sortIntArray(t_intArray array, enum SORT_TYPE type)
{
	switch (type)
	{
		case SORT_BUBBLE:
			bubbleSortIntArray(array);
			break;
		case SORT_SELECTION:
			break;
		case SORT_INSERT:
			break;
		default:
			break;
	}
}

int main(int argc, char* argv)
{
	t_intArray array;

	array.size = 256;
	array.data = generateRandomIntArray(array.size, 256);

	displayIntArray(array);
	sortIntArray(array, SORT_BUBBLE);
	displayIntArray(array);

	free(array.data);

	return 0;
}
