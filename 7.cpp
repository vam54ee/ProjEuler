#include<iostream>
#include<fstream>
using namespace std;
int main()
{
int j=3;
int size=10003;
int *b=new int[size];
b[0]=1;
b[1]=2;b[2]=3;
 ofstream myfile;
  myfile.open ("7.txt");
 for(int i=5;j<=size;i+=2)
 {int x=1;
 for(int c=1;c<j;c++)
 if(i%b[c]==0)
 x=0;
 if(x)
 {b[j]=i;j++;}
 }
 for(int i=1;i<j;i++)
  myfile<<b[i]<<"\r\n";
 
  myfile.close();
 

cout<<b[10001];
    return 0;
}
