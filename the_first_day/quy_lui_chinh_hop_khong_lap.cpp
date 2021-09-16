#include <iostream>
#include <iomanip>
using namespace std;

void initizlize(int arr[], int k){
    for (size_t i = 1; i <= k; i++)
    {
        arr[i] = 1;
    }
}

void output_array(int arr[], int k){
    for(int i = 1 ;i <= k; i++){
        cout <<  setw(5) << arr[i];
    }
    cout << endl;
}

void next_gen(int i, int arr[], int bool_arr[], int k, int n){
    for(int j = 1; j <= n; ++j){

        if(bool_arr[j]){
            arr[i] = j;
            if(i == k){
            
                output_array(arr, k);
            }else{
                bool_arr[j] = 0;
                next_gen(i+1, arr, bool_arr, k, n);
                bool_arr[j] = 1;
            }
        }
    }
}
int main(){
    int n;
    int k;
    int arr[100] = {};
    int bool_arr[100];
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap k: ";
    cin >> k;
    initizlize(bool_arr, n);
    next_gen(1, arr, bool_arr, k, n);

    return 0;
}