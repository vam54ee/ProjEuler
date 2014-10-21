#include"bigint.h"
#include<algorithm>
using namespace std;
int main()
{BigInt b,max1;
for(int i=1;i<=1000;i++)
{
  for(int j=1;j<=1000;j++)
  {b=i*(i+1)*j*(j+1)/4;
    if(b>BigInt("2000000"))
    break;
    if(max1<b)
    {max1=b;cout<<i<<"\t"<<j<<"\t"<<b<<endl;}
    
  }
}

  return 0;
}
