#include"bigint.h"
using namespace std;
int main()
{BigInt max1;int ans=1;
  for(int i=2;i<100;i++)
  for(int j=1;j<100;j++)
  {
    BigInt b(i),c=b.power(j);
    if(c.noOfDigits()>j)
    break;
    if(c.noOfDigits()==j)
    ans++;
    
    cout<<i<<"\t"<<j<<"\t"<<c.noOfDigits()<<endl;
  }
  cout<<ans;
return 0;
}
