#include"bigint.h"
#include<cmath>
#include<fstream>
using namespace std;
bool is(BigInt ck,BigInt ck1)
{
if(ck._s[0]=='1'&&ck._s[2]=='2'&&ck._s[4]=='3'&&ck._s[6]=='4'&&ck._s[8]=='5'&&ck._s[10]=='6'&&ck._s[12]=='7')
cout<<ck._s[0]<<ck._s[2]<<ck._s[4]<<ck._s[6]<<ck._s[8]<<ck._s[10]<<ck._s[12]<<ck._s[14]<<ck._s[16]<<ck._s[18]<<endl<<ck1<<endl;
if(ck._s[0]=='1'&&ck._s[2]=='2'&&ck._s[4]=='3'&&ck._s[6]=='4'&&ck._s[8]=='5'&&ck._s[10]=='6'&&ck._s[12]=='7'&&ck._s[14]=='8'&&ck._s[16]=='9'&&ck._s[18]=='0')
{return true;}
return false;
}
int main()
{ 
for(BigInt a("1000000030"),b;(b=a.power(2))<BigInt("2000000000000000000");)
{
//cout<<a<<endl;
if(is(b,a))
{cout<<a;break;}
if(a._s[8]=='3')
a+=40;
else if(a._s[8]=='7')
a+=60;
 }   
	return 0;
}
