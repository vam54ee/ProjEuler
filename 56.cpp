#include"bigint.h"
using namespace std;
int main()
{BigInt max1;
  for(int i=10;i<100;i++)
  for(int j=10;j<100;j++)
  {
    BigInt b(i),c=b.power(j);
    if(max1<c.sumOfDigits())
    max1=c.sumOfDigits();
    cout<<i<<"\t"<<j<<"\t"<<c.sumOfDigits()<<"\t"<<max1<<"\t"<<(max1<c.sumOfDigits())<<endl;
  }
  cout<<max1;
return 0;
}
