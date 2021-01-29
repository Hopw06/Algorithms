#include <iostream>
using namespace std;

int n;
int queen[100];

int abs(int x)
{
          return x > 0 ? x : -x;
}

bool ucv(int i, int k)
{
          for(int j = 0; j < k; j ++)
          {
                    if(queen[j] == i) return false;
                    if(abs(queen[j] - i) == abs(j - k)) return false;
          }
          return true;
}

void printQueen()
{
          for(int i = 0; i < n; i++)
          {
                    cout << queen[i] << " ";
          }
          cout << endl;
}

void placeQueen(int k)
{
          for(int i = 0; i < n; i ++)
          {
                    if(ucv(i, k))
                    {
                              queen[k] = i;
                              if(k == n - 1)
                              {
                                        printQueen();
                              }
                              else
                              {
                                        placeQueen(k + 1); 
                              }
                    }
          }
}

int main()
{
          cin >> n;
          placeQueen(0);
          return 0;
}