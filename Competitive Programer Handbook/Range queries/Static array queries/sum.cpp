#include<iostream>
using namespace std;
/*
          Problem: calculate the sum of values in range [a, b]
          using prefix sum
*/
int n;
int a[100];
int prefix[100];

int solve(int a, int b)
{
          int st = 0;
          if(a > 0) 
          {
                    st = prefix[a - 1];
          }
          return prefix[b] - st;
}

int main()
{
          cin >> n;
          cin >> a[0];
          prefix[0] = a[0];
          for(int i = 1; i < n; i++)
          {
                    cin >> a[i];      
                    prefix[i] = prefix[i - 1] + a[i];   
          }

          int a, b;
          cin >> a >> b;
          cout << solve(a, b) << endl;
          return 0;
}