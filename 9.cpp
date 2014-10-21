#include<iostream>
#include<fstream>
using namespace std;
int main()
{
int j=3;
int b[150000];
long long int q=5;
b[0]=1;
b[1]=2;b[2]=3;
 ofstream myfile;
  myfile.open ("9.txt");
 for(int i=5;j<=150000;i+=2)
 {int x=1;
 for(int c=1;c<j;c++)
 if(i%b[c]==0)
 x=0;
 if(x)
 {b[j]=i;j++;
 if(i<2000000)
 q+=i;
 }
 }
  for(int i=1;i<j;i++)
  myfile<<b[i]<<"\r\n";
 
  myfile.close();
 

cout<<q;
    return 0;
}
