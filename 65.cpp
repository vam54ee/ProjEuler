#include"bigint.h"
using namespace std;
int main()
{
BigInt max1;int ans=0;
BigInt num('0'),den('1'),num1;

for(int i=33;i>0;i--)
{
//cout<<num<<"\t"<<den<<endl;

BigInt tmp=num;
num=den;
//den=(den*'2')+tmp;
den=tmp+den;

tmp=num;
num=den;
//den=(den*'2')+tmp;
den=tmp+(den*BigInt(2*i));

tmp=num;
num=den;
//den=(den*'2')+tmp;
den=tmp+den;
cout<<tmp<<"\t"<<num<<"\t"<<den<<endl;
}
num1=num+(den*('2'));
cout<<num1<<endl;

num1=num1.sumOfDigits();
  cout<<num1;
return 0;
}
