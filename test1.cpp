#include<iostream>
#include <time.h>
#include <stdio>
using namespace std;
int main()
{
 time_t start,end;
time (&start);
for(int i=1;i<10000;i++)
{
for(int j=1;j<10000;j++)
{
j%i;j*i;j+i;j/i;
}
}
time (&end);
double dif = difftime (end,start);
printf ("Elasped time is %.2lf seconds.", dif );

    return 0;
}
