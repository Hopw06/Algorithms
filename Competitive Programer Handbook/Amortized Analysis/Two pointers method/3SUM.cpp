#include<iostream>
using namespace std;

/*
          Problem:
          Given an array of n positive integers and a target sum x.
          Find 3 value in array that sum up to x.
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

int binary_search(int l, int r, int value)
{
          while(l < r)
          {
                    int mid = (l + r) / 2;
                    if(a[mid] == value) return mid;
                    else if(a[mid] > value) 
                    {
                              r = mid - 1;
                    }
                    else
                    {
                              l = mid + 1;
                    }
          }
          return -1;
}

void solve()
{
          quickSort(0, n - 1);
          int l = 0, r = n - 1;
          int mid;
          int sum;
          int remain;
          while(l < r)
          {
                    sum = a[l] + a[r];
                    remain = target - sum;
                    if(remain < 0)
                    {
                              r--;
                    }
                    else if(remain <= a[l])
                    {
                              mid = binary_search(0, l, remain);
                              if(mid != -1)
                              {
                                       cout << a[l] << " " << a[mid] << " " << a[r] << endl;
                                       l++;
                              }
                              else
                              {
                                        r--;
                              }
                    }
                    else if(remain >= a[r])
                    {
                              mid = binary_search(r, n - 1, remain);
                              if(mid != -1)
                              {
                                        cout << a[l] << " " << a[mid] << " " << a[r] << endl;
                                        l++;
                              }
                              else
                              {
                                        l++;
                              }
                    }
                    else
                    {
                              l++;
                    }
          }
          // if(l < r && mid != -1)
          // {
          //           cout << a[l] << " " << a[mid] << " " << a[r];
          // }
          // else
          // {
          //           cout << "Not found" << endl;
          // }
          // cout << endl;
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