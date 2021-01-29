#include <iostream>
using namespace std;
/* Problem:
          Generate all sub set from a set of numbers. 
*/
int n;
int a[1000];

int subset[1000];
int sz;

void print_subset()
{         
          cout << ">: ";
          for (int i = 0; i < sz; i++)
          {
                    cout << subset[i] << " ";
          }
          cout << endl;
}

void search(int k)
{
          if(k == n)
          {
                    print_subset();
          }
          else
          {
                    search(k + 1);
                    subset[sz++] = k;
                    search(k + 1);
                    sz--;
          }
}

int main()
{
          cin >> n;
          for (int i = 0; i < n; i++)
          {
                    cin >> a[i];
          }
          search(0);
          return 0;
}