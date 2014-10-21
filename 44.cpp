#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
long long int *x,*y,*z;


long long int iny(long long int f,long long int g)
{
double k=(1+sqrt(1+(4*6*(f+g))))/6;
int l=(1+sqrt(1+(4*6*(f+g))))/6;
double k1=(1+sqrt(1+(4*6*(f-g))))/6;
int l1=(1+sqrt(1+(4*6*(f-g))))/6;
//if(g==22)
//cout<<k<<"\t"<<l<<endl;
if(k==l&&k1==l1)
{cout<<f-g<<"\t"<<f<<"\t"<<g<<"\t"<<k<<"\t"<<l<<endl;return 1;}
return 0;
}


int main()
{int size=10000;
y=new long long int[size];
int a=1;

for(long long int i=1;i<size;i++)
{
long long int b,c;
b=(i*(3*i-1))/2;
y[i]=b;
}
for(long long int i=1;i<size;i++)
for(long long int j=i+1;j<size;j++)
if(iny(y[j],y[i]))
cout<<i<<"\t"<<j<<endl;
return 0;
}
