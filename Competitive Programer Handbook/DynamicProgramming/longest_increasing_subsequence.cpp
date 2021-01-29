#include<iostream>
using namespace std;

int n;
int a[1007];

void solve()
{
          int max = 0;
          int length[1007];
          for(int i = 0; i < n; i++)
          {
                    length[i] = 1;
                    for(int j = 0; j < i; j++)
                    {
                              if(a[j] < a[i]) 
                              {
                                        if(length[j] + 1 > length[i])
                                        {
                                                  length[i] = length[j] + 1;
                                        }
                              }
                    }
                    if(max < length[i])
                    {
                              max = length[i];
                    }
          }
          cout << max << endl;
}

int main()
{
          cin >> n;
          for(int i = 0; i < n; i++)
          {
                    cin >> a[i];
          }
          solve();
          return 0;
}