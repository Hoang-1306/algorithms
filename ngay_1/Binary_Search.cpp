#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
// tim kiem nhi phan
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
// cai nay de ty sd qsort
int binary_Search(int *arr ,int left, int right, int value)
{
    if (right >= left)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        if (arr[mid] > value)
        {
            return binary_Search(arr, left, mid - 1, value);
        }
        return binary_Search(arr, mid + 1, right, value);
    }
    return -1;
}
void output_Array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int main()
{
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 3, 5, 2, 5, 32, 2, 22, 34, 43, 13, 21, 32, 33, 34, 55, 89, 144, 233, 377, 610};
    int value;
    cout << "Nhap phan tu can tim kiem: ";
    cin >> value;
    int n = sizeof(arr) / sizeof(arr[0]);
    output_Array(arr, n);
    qsort(arr, n, sizeof(int), compare);
    int result = binary_Search(arr, 0, n-1, value);
    cout << endl;
    (result == -1)  ? cout << "Khong ton tai phan tu can tim kiem la " << value
                    : (cout << "Phan tu can tim kiem la: "<< value << " nam o vi tri thu: " << result);
    return 0;
}