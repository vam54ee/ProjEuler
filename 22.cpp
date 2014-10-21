#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
using namespace std;
string sarr[6000];


void swap(string& a,string& b)
{
     string temp=b;
     b=a;
     a=temp;
 }


void heapify(string* array,int length=10,int index=1)
{
int left=2*index;
int right=left+1;
int max=index;
//cout<<array[left]<<endl;
     if(right<length)
  { if(strcmp(array[left].c_str(),array[index].c_str())>0||strcmp(array[right].c_str(),array[index].c_str())>0)
   {max=(strcmp(array[index].c_str(),array[left].c_str())>0)?(strcmp(array[index].c_str(),array[right].c_str())>0?index:right):(array[left]>array[right]?left:right);
   if(max!=index)
   {swap(array[max],array[index]);
   heapify(array,length,max);
   }//cout<<((array[2*index]==array[index])?2*index:2*index+1)<<endl;
   }  }
   else if(left<length)
   if(strcmp(array[left].c_str(),array[index].c_str())>0)
   {//cout<<array[left]<<endl;
   swap(array[left],array[index]);
   //heapify(array,length,2*index);
   }
 }
 void buildheap(string* array,int length)
 {for(int i=length-1;i>0;i--)
{heapify(array,length,i);}

  } 
  void heapsort(string* array,int length)
  {
       buildheap(array,length);
       for(int i=length-1;i>1;i--)
       {swap(array[i],array[1]);
       heapify(array,i,1);
   }}



int main()
{
	ifstream fin("names.txt");
	string s;
	getline(fin,s);
	int size=1;
	for(int i=1;i<s.length();)
	for(int j=i+1;j<s.length();j++)
	{//cout<<i<<"\t"<<s[j]<<"\t"<<j<<endl;
	if(s[j]==',')
	{
	sarr[size++]=s.substr(i,j-i-1);
	i=j+2;
	break;
	//cout<<i<<"\t"<<j<<endl;
	}
	if(j==s.length()-1)
	{
	sarr[size++]=s.substr(i,j-i);
	i=j+2;
	break;
	}
	
	}
	heapsort(sarr,size);
	long long int sum=0;
	for(int i=1;i<size;i++)
	{int x=0;
	for(int j=0;j<sarr[i].length();j++)
	{
	x+=sarr[i][j]-'A'+1;
	}
	cout<<sarr[i]<<"\t"<<x<<endl;
	sum+=x*i;
	}
	//cout<<sarr[938]<<endl;
	cout<<sum;
	fin.close();
	return 0;
}
