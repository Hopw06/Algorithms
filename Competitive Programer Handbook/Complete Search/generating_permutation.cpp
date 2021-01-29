#include <iostream>
using namespace std;
/* Problem:
          Generate all permutations from a set.
*/
int n;
int a[1000];

int permutation[1000];
bool visited[1000];

void printPermutation()
{
          for(int i = 0; i < n; i++)
          {
                    cout << permutation[i] << " ";
          }
          cout << endl;
}

void TRY(int k) 
{
          for(int i = 0; i < n; i++)
          {
                    if(!visited[i]) 
                    {
                              permutation[k] = a[i];
                              visited[i] = true;
                              if(k == n - 1) 
                              {
                                        printPermutation();
                              }
                              else
                              {
                                        TRY(k + 1);
                              }
                              visited[i] = false;
                    }
          }
}

int main()
{
          cin >> n;
          for (int i = 0; i < n; i++)
          {
                    cin >> a[i];
          }
          TRY(0);
          return 0;
}