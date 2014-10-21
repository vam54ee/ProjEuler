#include<iostream>
#include<fstream>
using namespace std;
void cancel(int a,int b)
{//cout<<a<<"\t"<<b<<endl;
int a1,a2,b1,b2;
a1=a/10;
a2=a%10;
b1=b/10;
b2=b%10;
//cout<<(a2==b1)<<"\t"<<(b2/((1.0*a1))<<"\t";
if(a1==b1&&a2!=0)
{
if(b2/(1.0*a2)==b/(1.0*a))
{
cout<<a<<"\t"<<b<<endl;
}
}
if(a1==b2&&a2!=0)
{
if(b1/(1.0*a2)==b/(1.0*a))
{
cout<<a<<"\t"<<b<<endl;
}
}
if(a2==b1&&a1!=0)
{
if(b2/(1.0*a1)==b/(1.0*a))
{
cout<<a<<"\t"<<b<<endl;
}
}
if(a2==b2&&a1!=0)
{
if(b1/(1.0*a1)==b/(1.0*a))
{
cout<<a<<"\t"<<b<<endl;
}
}
}
int gcd(int a, int b) {
  int r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main()
{
for(int i=11;i<100;i++)
{
for(int j=i+1;j<100;j++)
{//cout<<i<<"\t"<<j<<"\t"<<gcd(i,j)<<endl;
if(gcd(i,j)!=1)
cancel(i,j);
}
}
//cancel(49,98);
  return 0;
}
