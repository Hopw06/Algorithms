#include <iostream>
using namespace std;

/*
          Problem: calculate the sum of values in area between two cell [a, b] and [c, d] in matrix.
          using prefix sum
*/

int n, m;
int a[100][100];
int prefix[100][100];

int solve(int a, int b, int c, int d)
{
          return prefix[c][d] - prefix[c][b - 1] - prefix[a - 1][d] + prefix[a - 1][b - 1];
}

int main()
{        
          cin >> n >> m;
          for(int i = 0; i < n; i++)
          {
                    for(int j = 0; j < m; j++)
                    {
                              cin >> a[i][j];
                    }
          }
          for(int i = 0; i < n; i++)
          {
                    prefix[i][1] = a[i][0];
                    prefix[1][i] = a[0][i];
          }
          
          for(int i = 1; i < n; i++)
          {
                    for(int j = 1; j < m; j++)
                    {
                              prefix[i + 1][j + 1] = prefix[i - 1][j] + prefix[i][j - 1] + a[i][j];
                    }
          }
          int a, b, c, d;
          cin >> a >> b >> c >> d;
          cout << solve(a, b, c, d) << endl;
          return 0;
}