#include<iostream>
using namespace std;

void check(int i)
{
int* a=new int[10];
int *b=new int[10];
for(int j=i,k=2*i;j>0;j/=10,k/=10)
{a[j%10]++;b[k%10]++;}
for(int j=0;j<10;j++)
{if(a[j]!=b[j])return;}
b=new int[10];
for(int k=3*i;k>0;k/=10)
{b[k%10]++;}
for(int j=0;j<10;j++)
{if(a[j]!=b[j])return;}
b=new int[10];
for(int k=4*i;k>0;k/=10)
{b[k%10]++;}
for(int j=0;j<10;j++)
{if(a[j]!=b[j])return;}
b=new int[10];
for(int k=5*i;k>0;k/=10)
{b[k%10]++;}
for(int j=0;j<10;j++)
{if(a[j]!=b[j])return;}
b=new int[10];
for(int k=6*i;k>0;k/=10)
{b[k%10]++;}
for(int j=0;j<10;j++)
{if(a[j]!=b[j])return;}
cout<<i<<endl;
}

int main()
{
for(int i=100000;i<(1000000/6);i++)
check(i);
    return 0;
}
