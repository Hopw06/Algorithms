#include<iostream>
using namespace std;

/*
          Problem:
          Given an array of n positive integers and a target sum x.
          Find two value in array that sum up to x.
*/

int n;
int target;
int a[100];

void swap(int* a, int* b)
{
          int tmp = *a;
          *a = *b;
          *b = tmp;
}

void quickSort(int l, int r)
{
          if(l < r)
          {
                    int mid = a[(l + r) / 2];
                    int i, j;
                    i = l, j = r;
                    while(i <= j)
                    {
                              while(a[i] < mid) i++;
                              while(a[j] > mid) j--;
                              if(i <= j)
                              {
                                        swap(a[i], a[j]);
                                        i++;
                                        j--;
                              }
                    }
                    quickSort(l, j);
                    quickSort(i, r);
          }
}



void solve()
{
          quickSort(0, n - 1);
          int l = 0, r = n - 1;
          int sum = a[l] + a[r];
          while(sum != target && l < r)
          {
                    if(sum > target)
                    {
                              sum -= a[r];
                              r--;
                              sum += a[r];
                    }
                    else
                    {
                              sum -= a[l];
                              l++;
                              sum += a[l];
                    }
          }
          if(l < r)
          {
                    cout << a[l] << " " << a[r];
          }
          else
          {
                    cout << "Not found" << endl;
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