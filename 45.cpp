#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
long long int *x,*y,*z;


long long int iny(long long int f)
{
for(long long int i=0;i<100000;i++)
if(y[i]==f)
return 1;
return 0;
}

long long int inz(long long int f)
{
for(long long int i=0;i<100000;i++)
if(z[i]==f)
return 1;
return 0;

}


int main()
{x=new long long int[100000];
y=new long long int[100000];
z=new long long int[100000];

for(long long int i=0;i<100000;i++)
{
long long int a,b,c;
a=(i*(i+1))/2;
b=(i*(3*i-1))/2;
c=i*(2*i-1);
x[i]=a;y[i]=b;z[i]=c;
}
for(long long int i=0;i<100000;i++)
if(inz(x[i])&&iny(x[i]))
cout<<x[i]<<"\t"<<i<<endl;
return 0;
}
