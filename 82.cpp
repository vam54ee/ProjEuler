#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include"bigint.h"
using namespace std;
int size=5;
BigInt **arr=new BigInt*[size];
	BigInt min1(BigInt a,BigInt b)
	{
	if(a>b)
	return b;
	return a;
	}

int main()
{
	ifstream fin("82.txt");
	string s;
	for(int i=0;i<size;i++)
	arr[i]=new BigInt[size];
	for(int i=0;i<size&&getline(fin,s);i++)
	{int k=0;
	for(int j=0;j<size&&k<s.length();k++)
	{
	for(int n=k+1;n<s.length()-1;n++)
	{//cout<<s[n]<<endl;
	if(s[n]==',')
	{arr[i][j]=BigInt(s.substr(k,n-k));j++;k=n;break;}
	}
	 //cout<<i<<"\t"
	}
	/* for(int l=s.length()-1,ll=l-1;1;ll--)
	if(s[ll]==',')
	*/
	if(s[s.length()-6]==',')
	arr[i][size-1]=BigInt(s.substr(s.length()-5,4));
	if(s[s.length()-5]==',')
	arr[i][size-1]=BigInt(s.substr(s.length()-4,3));
	if(s[s.length()-4]==',')
	arr[i][size-1]=BigInt(s.substr(s.length()-3,2));
	if(s[s.length()-3]==',')
	arr[i][size-1]=BigInt(s.substr(s.length()-2,1));
	//cout<<arr[i][size-1]<<endl;
	}
	for(int i=0;i<size;i++)
	{for(int j=0;j<size;j++)
	cout<<arr[i][j]<<"\t";
	 cout<<endl;
	 }
	for(int i=size-2;i>=0;i--)
	{
	for(int j=size-1,k=i;k<size&&j>=0;j--,k++)
	{cout<<arr[j][k]<<"\t"<<j<<"\t"<<k<<endl;
	if(j==size-1)
	arr[size-1][k]+=arr[size-1][k+1];
	else if(k==size-1)
	arr[j][size-1]+=arr[j+1][size-1];
	else
	arr[j][k]+=min1(arr[j+1][k],arr[j][k+1]);
	cout<<arr[j][k]<<endl;
	}
	}
	for(int i=size-2;i>=0;i--)
	{
	for(int j=i,k=0;k<size&&j>=0;j--,k++)
	{//cout<<j<<"\t"<<k<<endl;
	arr[j][k]+=min1(arr[j+1][k],arr[j][k+1]);
	}
	}
	 for(int i=0;i<size;i++)
	{for(int j=0;j<size;j++)
	cout<<arr[i][j]<<"\t";
	 cout<<endl;
	 }
	  cout<<arr[0][0];
	 fin.close();
	return 0;
}
