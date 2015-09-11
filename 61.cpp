#include"bigint.h"
#include<cmath>
using namespace std;

#define max(a,b) (a>b)?a:b
void shiftRight(int* arr, int low, int high)
{
    int root = low;
    while ((root*2)+1 <= high)
    {
        int leftChild = (root * 2) + 1;
        int rightChild = leftChild + 1;
        int swapIdx = root;
        /*Check if root is less than left child*/
        if (arr[swapIdx] < arr[leftChild])
        {
            swapIdx = leftChild;
        }
        /*If right child exists check if it is less than current root*/
        if ((rightChild <= high) && (arr[swapIdx] < arr[rightChild]))
        {
            swapIdx = rightChild;
        }
        /*Make the biggest element of root, left and right child the root*/
        if (swapIdx != root)
        {
            int tmp = arr[root];
            arr[root] = arr[swapIdx];
            arr[swapIdx] = tmp;
            /*Keep shifting right and ensure that swapIdx satisfies
            heap property aka left and right child of it is smaller than
            itself*/
            root = swapIdx;
        }
        else
        {
            break;
        }
    }
    return;
}
void heapify(int* arr, int low, int high)
{
    /*Start with middle element. Middle element is chosen in
    such a way that the last element of array is either its
    left child or right child*/
    int midIdx = (high - low -1)/2;
    while (midIdx >= 0)
    {
        shiftRight(arr, midIdx, high);
        --midIdx;
    }
    return;
}
void heapSort(int* arr, int size)
{
    //assert(arr);
    //assert(size > 0);
    /*This will put max element in the index 0*/
    heapify(arr, 0, size-1);
    int high = size - 1;
    while (high > 0)
    {
        /*Swap max element with high index in the array*/
        int tmp = arr[high];
        arr[high] = arr[0];
        arr[0] = tmp;
        --high;
        /*Ensure heap property on remaining elements*/
        shiftRight(arr, 0, high);
    }
    return;
}


int search(int *arr,int sz,int ind)
{
for(int i=0;i<sz;i++)
{
if(arr[i]/100==ind)
return i;
}
return 0;
}



bool isp(double g)
{
return g==(int)g;
}


bool istr(int g)
{
double b1=(-1+sqrt(1+8*g))/2.0;
return isp(b1);
}


bool issq(int g)
{

return isp(sqrt(g));
}


bool ispe(int g)
{
double b1=(1+sqrt(1+24*g))/6.0;
return isp(b1);
}


bool ishe(int g)
{
double b1=(1+sqrt(1+8*g))/4.0;
return isp(b1);
}


bool ishep(int g)
{
double b1=(3+sqrt(9+40*g))/10.0;
return isp(b1);
}


bool isoc(int g)
{
double b1=(2+sqrt(4+12*g))/6.0;
return isp(b1);
}


void iscf(int *a)
{
int ck[]={0,0,0,0,0,0};
for(int i=0;i<6;i++)
{
if(istr(a[i]))
{
ck[0]++;
}
if(issq(a[i]))
{
ck[1]++;
}
if(ispe(a[i]))
{
ck[2]++;
}
if(ishe(a[i]))
{
ck[3]++;
}
if(ishep(a[i]))
{
ck[4]++;
}
if(isoc(a[i]))
{
ck[5]++;
}

}
//cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<a[5]<<"\t"<<(a[0]+a[1]+a[2]+a[3]+a[4]+a[5])<<endl;
//cout<<ck[0]<<ck[1]<<ck[2]<<ck[3]<<ck[4]<<ck[5]<<endl;
for(int i=0;i<6;i++)
if(ck[i]<1)
return;
cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<a[5]<<"\t"<<(a[0]+a[1]+a[2]+a[3]+a[4]+a[5])<<endl;
cout<<ck[0]<<ck[1]<<ck[2]<<ck[3]<<ck[4]<<ck[5]<<endl;
}





int main()
{
int *a=new int[600];
int num=0;
for(int i=0;;i++)
{int x=i*(i+1)/2;
if(x>9999)
break;
if(x>999)
a[num++]=x;
}

for(int i=0;;i++)
{int x=i*i;
if(x>9999)
break;
if(x>999)
a[num++]=x;
}

for(int i=0;;i++)
{int x=i*(3*i-1)/2;
if(x>9999)
break;
if(x>999)
a[num++]=x;
}

for(int i=0;;i++)
{int x=i*(2*i-1);
if(x>9999)
break;
if(x>999)
a[num++]=x;
}

for(int i=0;;i++)
{int x=i*(5*i-3)/2;
if(x>9999)
break;
if(x>999)
a[num++]=x;
}

for(int i=0;;i++)
{int x=i*(3*i-2);
if(x>9999)
break;
if(x>999)
a[num++]=x;
}
heapSort(a,num);
for(int i=0;i<num;i++)
cout<<i<<"\t"<<a[i]<<endl;


for(int i=0;i<num-6;i++)
{int ii=a[i]%100;
for(int j=search(a,num,ii);a[j]/100==ii;j++)
{int jj=a[j]%100;
for(int k=search(a,num,jj);a[k]/100==jj;k++)
{int kk=a[k]%100;
for(int l=search(a,num,kk);a[l]/100==kk;l++)
{int ll=a[l]%100;
for(int m=search(a,num,ll);a[m]/100==ll;m++)
{int mm=a[m]%100;
for(int n=search(a,num,mm);a[n]/100==mm;n++)
{
if(a[n]%100==a[i]/100)
{int an[]={a[i],a[j],a[k],a[l],a[m],a[n]};
iscf(an);
}
}
}
}
}
}
}

cout<<ishe(8128);
return 0;
}
