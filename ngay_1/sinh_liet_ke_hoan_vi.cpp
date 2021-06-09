#include <iostream>
#include <iomanip>

using namespace std;
void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int *initialization(int *a, int &n){
    a = new int[n];
    for (size_t i = 1; i <= n; i++)
    {
        /* code */
        // khoi tao cau hinh  x1 =  1, x2 = 2, x3= 3, ..., xN = N
        a[i] = i;
    }
    return a;
}
void result(int *a, int n){
    for (size_t i = 1; i <= n; i++)
    {
        /* code */
        cout << setw(5) << a[i];
    }
    cout << endl;
}
void gen(int *a, int n, int &count){
    int i, k , x, y;
    i = n - 1;
    while(i > 0 && a[i] > a[i+1])
        i--;
    if(i > 0){
        k = n;
        while(a[i] > a[k]) k--;
        Swap(a[i], a[k]);
        x = i + 1;
        y = n;
        while (x <= y)
        {
            /* code */
            Swap(a[x], a[y]);
            x++;
            y--;
        };
    }else{
        count = 0;
    }
}
void handler_function(int *a, int n, int &count){
    int i = 0;
    while (count)
    {
        /* code */
        i++;
        cout << "Mang thu " << setw(3) << i << " la: " << endl;
        result(a, n);
        gen(a, n, count);
    };
}
int main(){
    int n, count = 1;
    int *a;
    cout << "Nhap n: ";
    cin >> n;
    a = initialization(a, n);
    // result(a, n);
    handler_function(a, n , count);
    delete a;
    return 0;
}