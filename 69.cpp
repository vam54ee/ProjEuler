#include<iostream>
using namespace std;
int size=1000000;
 int j=3;
int *b=new int[size];

void prime(){

b[0]=1;
b[1]=2;b[2]=3;
 for(int i=5;i<=size;i+=2)
 {
 int x=1;
 for(int c=1;c<j;c++)
 if(i%b[c]==0)
 x=0;
 if(x)
 {b[j]=i;j++;}
 }
 }
int main()
{double* a=new double[size];
int max1=2;
 for(int i=0;i<size;i++)
a[i]=1;
prime();
 for(int i=1;i<j;i++)
{double x=1-(1.0/b[i]);
//cout<<x<<endl;
for(int k=1;b[i]*k<size;k++)
{
a[b[i]*k]*=(1/x);
}
}
for(int i=2;i<size;i++)
{
if(a[max1]<a[i])
max1=i;
//cout<<a[i]<<endl;
}
cout<<max1;
return 0;
}
  