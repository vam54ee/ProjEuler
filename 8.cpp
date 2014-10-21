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
	ifstream fin("num8.txt");
	char s[]="7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	long long int max=0,product=7*3*1*6*7*1*7*6*5*3*1*3*3;
	for(int i=14;i+12<1000;i++)
	{
	
	product=1;
	for(int j=i;j<i+13;j++)
	{
	product*=(s[j]-'0');
	//cout<<(s[j]-'0');
	}
	
	if(product>max)
	max=product;
	//cout<<i<<"\t";
	cout<<product<<endl;
	}
	cout<<max;
	fin.close();
	return 0;
}
