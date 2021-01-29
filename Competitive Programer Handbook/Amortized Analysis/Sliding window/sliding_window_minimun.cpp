#include <iostream>
using namespace std;

/*
          Problem:
          Find minimum element in each subarray with size 4.
*/

int n;
int a[100];

int queue[1000];
int fr = 0, rear = 0;

void solve()
{
          int l = 0, r = 3;
          int min_element[100];
          int k = 0;
          while(r < n)
          {
                    if(queue[fr] < l) 
                    {
                              fr++;
                    }
                    for(int i = l; i <= r; i++)
                    {
                              while(rear > fr && a[queue[rear - 1]] >= a[i])
                              {
                                        rear -= 1;
                              }
                              queue[rear++] = i;
                    }
                    min_element[k++] = a[queue[fr]];
                    l++;
                    r++;
          }
          for(int i = 0; i < k; i++)
          {
                    cout << min_element[i] << " ";
          }
          cout << endl;
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