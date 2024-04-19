//so luong cac uoc so nguyen to cua n liet ke chung ra

#include<iostream>
#include<map>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

void prime_factorization(long long n, map<long long,int>& factors)
{ 
  while (n % 2 == 0)
  {
    factors[2]++;
    n /= 2;
  }

  for(int i = 3; i <=sqrt(n); i+= 2)
  {
    while(n % i == 0)
    {
        factors[i]++;
        n /= i;
        
    }
  }

  if(n > 2)
  {
    factors[n]++;
  }
  
}

long long countDivisor(long long n, map<long long,int>& factors)
{
    long long count = 1;
    for(auto id : factors)
    {
        count *= (id.second + 1);
    }
    return count;
}


void listDivisor(long long n, vector<long long>& divisors)
{
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            divisors.push_back(i);
            if(i != n/i)
            {
                divisors.push_back(n/i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    
}

int main()
{
    long long n, count = 0;
    cout<<"Enter integer n: ";
    cin>>n;

    if(n < 2)
    {
        cout<<"n must be greater than 1";
        return 0;
    }
    
    map<long long, int> factors;
    prime_factorization(n, factors);
    cout<<"Number of divisors of "<<n<<" is "<<countDivisor(n, factors);

   vector<long long> divisors;
    listDivisor(n, divisors);
    cout<<"\nList of divisors of "<<n<<" is ";
    for(auto id : divisors)
    {
        cout<<id<<" ";
    }
    return 0;
}