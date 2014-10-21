#include"bigint.h"
using namespace std;
int main()
{
BigInt max1;int ans=0;
BigInt num('1'),den('2'),num1;

for(int i=1;i<=1000;i++)
{
//cout<<num<<"\t"<<den<<endl;

BigInt tmp=num;
num=den;
den=(den*'2')+tmp;
num1=num+den;
//cout<<num1<<"\t"<<num<<"\t"<<den<<endl;
if(num1.noOfDigits()>den.noOfDigits())
ans++;
}

  cout<<ans;
return 0;
}
