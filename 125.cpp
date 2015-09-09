#include<vector>
#include<cmath>
#include"bigint.h"
#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	vector<long long> consecSquares;
	long lim = 1e8;
	for(int i = 1; ; i++)
	{
		long long x = 2*i*i;
		long long a = (x*i+3*i*i+i)/6;
		long long yy = 2*(i-1)*(i-1);
		long long bb = (yy*(i-1)+3*(i-1)*(i-1)+(i-1))/6;
		//cout<<i<<"\t"<<a<<"\t"<<bb<<endl;
		if(a - bb > lim)
		{
			//cout<<"stopped at \t "<<i<<endl;
			break;
		}
		//if(a > 1000000000)
		{
			//cout<<a<<"\t"<<i<<endl;
			//break;
		}
		for(int j = 0; j < i-1; j++)
		{
			long long y = 2*j*j;
			long long b = (y*j+3*j*j+j)/6;
			if(a-b < 0 )
				cout<<i<<"\t"<<j<<"\t"<<(a-b)<<"\t"<<a<<"\t"<<b<<endl;
			if(a-b < lim )
			{
				consecSquares.push_back(a-b);
				//if(i%1000 == 0)
				//cout<<i<<"\t"<<j<<"\t"<<(a-b)<<endl;
			}
		}
	}
	//cout<<consecSquares.size()<<endl;
	vector<long long> filteredcs;
	long long ans = 0;
	for(int i = 0; i < consecSquares.size(); i++)
	{
		if(BigInt(consecSquares[i]).isPalindrome())
		{
			filteredcs.push_back(consecSquares[i]);
			//ans += consecSquares[i];
			//cout<<i<<"\t"<<consecSquares[i]<<endl;
		}
	}
	std::sort(filteredcs.begin(), filteredcs.end());
	ans = filteredcs[0];
	for(int i = 1; i < filteredcs.size();i++)
	{
		if(filteredcs[i]!=filteredcs[i-1])
			ans+=filteredcs[i];
	}
		//cout<<filteredcs[i]<<endl;
	//cout<<filteredcs.size()<<endl;
	cout<<ans;
	return 0;
}
