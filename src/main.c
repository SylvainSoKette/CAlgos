#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct
{
	int size;
	int* values;
} intArray_t;

intArray_t* newRandomIntArray(int size, int max_value)
{
	intArray_t* array_p;

	array_p->size = size;
	if ((array_p->values = malloc(sizeof(int) * size)) != NULL)
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
	int j;
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

typedef enum
{
	SORT_BUBBLE,
	SORT_SELECTION,
	SORT_INSERT
} SORT_TYPE;

void sortIntArray(intArray_t* array_p, SORT_TYPE type)
{
	switch (type)
	{
		case SORT_BUBBLE:
			bubbleSortIntArray(array_p);
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
	intArray_t* array_p;

	array_p = newRandomIntArray(32, 256);

	displayIntArray(array_p);
	sortIntArray(array_p, SORT_BUBBLE);
	displayIntArray(array_p);

	free(array_p);

	return 0;
}
