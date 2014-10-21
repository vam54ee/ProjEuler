#include"bigint.h"
#include<cmath>
#include<fstream>
using namespace std;
int main()
{BigInt a[1001], b[1001];
    ifstream fin("99.txt");
	string s;
	for(int i=1;i<1001&&getline(fin,s);i++)
	{
	for(int j=0;j<s.length();j++)
	{
	if(s[j]==',')
	{
	a[i]=BigInt(s.substr(0,j));
	b[i]=BigInt(s.substr(j+1,s.length()-2-j));
	}
	}
	}
	int max1=1;
for(int i=2;i<1001;i++)
{
if(((int)b[i])*log((int)a[i])>((int)b[max1])*log((int)a[max1]))
max1=i;}
cout<<max1;
	 fin.close();
	return 0;
}
