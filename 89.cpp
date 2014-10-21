#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	ifstream fin("89.txt");
	string s;
	int ans=0;
	while(getline(fin,s)&&ans>=0)
	{
	for(int i=0;i<s.length()-1;i++)
	{
	//cout<<i<<"\t"<<ans<<"\t"<<s[i]<<"\t"<<s<<endl;
	if(s[i]!=s[i+1])
	continue;
	if(s[i]!=s[i+2])
	continue;
	if(s[i]!=s[i+3])
	continue;
	if(s[i]==s[i+3]&&s[i]!='M')
	{
	if(s[i]=='I'&&s[i-1]=='V')
	ans+=3;
	else if(s[i]=='I')
	ans+=2;
	if(s[i]=='X'&&s[i-1]=='L')
	ans+=3;
	else if(s[i]=='X')
	ans+=2;
	if(s[i]=='C'&&s[i-1]=='D')
	ans+=3;
	else if(s[i]=='C')
	ans+=2;
	
	}//cout<<i<<"\t"<<ans<<"\t"<<s<<endl;
	
	}
	cout<<ans<<"\t"<<s<<endl;
	}
	fin.close();
	return 0;
}
