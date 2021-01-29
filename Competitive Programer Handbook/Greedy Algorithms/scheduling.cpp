#include <iostream>
using namespace std;

int n;
int startTime[100];
int endTime[100];

/* Problem:
          Given n events with their starting and ending times, find a schedule that includes as many events as possible.
*/

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
                    int mid = endTime[(l + r) / 2];
                    int i, j;
                    i = l, j = r;
                    while(i <= j)
                    {
                              while(endTime[i] < mid) i++;
                              while(endTime[j] > mid) j--;
                              if(i <= j)
                              {
                                        swap(endTime[i], endTime[j]);
                                        swap(endTime[i], endTime[j]);
                                        i++;
                                        j--;
                              }
                    }
                    quickSort(l, j);
                    quickSort(i, r);
          }
}


int main()
{
          cin >> n;
          for (int i = 0; i < n; i++)
          {
                    cin >> startTime[i] >> endTime[i];
          }

          quickSort(0, n - 1);

          int i = 0;
          int cnt = 1;
          bool found = false;
          while (i < n)
          {
                    found = false;
                    for (int j = i + 1; j < n; j++)
                    {
                              if(startTime[j] > endTime[i])
                              {
                                        i = j;
                                        cnt++;
                                        found = true;
                                        break;
                              }
                    }

                    if(!found)
                    {
                              break;
                    }
          }
          cout << cnt << endl;
          return 0;
}