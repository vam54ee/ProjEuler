#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
using namespace std;
long long int a[10];
int main()
{a[0]=1;a[1]=1;a[2]=2;
for(long long int i=3;i<10;i++)
a[i]=a[i-1]*i;
long long int ans=0;
for(long long int i=10;i<10000000;i++)
{long long int sum=0;
for(long long int j=i;j>0;j=j/10)
{
sum=sum+a[j%10];
}
if(sum==i)
{ans+=i;cout<<i<<endl;}
}
cout<<ans;

	return 0;
}
