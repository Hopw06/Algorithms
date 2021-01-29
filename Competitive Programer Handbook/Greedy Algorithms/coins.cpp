#include <iostream>
using namespace std;
/* Problem:
Give a set of coins and the task is to form a sum of money n using coins.
Find the minimum number of coins needed.
*/
int coins[100];

void quicksort(int l, int r)
{
          if(l < r)
          {
                    int mid = coins[(l + r) / 2];
                    int i = l;
                    int j = r;
                    while(i <= j)
                    {
                              while(coins[i] < mid) i++;
                              while(coins[j] > mid) j--;
                              if(i <= j)
                              {
                                        int tmp = coins[i];
                                        coins[i] = coins[j];
                                        coins[j] = tmp;
                                        i++;
                                        j--;
                              }
                              quicksort(l, j);
                              quicksort(i, r);
                    }
          }
}

int main()
{
          // always select the largest possible coin.
          int n, s;
          cin >> n >> s;
          for(int i = 0; i < n; i++)
          {
                    cin >> coins[i];
          }
          // first we need to sort coins.
          quicksort(0, n - 1);
          for(int i = 0; i < n; i++)
          {
                    cout <<  coins[i] << " ";
          }
          // apply greedy algorithm
          int cnt = 0;
          for(int i = n - 1; i >= 0; i--)
          {
                    while(s >= coins[i])
                    {
                              s -= coins[i];
                              cout << coins[i] << " " << s << endl;
                              cnt++;
                    }
          }
          cout << cnt << endl;
          return 0;
}