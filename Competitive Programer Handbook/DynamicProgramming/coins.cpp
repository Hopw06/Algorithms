#include <iostream>
using namespace std;
/* Problem:
Give a set of coins and the task is to form a sum of money n using coins.
Find the minimum number of coins needed.
*/
int n, s;
int coins[100];

void solve() {
          // using dp
          int dp[1000];
          int first[1000];
          dp[0] = 0;
          first[0] = 0;
          for (int a = 1;  a <= s; a ++) 
          {         
                    int min = 1000000;
                    for(int i = 0; i < n; i ++ )
                    {
                              if(a - coins[i] >= 0) 
                              {
                                        if(1 + dp[a - coins[i]] < min) 
                                        {
                                                  min = 1 + dp[a - coins[i]];
                                                  first[a] = coins[i];
                                        }
                              }
                    }
                    dp[a] = min;
          }

          cout << dp[s] << endl;
          while(first[s]) 
          {
                    cout << first[s] << " ";
                    s -= first[s];
          }
          cout << endl;
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