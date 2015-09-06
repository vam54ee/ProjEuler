#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;
//293.js 293.cpp both together produce the result

vector<int> generateSieve(int lim)
{
   vector<bool> primes (lim/2,true);
    vector<int> finalPrimes;
   finalPrimes.push_back(2);
   primes[0]=0;
   //cout<<primes;
  
  for(int i = 3; i < lim/2; i+=2)
  {
    for(int j= 3; i*j < lim; j+=2)
    {
      primes[i*j/2] = false;
    }
    
    //for(;primes[i] === 0;i+=2);
    //console.log(i);
	if(i%1000000 == 0)
  cout<<i<<endl;
  }
  cout<<"done"<<endl;
  for (int i = 1; i < lim/2;i++)
  {
    if(primes[i])
		finalPrimes.push_back(2*i+1);
	if(i%1000000 == 0)
  cout<<i<<endl;
  }
  cout<<"done with final primes with length "<<finalPrimes.size();
  return finalPrimes; 
}



int binarySearch(int value,vector<int>arr,char* type)
{
  int start = 0;
  int end = arr.size() - 1;
  if(arr[start] == value)
    return start;
  if(arr[end] == value)
    return end;

int i,j;
  for(i = start, j = end; i < j; )
  {
    int mid = (i+j)/2;
    if(arr[mid] == value)
      return mid;
    if(j-i == 1)
    {
      return (strcmp(type,"left") == 0)?i:(strcmp(type,"right") == 0)?j:-1;
    }
    if(arr[mid] > value)
      j = mid;
    else
      i = mid;
  }
  return (strcmp(type,"left") == 0)?i:(strcmp(type,"right") == 0)?j:-1;
}




int main()
{
	int lim = 1000000000;
	
	vector<bool> x(lim/2,false);
	vector<int> y;

	/* for(int i = 1; pow(2*1.0,i*1.0) < lim; i++)
	{
		x[(int)pow(2.0,i*1.0)/2] = true;
		y.push_back((int)pow(2.0,i*1.0));
	}
	cout<<"done with 2 powers"<<endl;

    int casualPrimes[10]={2,3,5,7,11,13,17,19,23,25};
	for(int product = casualPrimes[1], i = 1; product < lim/2;i++,product *= casualPrimes[i])
	{
	  for(int j = 0; j < y.size() ; j++)
	  {
		  //if(i == 1)
		  //cout<<"finding x and y "<<i<<"\t"<<j<<"\t"<<product<<"\t"<<y[j]<<"\t"<<product*y[j]<<"\t"<<(product*y[j] <= lim)<<"\t"<<(product*y[j] > 0)<<"\t"<<y.size()<<endl;
		if(product*y[j] <= lim && product*y[j] > 0)
		{
			if(i == 2 && y.size() < 650)
			cout<<"finding x and y "<<i<<"\t"<<j<<"\t"<<product<<"\t"<<y[j]<<"\t"<<product*y[j]<<"\t"<<(product*y[j] <= lim)<<"\t"<<(product*y[j] > 0)<<"\t"<<y.size()<<endl;
		  x[product*y[j]/2] = true;
		  y.push_back(product*y[j]);
		 // cout<<"finding x and y "<<i<<"\t"<<j<<"\t"<<product*y[j]<<"\t"<<y.size()<<endl;
		}
		//console.log(j,product,y.length);
	  }
	  cout<<y.size()<<endl;
	}
	cout<<"done with x and y"<<endl;
	sort(y.begin(),y.end()); */

	vector<int> admissible = y;

	/* for(int i = 0; i < x.size(); i++)
	{
	  if(x[i])
		admissible.push_back(2*i);
	} */
	
	string line;
	 ifstream myfile ("admissible.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
		int num = 0;
      for(int i = 0; i < line.length();i++)
	  {
		  num = (num*10)+(line[i]-'0');
	  }
	  //cout<<num<<endl;
	  admissible.push_back(num);
    }
    myfile.close();
  }
	
	
cout<<admissible.size();
	
vector<int> finalPrimes(generateSieve(lim));
	 /* ofstream myfile;
  myfile.open ("sieve.txt");
  int ct = 0;
	 for(std::vector<int>::iterator it = finalPrimes.begin(); it != finalPrimes.end(); ++it,++ct) {
		myfile<<*it<<"\r\n";
		if(ct%1000000 == 0 || ct == 100 || ct ==1000 || ct == 10000)
			cout<<ct<<endl;
	}  */
	cout<<"back to main after sieve"<<endl;
	
	int ans = 0,adSize = admissible.size();
	vector<bool> unique(10000,false);
	
	for(int i = 0,j=0; i < adSize; )
	{
		if (finalPrimes[j] - admissible[i] > 1)
		{
			if(unique[(finalPrimes[j] - admissible[i])] == false)
			{
				ans+=(finalPrimes[j]-admissible[i]);
				unique[(finalPrimes[j] - admissible[i])] = true;
			}
			//cout<<i<<"\t"<<j<<"\t"<<admissible[i]<<"\t"<<finalPrimes[j]<<"\t"<<ans<<endl;
			i++;
		}
		else j++;
		//if(j%1000000 == 0|| j== 10 || j == 100 || j == 1000 || j == 10000)
			if(j < 200)
		cout<<i<<"\t"<<j<<"\t"<<admissible[i]<<"\t"<<finalPrimes[j]<<"\t"<<ans<<endl;
	  //ans += (finalPrimes[binarySearch(admissible[i],finalPrimes,"right")] - admissible[i]);
	  //cout<<finalPrimes[binarySearch(admissible[i],finalPrimes,"right")]<<"\t"<<admissible[i]<<endl;
	}
	cout<<ans;

	//console.log(admissible,admissible.length,ans); */


	return 0;
}
