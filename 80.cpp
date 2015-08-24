#include<iostream>
#include"bigint.h"
#include<math.h>
using namespace std;
BigInt sqroot(int num)
{
	string root = "";
	int xx = floor(sqrt(num*1.0));
	BigInt x = BigInt(xx);
	int rem = num - xx*xx;
	BigInt y = BigInt(xx*2);
	BigInt remainder = BigInt(rem);
	BigInt hun = BigInt(100);
	BigInt ten = BigInt(10);
	for(int i = 0; i < 99; i++)
	{
		//cout<<i<<"\t"<<remainder<<"\t"<<x<<"\t"<<y<<"\t"<<endl;
		remainder = remainder*hun;
		BigInt arr[] = {'0','1','2','3','4','5','6','7','8','9'};
		int j;
		//cout<<remainder<<"\t"<<x<<"\t"<<y<<"\t"<<endl;
		
		for( j = 0; j < 10; j++)
		{
			BigInt tmp = (y*ten+arr[j])*arr[j];
			if(tmp > remainder)
			{
				j--;
				break;
			}
		}
		if(j == 10)
		j=9;
		//cout<<remainder<<"\t"<<x<<"\t"<<y<<"\t"<<j<<"\t"<<endl;
		
		x = x*ten+arr[j];
		//cout<<remainder<<"\t"<<x<<"\t"<<y<<"\t"<<j<<"\t"<<endl;
		remainder = remainder - (y*ten+arr[j])*arr[j];
		y = x*BigInt('2');
		//cout<<remainder<<"\t"<<x<<"\t"<<x<<"\t"<<endl;
		
	}
	return x;
}

int main()
{
	BigInt x = BigInt("105527215600");
	BigInt y = BigInt("10");
	//BigInt z = sqroot(2);
//cout<<z<<endl<<z.sumOfDigits()<<endl;
BigInt ans = BigInt('0');
for(int i = 2; i < 100; i++)
{
	if(sqrt(i*1.0) != floor(sqrt(i*1.0)))
	{
		BigInt tmp = sqroot(BigInt(i));
		//cout<<i<<"\t"<<tmp.sumOfDigits()<<endl<<tmp<<endl;
		ans+= tmp.sumOfDigits();
	}
}
cout<<ans;
    return 0;
}
