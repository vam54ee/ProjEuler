#include"bigint.h"
#include<fstream>
#include<cmath>
using namespace std;
bool ispan(BigInt b,int c)
{cout<<c<<endl;
	int a[]={0,0,0,0,0,0,0,0,0,0};
	for(int i=0;i<9;i++)
	{//cout<<(b[i]-'0')<<"\t"<<(b[b.noOfDigits()-i-1]-'0')<<endl;
		a[b[i]-'0']++;
		a[b[b.noOfDigits()-i-1]-'0']++;
	}
	for(int i=1;i<=9;i++)
	{//cout<<a[i]<<"\t";
		if(a[i]!=2)
			return false;
	}
	cout<<c;
	return true;
}

int main()
{int k=3;
//cout<<ispan(BigInt("53624187921649849845963245187"),5);
for(BigInt i='1',j='2';!ispan(j,k);k++)
{
	BigInt tmp=i;
	i=j;
	j=j+tmp;
}
	return 0;
}
