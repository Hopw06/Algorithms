#include <iostream>
using namespace std;

/*
          Problem: Given a list of weights [w1, w2, ..., wn].
          Determine all sums that can be constructed using the weights.
*/

int n;
int W;
int weights[1007];
bool possible[1007];

void solve()
{
          possible[0] = true;
          for(int i = 0; i < n; i++)
          {
                    for(int w = W; w >= 0; w--)
                    {
                              if(possible[w]) {
                                        possible[w + weights[i]] = true;
                              }
                    }
          }
          for(int w = 0; w <= W; w++)
          {
                    if(possible[w])
                    {
                              cout << w << " ";
                    }
          }
          cout << endl;
}

int main()
{
          cin >> n;
          for(int i = 0; i < n; i++)
          {
                    cin >> weights[i];
                    W += weights[i];
          }
          solve();
          return 0;
}