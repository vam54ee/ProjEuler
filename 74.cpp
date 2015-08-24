#include"bigint.h"
using namespace std;
BigInt fac[]={1,1,2,6,24,120,720,5040,40320,362880};
BigInt *cka;
int ckc=0;
bool has(BigInt l)
{
for(int i=0;i<ckc;i++)
if(cka[i]==l)
return true;
return false;
}
void init()
{
ckc=0;
cka=new BigInt[65];
}
BigInt sum(BigInt num)
{
BigInt ans;
for(int i=0;i<num.noOfDigits();i++)
{
ans+=BigInt(fac[num[i]-'0']);
}
return ans;
}
int main()
{BigInt maxsz("2177290"),maxsz1("1000000");
BigInt *a=new BigInt[maxsz];
BigInt *b=new BigInt[maxsz];
for(int i=1;i<maxsz;i++)
{a[i]=sum(i);
cout<<i<<endl;}
int ans=0;
for(BigInt i=3;i<maxsz1;i+=1)
{
cout<<i<<endl;
if(b[i]!=BigInt())
continue;
init();
int cnt=0;
for(BigInt j=i;ckc<63;j=a[j],cnt++)
{
/* if(b[j]!=BigInt())
{ckc+=b[j];
ckc++;
int cntk=0;
for(BigInt k=i;cntk<cnt;k=a[k],cntk++)
{b[k]=ckc--;
cout<<ckc<<"\t"<<k<<"\t"<<j<<endl;}
break;
} */
cka[ckc++]=j;
if(has(a[j]))
{int cntk=0;
for(BigInt k=i;cntk<=cnt;k=a[k],cntk++)
{//cout<<ckc<<"\t"<<k<<"\t"<<j<<endl;
b[k]=ckc--;
if(k==a[j])
break;}
break;}
}
if(ckc>60)
b[i]=61;
}
for(int i=2;i<maxsz1;i++)
{cout<<i<<"\t"<<b[i]<<"\t"<<a[i]<<endl;
if(b[i]==BigInt("60"))
ans++;
}cout<<ans;
//cout<<sum(BigInt("1"));   
   return 0;
}
