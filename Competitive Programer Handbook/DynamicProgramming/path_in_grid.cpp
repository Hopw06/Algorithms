#include <iostream>
using namespace std;

int n;
int a[1007][1007];
int dp[1007][1007];
/*
          Given a matrix nxn with a positive number in each cell. Find a path from upper-left conner to the lower right conner that
          the sum of values along the path is as large as possible.
*/
void solve()
{
          for(int i = 1; i <= n; i++)
          {
                    for(int j = 1; j <= n; j++)
                    {
                              dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
                    }
          }
          cout << dp[n][n] << endl;
}

int main()
{
          cin >> n;
          for(int i = 1; i <= n; i++)
          {
                    for(int j = 1; j <= n; j++)
                    {
                              cin >> a[i][j];
                    }
          }
          solve();
          return 0;
}