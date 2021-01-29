#include <iostream>
using namespace std;

int n;
int duration[100];
int deadline[100];

/* Problem:
          Given n tasks with durations and deadlines and our task is to choose an order to perform the tasks.
          For each task, we earn d - x points  where d is the task's deadline and x is the moment when we finish the task. 
          What is the largest possible total score we can obtain?

Solution:
          Just sort base on durations.
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
                    int mid = duration[(l + r) / 2];
                    int i, j;
                    i = l, j = r;
                    while(i <= j)
                    {
                              while(duration[i] < mid) i++;
                              while(duration[j] > mid) j--;
                              if(i <= j)
                              {
                                        swap(duration[i], duration[j]);
                                        swap(deadline[i], deadline[j]);
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
                    cin >> duration[i] >> deadline[i];
          }

          quickSort(0, n - 1);

          int s = 0;
          int time = 0;
          for (int i = 0; i < n; i++)
          {         
                    time += duration[i];
                    s += deadline[i] - time;
          }
          cout << s << endl;
          return 0;
}