//tich cac uoc so = bao nhieu

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

long long productOfFactors(long long n, map<long long,int>& factors)
{
    long long count = countDivisor(n, factors);
    return pow(n, count/2);
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
    cout<<"Product of factors is "<<productOfFactors(n, factors);
    
    return 0;
}