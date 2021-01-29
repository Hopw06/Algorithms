#include <iostream>
using namespace std;
/* Problem:
Give a set of coins and the task is to form a sum of money n using coins.
Count the number of ways to form the sum.
*/
int n, s;
int coins[100];

void solve() {
          // using dp
          int P = 1000007;
          int dp[1000];
          dp[0] = 1;
          for (int a = 1;  a <= s; a ++) 
          {         
                    for(int i = 0; i < n; i ++ )
                    {
                              if(a - coins[i] >= 0) 
                              {
                                        dp[a]  += dp[a - coins[i]];
                                        dp[a] %= P;
                              }
                    }
                    cout << dp[a] << " ";
          }

          // cout << dp[s] << endl;
}

int main()
{
          cin >> n >> s;
          for(int i = 0; i < n; i++)
          {
                    cin >> coins[i];
          }
          solve();
          return 0;
}