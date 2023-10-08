#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}


/**
 * sorted - checks if an array or segment of an array is sorted
 * @array: array to be checked
 * @size: size of the array
 *
 * Return: 1 if true, else 0
 */
int sorted(int *array, size_t size)
{
	size_t i = 0;

	while (i < (size - 1))
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void qksort_pro(int *arr, size_t start, size_t size, size_t S)
{
	size_t j, p = size - 1, i = start;
	int large, temp, found = 0;

	if (sorted(arr, size))
		return;
	while (i < p)
	{
		if (arr[i] > arr[p])
		{
			large = arr[i], j = i + 1;
			while (j <= p)
			{
				if (arr[j] < arr[p])
				{
					arr[i] = arr[j], arr[j] = large;
					found = 1, sleep(1), print_array(arr, S);
					break;
				}
				else
					found = 0;
				j++;
			}
			if (!found)
				break;
		}
		i++;
	}
	if (!found && arr[p] != arr[i])
	{
		temp = arr[p], arr[p] = large, arr[i] = temp;
		found = 0, sleep(1), print_array(arr, S);
	}
	if (i == (size - 1))
		qksort_pro(arr, 0, (size - 1), S);
	else if (!i)
		qksort_pro(arr, 0, size, S);
	else
	{
		qksort_pro(arr, 0, i, S), qksort_pro(arr, (i + 1), size, S);
	}
}
/**
 * quick_sort - function that sorts an array of integers in ascending order
 * @array: array
 * @size: size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	qksort_pro(array, 0, size, size);
}

int main()
{
	//Sample Data Set
	int numArr[30] = {354383191, 67, 21, 34, 98, 47, 1, 23, 12, 11133, 88458, 2355, 34, 21, 789, 56, 242, 76544, 55655, 787, 123, 1344455333, 12323556, 24565, 1, 78534, 98657, 888867, 13312, 2};

	quick_sort(numArr, 30);
	return (0);
}
