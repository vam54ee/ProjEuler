#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include"bigint.h"
using namespace std;
BigInt **arr=new BigInt*[101];
	BigInt max1(BigInt a,BigInt b)
	{
	if(a>b)
	return a;
	return b;
	}
BigInt calc()
{
for(int i=99;i>=1;i--)
{
for(int j=0;j<i;j++)
{
arr[i][j]+=max1(arr[i+1][j],arr[i+1][j+1]);
cout<<i<<"\t"<<j<<endl;
}
}
return arr[1][0];
}

int main()
{
	ifstream fin("67.txt");
	string s;
	BigInt ans=97;
	for(int i=1;i<101;i++)
	arr[i]=new BigInt[100];
	for(int i=1;i<101&&getline(fin,s);i++)
	{
	for(int j=0;j<i;j++)
	{
	arr[i][j]=BigInt(s.substr(j*3,2));
	}
	//cout<<ans<<"\t"<<arr[i][0]<<endl;
	}
	/* for(int j=0;j<100;j++)
	if(arr[100][j]>60&&arr[100][j]<=70)
	{ans=arr[100][j];
	int ref=81;
	for(int i=99;i>0;i--)
	{
	if(arr[i][ref]>arr[i][ref-1])
	ans+=arr[i][ref];
	else
	{
	ans+=arr[i][ref-1];
	ref=ref-1;
	}
	//cout<<arr[i][ref]<<endl;
	}
	
	 //cout<<arr[100][ref]<<endl;
	cout<<ans<<endl;
	}
	 */
	 BigInt b=calc();
	 cout<<b;
	 fin.close();
	return 0;
}
