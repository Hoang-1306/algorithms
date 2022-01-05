#include <math.h>
#include <stdio.h>
// store input bits
int input[32];
// store hamming code
int code[32];

int ham_calc(int, int);

void solve(int input[], int);
// function to calculate bit for
// ith position

int ham_calc(int position, int c_l)
{
    int count = 0, i;
    i = position - 1;
    // Traverse to store Hamming Code
    while (i < c_l)
    {
        /* code */
        for (int j = i; j < i + position; j++)
        {
            // If current boit is 1
            if (code[j] == 1)
            {
                count++;
            }
        }
        // update i
        i = i + 2 * position;
    }
    if (count % 2 == 0)
        return 0;
    else
        return 1;
}

void solve(int input[], int n)
{
    int i, p_n = 0, c_l, j, k;
    i = 0;

    while (n > (int)pow(2, i) - (i + 1))
    {
        p_n++;
        i++;
    }
    c_l = p_n + n;
    j = k = 0;
    for (i = 0; i < c_l; i++)
    {
        // Update the code
        if (i == ((int)pow(2, k) - 1))
        {
            code[i] = 0;
            k++;
        }else{
            code[i] = input[j];
            j++;
        }
    }
    // update the hamming code
    for(i = 0; i < p_n; i++){
        int position = (int)pow(2, i);
        int value = ham_calc(position, c_l);
        code[position - 1] =  value;
    }
    // print the hamming code
    printf("\nThe generated code word is: ");
    for(i = 0; i < c_l; i++){
        printf("%d", code[i]);
    }
}

// Driver Code
int main()
{
    // Given input message Bit
    input[0] = 0;
    input[1] = 1;
    input[2] = 1;
    input[3] = 1;
 
    int N = 4;
 
    // Function Call
    solve(input, N);
}