#include<iostream>
using namespace std;

/*
          Problem: Given an array of n positive integers and a target sum s.
          Find a subarray whose sum is x or report that there is no such subarray.
*/

int n;
int target;
int a[100];

void solve()
{
          int l = 0;
          int r = 0;
          int sum = a[0];
          while(r < n)
          {
                    if(sum == target)
                    {
                              break;
                    }
                    else if(sum > target)
                    {
                              sum -= a[l];
                              l ++;
                    }
                    else
                    {         
                              r ++;
                              sum += a[r]; 
                    }
          }

          for(int i = l; i <= r; i++)
          {
                    cout << a[i] << " ";
          }
          cout << endl;
}

int main()
{
          cin >> n >> target;
          for(int i = 0; i < n; i++)
          {
                    cin >> a[i];
          }
          solve();
          return 0;
}