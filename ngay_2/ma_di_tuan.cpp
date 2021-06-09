#include <iostream>
#define MAX 8
using namespace std;
// code nay chi dung khi bat dau tai vi tri (0, 0) thoi
int cols[8] = {-2, -2, -1, -1, 1, 1, 2, 2}; // column  = cot
int rows[8] = {-1, 1, -2, 2, -2, 2, -1, 1}; // row = hang
void printRetult(int arr[MAX][MAX], int n){
    for(int i=0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
void matrix_chess(int arr[MAX][MAX], int count, int &n, int x, int y){
    ++count;
    arr[x][y] = count;
    for(int i = 0; i < MAX; i++){
        if(count == n*n){
            cout << "Cac buoc di chuyen la: \n";
            printRetult(arr, n);
            exit(0);
        }
        int u = x + cols[i]; // vi tri cu cong them gia tri moi de ra vi tri moi 
        int v = y + rows[i];
        if(u >= 0 && u < n && v >=0 && v < n && arr[u][v] == 0)
            matrix_chess(arr, count, n, u, v);
    }
    --count;
    arr[x][y] = 0;
}
int main(){
    int n, x, y;
    int count = 0;
    int arr[MAX][MAX] = {0};
    do{
    cout << "Nhap 0 < n <= 8: ";
    cin >> n;
    }while(n> 8 || n <= 0);
    cout << "Nhap vi tri x: ";
    cin >> x;
    cout << "Nhap vi tri y: ";
    cin >> y;
    matrix_chess(arr, count , n, x-1, y-1);
    return 0;
}