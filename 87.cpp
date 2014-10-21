#include"bigint.h"
#include<algorithm>
using namespace std;
int main()
{int size=1000;
string ck="50000000";
  int *b=new int[size],ans=0;
BigInt *c=new BigInt[size],d(ck);
int sz=4;
b[0]=2,b[1]=3,b[2]=5,b[3]=7;
c[0]=BigInt(2),c[1]=BigInt(3),c[2]=BigInt(5),c[3]=BigInt(7);
for(int i=11;i<=7071;i++)
{int x=1;
  for(int j=0;j<sz;j++)
  {//cout<<i<<"\t"<<j<<"\t"<<sz<<endl;
   
    if(i%b[j]==0)
    x=0;
  }
  if(x)
  {b[sz]=i;
  c[sz++]=BigInt(i);
  }
}
//{
//int x,y,z;
//  for(int i=sz-1;i>=0;i--)
//  {
//    if(c[i].power(2)<d)
//    {
//      x=i;break;
//    }
//  }
//  for(int i=sz-1;i>=0;i--)
//  {
//    if(c[i].power(3)<d)
//    {
//      y=i;break;
//    }
//  }
//  for(int i=sz-1;i>=0;i--)
//  {
//    if(c[i].power(4)<d)
//    {
//      z=i;break;
//    }
//  }
//  cout<<x<<"\t"<<y<<"\t"<<z<<"\t"<<endl;
//  for(int i=x;i>=0;i--)
//  {
//    for(int j=y;j>=0;j--)
//  {
//    for(int k=z;k>=0;k--)
//  { BigInt e=c[i].power(2)+c[j].power(3)+c[k].power(4);
//   cout<<e<<"\t"<<c[i]<<"\t"<<c[j]<<"\t"<<c[k]<<endl;
//    if(e<d)
//    {ans+=(k+1);cout<<(k+1)<<endl;break;}
//    
//  } 
//  }  
//  }
//}
  
  for(int i=0;i<sz;i++)
  {
    for(int j=0;j<sz;j++)
  {
    for(int k=0;k<sz;k++)
  { BigInt e=c[i].power(2)+c[j].power(3)+c[k].power(4);
   cout<<e<<"\t"<<c[i]<<"\t"<<c[j]<<"\t"<<c[k]<<endl;
    if(e<d)
    {ans++;cout<<(k+1)<<endl;}
    else break;
    
  } 
  }  
  }
  cout<<ans;
  return 0;
}
