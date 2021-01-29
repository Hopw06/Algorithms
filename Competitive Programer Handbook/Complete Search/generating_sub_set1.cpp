#include <iostream>
using namespace std;
/* Problem:
          Generate all sub set from a set of numbers. 
          Using bit representation
*/
int n;
int a[1000];

int subset[1000];
int sz;

int main()
{
          cin >> n;
          for (int i = 0; i < n; i++)
          {
                    cin >> a[i];
          }

          for (int b = 0; b < (1 << n);  b++)
          {         
                    for(int i = 0; i < n; i++) {
                              if (b & (1 << i)) {
                                        subset[sz++] = a[i];
                              }
                    }
                    cout << ">: ";
                    for(int i = 0; i < sz; i++)
                    {
                              cout << subset[i] << " ";
                    }
                    cout << endl;
                    sz =0;
          }
          return 0;
}