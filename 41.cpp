#include<iostream>
#include<cmath>
using namespace std;
int isprime(int p)
{
for(int i=2;i<sqrt(p);i++)
{
if(p%i==0)
return 0;
}
return 1;
}
int ispan(int p)
{
int* a=new int[8];
while(p>0)
{if(p%10==0)
return 0;
if(a[p%10]>0)
return 0;
a[p%10]++;
p/=10;
}
for(int i=1;i<8;i++)
if(a[i]!=1)
return 0;
return 1;
}
int main()
{
for(int i=166667;i<=1666666;i++)
{
if(ispan(6*i+1))
if(isprime(6*i+1))
cout<<(6*i+1)<<endl;
if(ispan(6*i-1))
if(isprime(6*i-1))
cout<<(6*i-1)<<endl;
}
return 0;
}
