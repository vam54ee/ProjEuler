#include<iostream>
#include<fstream>
using namespace std;
int main()
{
int j=0;
int b[8]={0,0,0,0,0,0,0,0};
int a=999,c=999;
 ofstream myfile;
  myfile.open ("4.txt");
 for(;c>900;c--)
 for(a=999;a>900;a--)
 {int x=a*c;
 j=0;
 while(x!=0)
 {
 b[j]=x%10;
 j++;
 x=x/10;
 }
 //cout<<a*c<<endl;
 int ch=1,p=0;
 while(p<j-p-1)
 {
 //cout<<b[p]<<"\t"<<b[j-p-1]<<endl;
 if(b[p]!=b[j-p-1])
 {ch=0;break;}
 p++;
 }
 if(ch)
 myfile<<a*c<<"\t"<<a<<"\t"<<c<<"\r\n";
 }
  myfile.close();
 

cout<<j;
    return 0;
}
