#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
// solution is in this url. But when will you find solutions like this asshole.
// http://math.stackexchange.com/questions/1218821/find-all-prime-triples-a-b-c-such-a1-b1-c1-form-a-geometric-sequence
vector<long long> generateIsPrimeArrayAndSieve(long long size, vector<bool>& primes)
{
  primes = vector<bool>(size+1, false);
  vector<long long> finalPrimes;
  primes[2] = true;
  primes[3] = true;
  primes[5] = true;
  primes[7] = true;
  for(long long i = 8; i < size; i++)
  {
    if(i%2 == 1)
      primes[i] = true;
    else
      primes[i] = false;
  }

  for(long long i = 3; i < size/2; i+=2)
  {
    for(long long j= 3; i*j < size; j+=2)
    {
      primes[i*j] = false;
    }
  }
  cout<<"done"<<endl;
  for (long long i = 0; i < size+1;i++)
  {
    if(primes[i] == true)
      finalPrimes.push_back(i);
  }
  cout<<"done with final primes with length"<<finalPrimes.size()<<endl;
  return finalPrimes;
}

int main() {
  long long n = 100000000;
  long long ans = 0;
  vector <bool> primes;
  vector<long long> finalPrimes = generateIsPrimeArrayAndSieve(n, primes);
  for(long long i = 0; i < finalPrimes.size(); i++) {
    long long b ;
    for (b = ceil(sqrt(finalPrimes[i] + 1)); b > 0; b--) {
      if((finalPrimes[i] + 1) % (b*b) == 0) break;
    }
    for (long long a = b + 1; a < b*sqrt(1.0*(n+1)/(finalPrimes[i] + 1)); a++) {
      long long p = finalPrimes[i];
      double k = a*1.0/b;
      long long middle = round((p+1)*k - 1), last = round((p+1)*k*k - 1);
      // cout<<a<<"\t"<<b<<"\t"<<k<<"\t"<<p<<"\t"<<middle<<"\t"<<last<<"\t"<<primes[middle]<<"\t"<<primes[last]<<endl;
      if(primes[middle] && primes[last]) {
        cout<<p<<"\t"<<middle<<"\t"<<last<<endl;
        ans += (p + middle + last);
      }
    }
  }
  cout<<ans<<endl;

  return 0;
}
