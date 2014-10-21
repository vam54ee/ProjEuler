#include"bigint.h"
using namespace std;
BigInt b[568];
int size=568;
int main()
{
for(int i=1;i<size;i++)
{cout<<i<<"\t"<<b[i]<<endl;
if(b[i]==BigInt('1')||b[i]==BigInt(89))
continue;
BigInt tmp=BigInt(i);
if(tmp.sumOfDigits(2)==BigInt('1'))
{b[i]=BigInt('1');continue;}
if(tmp.sumOfDigits(2)==BigInt(89))
{b[i]=89;;continue;}
BigInt bi,j(i),k;
for(;1;j=j.sumOfDigits(2))
{
//cout<<j<<endl;
if(b[j]==BigInt('1'))
{bi='1';break;}
if(b[j]==BigInt(89))
{bi=89;break;}
if(BigInt(j).sumOfDigits(2)==BigInt('1'))
{bi='1';break;}
if(BigInt(j).sumOfDigits(2)==BigInt(89))
{bi=89;break;}
}
 for(BigInt k(i);k!=j;k=k.sumOfDigits(2))
{

b[k]=bi;
}
b[j]=bi;
cout<<i<<"\t"<<b[i]<<endl;}
int ans=0;
for(int i=0;i<10000000;i++)
{cout<<i<<endl;
BigInt ck(i),dd=ck.sumOfDigits(2);
if(b[dd]==BigInt(89))
ans++;
} cout<<ans;
 return 0;
}
