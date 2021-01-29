#include<iostream>
using namespace std;

/* 
          Problem: Find for each array element the nearest smaller element.
*/

int n;
int a[100];

int sz;
int stack[100];

void push(int value)
{
          stack[sz++] = value;
}

int pop()
{
          int value = stack[sz - 1];
          sz -= 1;
          return value;
}

int top()
{
          return stack[sz - 1];
}

void solve()
{
          int nearest_smaller_elements[100];
          for(int i = 0; i < n; i ++)
          {
                    while(sz > 0 && top() >= a[i])
                    {
                              pop();
                    }
                    if(sz > 0)
                    {
                              nearest_smaller_elements[i] = top();
                    }
                    else
                    {
                              nearest_smaller_elements[i] = -1;
                    }
                    push(a[i]);
          }
          for(int i = 0; i < n; i++)
          {
                    cout << nearest_smaller_elements[i] << " ";
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