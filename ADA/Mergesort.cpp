#include <bits/stdc++.h>
using namespace std;
void merge(int array[], int const left, int const mid, int const right)
{
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;


	int *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];
	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = {1,4,7,2,5,8,3,6,9};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printArray(arr, arr_size);
	return 0;
}