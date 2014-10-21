#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
using namespace std;
long long int a[10];
int main()
{a[0]=0;a[1]=1;
for(long long int i=2;i<10;i++)
a[i]=(int)pow(i,5);
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
