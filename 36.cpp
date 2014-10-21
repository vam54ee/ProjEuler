#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
using namespace std;
int isdoublep(int a,int b,int d)
{int *x=new int[100];
int c=0,f=a/(int)pow(10,d%2);
for(int i=1;i<=b;i++)
{c*=10;
f=a/(int)pow(10,d%2);
f=f/(int)pow(10,i-1);
c+=f%10;

}
a=a*(int)pow(10,b)+c;
cout<<a<<"\t"<<b<<"\t"<<d<<endl;

int i,j;
for( i=a,j=0;i>0;i/=2,j++)
{
x[j]=i%2;
if(a==585)
cout<<x[j];
}
for(int z=0;z<j&&z<j-z-1;z++)
if(x[z]!=x[j-z-1])
return 0;
return a;
}
int main()
{int ans=25;
int x=0;
for(int i=100;i<1000;i++)
{
if(x=isdoublep(i,3,6))
ans+=x;
}
for(int i=100;i<1000;i++)
{
if(x=isdoublep(i,2,5))
ans+=x;}
for(int i=10;i<100;i++)
{if(x=isdoublep(i,2,4))
ans+=x;}
for(int i=10;i<100;i++)
{if(x=isdoublep(i,1,3))
ans+=x;}
for(int i=1;i<10;i++)
{if(x=isdoublep(i,1,2))
ans+=x;}

cout<<ans;
	return 0;
}
