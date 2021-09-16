#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 100

void xuat(int arr[], int n){
    for (size_t i = 1; i <= n; i++)
    {
        /* code */
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void Try(int i, int arr[], int n, int Bool[]){
    for (size_t j = 1; j <= n; j++)
    {
        /* code */
        if(!Bool[j]){
            arr[i] = j;
            Bool[j] = 1;
            if(i == n){
                xuat(arr, n);
            }
            else{
                Try(i+1, arr, n, Bool);
            }
            Bool[j] = 0;
        }
    }
    
}
int main(){
    int n;
    int i = 1;
    int arr[100];
    int Bool[100]= {0};
    cout << "Nhap n: ";
    cin >> n;
    Try(i, arr, n, Bool);
}