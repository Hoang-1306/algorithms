#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
// cho mot tap hop X = {1, 2, 3, 4, 5 , ... ,n-1, n}
// Hay liet ke tat ca tap con  m < n phan tu X
// Vi du A = {1, 2, 3, 4, 5}, hay liet ke tap con co 3 phan tu cua  => có 5C3 phần tử
// {1,2 ,3}, {1, 2, 4},  {1, 2, 5}, ....
// Thuat toan sinh ke tiep
// ham khoi tao

int *initialization(int &n, int &k, int *a)
{
    a = new int[k];
    for (int i = 0; i < k; i++)
    {
        a[i] = i + 1;
    }
    return a;
}
// function print result
void result(int *a, int k)
{   
    for (size_t i = 0; i < k; i++)
    {
        /* code */
        cout << setw(5) << a[i];
    }
    cout << endl;
}
// ham sinh day ke tiep = next swequence generator function
void generation(int *a, int n, int k, int &stop)
{
    int i = k - 1;
    if(k < 1){
        return;
    }
    while (i >= 0 && a[i] == n - k + i + 1)
    {
        i--;
    }
    if (i >= 0)
    {
        a[i]++;
        for (int j = i + 1; j < k; j++)
        {
            /* code */
            a[j] = a[i] + j - i;
        }
    }
    else
    {
        stop = 1;
    }
}
void handler_function(int *a, int n, int k, int &stop)
{
    int i = 0;
    while (!stop)
    {
        i++;
        cout << "Ham con thu" << setw(3) <<  i << " la: " << endl;
        result(a, k);
        generation(a, n, k, stop);
    };
}
int main()
{
    int n, k, stop = 0, *a;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap k: ";
    cin >> k;
    a = initialization(n, k, a);
    handler_function(a, n, k, stop);
    delete a;
    return 0;
}