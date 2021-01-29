#include<iostream>
using namespace std;

string x, y;
int dp[107][107];

int min(int a, int b, int c)
{
          int min = a;
          if(min > b) min = b;
          if(min > c) min = c;
          return min;
}

void solve()
{
          int n = x.size();
          int m = y.size();
          for(int i = 0; i <= n; i++)
          {
                    dp[i][0] = i;
          }

           for(int i = 0; i <= m; i++)
          {
                    dp[0][i] = i;
          }

          for(int i = 1; i <= n; i++)
          {
                    for(int j = 1; j <= m; j++)
                    {
                              int c = 0;
                              if(x[i - 1] != y[j - 1]) c = 1;
                              dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + c);
                    }
          }

          for(int i = 0; i <= n; i++)
          {
                    for(int j = 0; j <= m; j++)
                    {
                              cout << dp[i][j] << " ";
                    }
                    cout << endl;
          }
}

int main()
{
          cin >> x >> y;
          solve();
          return 0;
}