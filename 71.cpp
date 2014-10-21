#include"bigint.h"
#include<cmath>
#define max(a,b) (a>b)?a:b
using namespace std;
int size=1000000;
double *arr=new double[5*size];
int *narr=new int[5*size];

void swap(double& a,double& b)
{
     double temp=b;
     b=a;
     a=temp;
 }
void swap(int& a,int& b)
{
     int temp=b;
     b=a;
     a=temp;
 }


void heapify(double* array,int length=10,int index=1)
{
int left=2*index;
int right=left+1;
int max=index;
//cout<<array[left]<<endl;
     if(right<length)
  { if(array[left]>array[index]||array[right]>array[index])
   {max=(array[index]>array[left])?(array[index]>array[right]?index:right):(array[left]>array[right]?left:right);
   if(max!=index)
   {swap(array[max],array[index]);swap(narr[max],narr[index]);
   heapify(array,length,max);
   }//cout<<((array[2*index]==array[index])?2*index:2*index+1)<<endl;
   }  }
   else if(left<length)
   if(array[left]>array[index])
   {//cout<<array[left]<<endl;
   swap(array[left],array[index]);swap(narr[left],narr[index]);
   //heapify(array,length,2*index);
   }
 }
 void buildheap(double* array,int length)
 {for(int i=length-1;i>0;i--)
{heapify(array,length,i);}

  } 
  void heapsort(double* array,int length)
  {
       buildheap(array,length);
       for(int i=length-1;i>1;i--)
       {swap(array[i],array[1]);swap(narr[i],narr[1]);
       heapify(array,i,1);
   }}
/* int main()
{
//int* arr=new int[10];
int arr[11]={0,4,1,3,2,16,9,10,14,8,7};
//for(int i=0;i<10;i++)
//{arr[i]=i;cout<<arr[i]<<"\t";}
//cout<<endl;
heapsort(arr,11);
for(int i=1;i<11;i++)
{cout<<arr[i]<<"\t";}
cout<<endl;
    system("pause");
    return 0;
}
 */



int gcd(int a,int b)
{
  if(a%b==0)
  return b;
return gcd(b,a%b);
}
int main()
{
int j=2;
arr[1]=3.0/7;
narr[1]=3;
for(int i=2;i<=size;i++)
{if(1*1.0/i<3.0/7)
  {narr[j]=1;
  arr[j++]=1.0/i;
  cout<<1<<"\t"<<i<<"\t"<<1.0/i<<endl;
  break;}

}
for(int i=2;i<=size;i++)
{int k=ceil(i*7.0/3);
if(k>size)
	break;
//cout<<i*1.0/k<<"\t"<<3.0/7<<endl;
 // for(;k<=size;k++)
  //{ 
     
   // if(k%i!=0&&gcd(k,i)==1&&i*1.0/k<=3.0/7)
    //{
if (i==3)
	continue;
     narr[j]=i;
	 arr[j++]=i*1.0/k;
      cout<<i<<"\t"<<k<<"\t"<<i*1.0/k<<endl;
      //break;
      
    //}
  //}
}
heapsort(arr,j);
//for(int i=0;i<j;i++)
//if(arr[i]==3.0/7)
//{cout<<arr[i-1]<<"\t"<<narr[i-1]<<"\t"<<narr[j-2]<<"\t"<<narr[j-1];break;}
cout<<narr[j-2]<<"\t"<<arr[j-2]<<endl;  
  return 0;
}
