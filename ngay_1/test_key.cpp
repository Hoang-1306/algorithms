#include <stdio.h>

int x, t, n, i, k, s;
int M[100];
int  main()
{
  printf("n = ");
  scanf("%d", &n);
  M[0] = n;
  k = i = 1;
ANALYZE:
  t = M[k - 1] - 1;
  s = t + i - k + 1;
  for (i = k; i <= n; i++)
  {
    if (s > t)
    {
      M[i - 1] = t;
      s = s - t;
    }
    else
    {
      M[i - 1] = s;
      goto SHOWRESULT;
    }
  }
SHOWRESULT:
  printf("%d = ", n);
  for (k = 1; k < i; k++)
    printf("%d + ", M[k - 1]);
  printf("%d\n", M[i - 1]);
  for (k = i; k >= 1; k--)
    if (M[k - 1] > 1)
      goto ANALYZE;
}