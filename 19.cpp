#include<iostream>
using namespace std;
int main()
{
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int k=3,z=0;
for(int i=1901;i<2001;i++)
{
for(int j=1;j<=12;j++)
{
if(j!=2)
k+=(a[j]%7);
else if(j==2 && j%4==0)
k+=(1);
if(k>7)
k=(k%7);
if(k==1)
z++;
cout<<k<<endl;
}
}   
cout<<z;

   return 0;
}
