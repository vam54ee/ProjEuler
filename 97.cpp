#include"bigint.h"
using namespace std;
//BigInt power(BigInt b,int p)
//{
//  if(b.noOfDigits()>10)
//  {
//    b.removeOtherThan(b.noOfDigits()-10,10);
//  }
//  if(p==0)
//    return BigInt('1');
//    if(p==1)
//    return b;
//    if(p==2)
//    return (b)*(b);
//    if(p%2==0)
//    return power(power(b,2),p/2);
//    else
//    return b*(power(b,p-1));
//    
//
//}
int main()
{
  BigInt b("2"),c,d("28433");
  c=b.limitPower(7830457,10);
  c=c*d;
  c=c+1;
  if(c.noOfDigits()>10)
  {
    c.removeOtherThan(c.noOfDigits()-10,10);
  }
 
  cout<<c;
  //c.reverseInit();
  //c=b.sumOfDigits();
  
  
  return 0;
}
