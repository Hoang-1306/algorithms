#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void printResult(int arr[], int n)
{
    for (size_t i = 1; i <= n; i++)
    {
        /* code */
        cout << setw(5) << arr[i];
    }
    cout << endl;
}
bool OK(int arr[], int x1, int y1)
{
    for (int i = 1; i < x1; i++)
    {
        // ar[i] == y1 kiem tra xem quan hau nay co nam cung cot voi quan hau kia hay k
        //abs(i - x1) == abs( a[i] - y1 ) kiem tra xem con hau nay co nam
        //  tren duong cheo cua con hau trc do hay khong
        if (arr[i] == y1 || abs(i - x1) == abs(arr[i] - y1))
            return false;
    }
    return true;
}
void xu_li(int i, int arr[], int n)
{
    for (int j = 1; j <= n; j++)
    {
        if (OK(arr, i, j))
        {
            arr[i] = j;
            if (i == n)
            {
                printResult(arr, n);
            }
            xu_li(i + 1, arr, n);
        }
    }
}
int main()
{
    int arr[10];
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "So cot: \n";
    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << i + 1;
    }
    cout << endl;
    cout << setw(5) << "====================================\n";
    xu_li(1, arr, n);
    return 0;
}