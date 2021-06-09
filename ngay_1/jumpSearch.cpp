#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
//Like Binary Search,
//Jump Search is a searching algorithm for sorted arrays.
//The basic idea is to check fewer elements(than linear search)
//by jumping ahead by fixed steps or
//skipping some elements in place of searching all elements.

int jumpSearch(int arr[], int x, int n)
{
	int step = sqrt(n);
	int prev = 0;
	while (arr[min(step, n) - 1] < x)
	{
		prev = step;
		step += sqrt(n);
		if (prev >= n)
		{
			return -1;
		}
	}
	while (arr[prev] < x)
	{
		prev++;
		if (prev == min(step, n))
			return -1;
	}
	if (arr[prev] == x)
		return prev;
	return -1;
}
int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
int main()
{
	int arr[] = {0, 1, 1, 2, 3, 5, 8, 3, 5, 2, 5, 32, 2, 22, 34, 43, 13, 21, 32, 33, 34, 55, 89, 144, 233, 377, 610};

	int n = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, n, sizeof(int), compare);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	int x = 43;
	//qsort_s(arr,0, n-1);

	int index = jumpSearch(arr, x, n);
	cout << "\n" << n;
	cout << "\nNumber " << x << " is at index " << index;
	return 0;
}