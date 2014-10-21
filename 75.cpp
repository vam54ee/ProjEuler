#include"bigint.h"
#include<cmath>
using namespace std;
int main()
{int x=0,size=1500001,*a=new int[size],ans=0;
for(int i=0;i<size;i++)
a[i]=0;
 for(int i=1;i<size;i++)
{
for(int j=i;sqrt(i*i+j*j)<size;j++)
{
  int m=sqrt(i*i+j*j);
  if(m==1.0*sqrt(i*i+j*j))
  if(i+j+m<size)
  {cout<<i<<"\t"<<j<<"\t"<<m<<"\t"<<i+j+m<<endl;a[i+j+m]++;}
}
}
for(int i=0;i<size;i++)
{//cout<<a[i]<<endl;
if(a[i]==1)
ans++;
}
cout<<ans;

  return 0;
}
