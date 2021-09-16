#include <iostream>
#include <iomanip>
using namespace std;
void init(int x[], int t[]){
    x[0] = 1;
    t[0] = 0;
}
void printRetuls(int arr[], int n){
    for (size_t i = 1; i <= n; i++)
    {
        /* code */
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void quy_lui(int i, int x[], int t[], int n){
    for(int j = x[i-1]; j <= (n-(t[i-1]))/2; j++){
        x[i] = j;
        t[i] = t[i-1] + j;
        quy_lui(i+1, x, t, n);
    }
    x[i] = n - t[i-1];
    printRetuls(x, i);
}
int main(){
    int x[30];
    int t[30];
    
    int n;
    cout << "Nhap n: ";
    cin >> n;

    init(x, t);
    quy_lui(1, x, t, n);
    return 0;
}