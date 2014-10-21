#include<iostream>
#include<cmath>
using namespace std;
int a[1000],b[1000],c[1000];
int k=0;
int ans=0;
int *ansarr=new int[1001];
int main()
{
for(int i=1;i<1000;i++)
for(int j=i+1;j<1000;j++)
{
double d=sqrt((i*i+j*j)*1.0);
if((int)d==d)
{a[k]=i;b[k]=j;c[k]=(int)d;k++;
cout<<i<<"\t"<<j<<"\t"<<d<<endl;}
}
for(int i=0;i<k;i++)
{
if((a[i]+b[i]+c[i])<=1000)
{
ansarr[a[i]+b[i]+c[i]]++;
if(ansarr[ans]<ansarr[a[i]+b[i]+c[i]])
ans=a[i]+b[i]+c[i];
}
}
for(int i=0;i<1001;i++)
if(ansarr[i]>3)
cout<<i<<"\t"<<ansarr[i]<<endl;


cout<<ans;   
   return 0;
}
