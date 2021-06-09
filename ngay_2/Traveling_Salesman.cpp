#include <iostream>
#include <iomanip>
#define MAX 20
#define maxC (MAX * 100)
using namespace std;
// bai toan nguoi du lich
int C[MAX][MAX];
int X[MAX + 1];
int BestWay[MAX + 1];
int T[MAX];
bool Free[MAX];
int MinSpending;
int m, n;
// on gioi da dung roy

void Enter()
{

    int i, j, k;
    for (i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                C[i][j] = 0;
            }
            else
            {
                C[i][j] = maxC;
            }
        }
    }
    for (k = 1; k <= m; k++)
    {
        /* code */
        cout << "Enter i: ";
        cin >> i;
        cout << "Enter j: ";
        cin >> j;
        cout << "Cost: " << i << "->" << j << "]: ";
        cin >> C[i][j];
        C[j][i] = C[i][j];
    }
}
void Init()
{
    for (int i = 1; i <= n; i++)
    {
        Free[i] = true;
    }
    Free[1] = false;
    X[1] = 1;
    T[1] = 0;
    MinSpending = maxC;
}
void Try(int i)
{
    int j;
    for (j = 2; j <= n; j++)
    {
        if (Free[j] ==true)
        {
            X[i] = j;
            T[i] = T[i - 1] + C[X[i - 1]][j];
            if ((T[i] + C[i][1]) < MinSpending)
            {
                if (i < n)
                {
                    Free[j] = false;
                    Try(i + 1);
                    Free[j] = true;
                }
                else
                {
                    for (int var = 1; var <= n; var++)
                    {
                        BestWay[var] = X[var];
                    }
                    MinSpending = T[n] + C[X[n]][1];
                }
            }
        }
    }
}
void printResult()
{
    if (MinSpending == maxC)
    {
        cout << "No solution";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << BestWay[i] << "->";
        }
        cout << "Cost min spending is : " << MinSpending;
    }
}
int main()
{
    cout << "Input city: ";
    cin >> n;
    cout << "Input traffic road: ";
    cin >> m;
    Enter();
    Init();
    Try(2);
    cout << "Print cost: ";
    printResult();
    return 0;
}