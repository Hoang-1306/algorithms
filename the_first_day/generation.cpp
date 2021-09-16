#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;
void Gen(int a[], int n)
{
	++a[n - 1];
	for (int i = n - 1; i > 0; i--)
	{
		if (a[i] > 1)
		{
			++a[i - 1];
			a[i] -= 2;
		}
	}
}
// ham generation sai vcl luon
bool generation(int *a, int &n)
{
	int index = n - 1;
	a[n - 1] = 1;
	while (a[index] == 1 && index >= 0)
		index--;
	if (index == -1)
		return false;
	else
	{
		a[index] = 1;
		for (size_t i = index + 1; i < n; i++)
		{
			/* code */
			a[i] = 0;
		}
	}
	return generation(a, n);
}
void Output(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i];
	cout << endl;
}
int *init_array(int *a, int &n)
{
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
	return a;
}
void handler_fuctions(int *a, int &n)
{
	for (size_t i = 0; i < pow(2, n); i++)
	{
		/* code */
		cout << "Mang thu" << setw(3) << i + 1 << " la: " << endl;
		Output(a, n);
		Gen(a, n);
	}
}
int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int *a;
	a = init_array(a, n);
	handler_fuctions(a, n);
	return 0;
}