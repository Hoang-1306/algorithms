#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
void ouput_array(int arr[], int k)
{
    for (size_t i = 1; i <= k; i++)
    {
        /* code */
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void generation(int i, int arr[], int n, int k)
{
    for (int j = arr[i - 1] + 1; j <= n - k + i; j++)
    {
        arr[i] = j;
        if (i == k)
        {
            ouput_array(arr, k);
        }
        else
        {
            generation(i + 1, arr, n, k);
        }
    }
}
int main()
{
    int n, k;
    int arr[100] = {};
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap k: ";
    cin >> k;
    generation(1, arr, n, k);
    return 0;
}