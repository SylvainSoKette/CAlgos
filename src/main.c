#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct
{
	int size;
	int* values;
} intArray_t;

intArray_t* newIntArray(int size)
{
	intArray_t* array_p;

	array_p = malloc(sizeof(intArray_t));
	array_p->size = size;
	if ((array_p->values = malloc(size * sizeof(array_p->values))) != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			array_p->values[i] = 0;
		}
	}

	return array_p;
}

intArray_t* newRandomIntArray(int size, int max_value)
{
	intArray_t* array_p;

	array_p = array_p = malloc(sizeof(intArray_t));
	array_p->size = size;
	if ((array_p->values = malloc(size * sizeof(array_p->values))) != NULL)
	{
		srand(time(NULL));
		for (int i = 0; i < size; i++)
		{
			array_p->values[i] = rand() % max_value;
		}
	}

	return array_p;
}

void displayIntArray(intArray_t* array_p)
{
	int i;

	for (i = 0; i < array_p->size; i++)
	{
		if (i == 0)
		{
			printf("[%d, ", array_p->values[i]);
		}
		else if (i == array_p->size -1)
		{
			printf("%d]\n", array_p->values[i]);
		}
		else
		{
			printf("%d, ", array_p->values[i]);
		}
	}
}

void bubbleSortIntArray(intArray_t* array_p)
{
	int i;
	int temp;
	bool did_swap;

	do
	{
		did_swap = false;
		for (i = 1; i < array_p->size; i++)
		{
			if (array_p->values[i - 1] > array_p->values[i])
			{
				temp = array_p->values[i];
				array_p->values[i] = array_p->values[i - 1];
				array_p->values[i - 1] = temp;
				did_swap = true;
			}
		}
	} while (did_swap);
}

/*
void insertSortIntArray(intArray_t* array_p)
{
	int i;
	int j;
	int temp;

	i = 1;
	while (i < array_p->size)
	{
		j = i;
		while (j > 0 && array_p->values[j-1] > array_p->values[j])
		{
			temp = array_p->values[j-1];
			array_p->values[j-1] = array_p->values[j];
			array_p->values[j] = temp;
			j--;
		}
		i++;
	}
}
*/

/*
 * Slightly optimized version of the insertion sort algorithm
 */
void insertSortIntArray(intArray_t* array_p)
{
	int i;
	int j;
	int temp;

	i = 1;
	while (i < array_p->size)
	{
		temp = array_p->values[i];
		j = i - 1;
		while (j >= 0 && array_p->values[j] > temp)
		{
			array_p->values[j+1] = array_p->values[j];
			j--;
		}
		array_p->values[j+1] = temp;
		i++;
	}
}

typedef enum
{
	SORT_BUBBLE,
	SORT_SELECTION,
	SORT_INSERT
} SortType;

void sortIntArray(intArray_t* array_p, SortType type)
{
	switch (type)
	{
		case SORT_BUBBLE:
			bubbleSortIntArray(array_p);
			break;
		case SORT_SELECTION:
			break;
		case SORT_INSERT:
			insertSortIntArray(array_p);
			break;
		default:
			break;
	}
}

int main(int argc, char* argv)
{
	intArray_t* array_p;

	array_p = newRandomIntArray(32, 256);

	displayIntArray(array_p);
	sortIntArray(array_p, SORT_INSERT);
	displayIntArray(array_p);

	free(array_p);

	return 0;
}
