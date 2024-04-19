//thuc hienj phan ra thua so nguyen to trong do p1 p2 p3 la cac so nguyen to phan biet
#include<iostream>
#include<map>
#include<math.h>
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



int main()
{
    long long n, count = 0;
    cout<<"Enter n: ";
    cin>>n;

    if(n < 2)
    {
        cout<<"n must be greater than 1";
        return 0;
    }

    map<long long,int> factors;
    prime_factorization(n, factors);
    for(auto it : factors)
    {    
        count++;
        if(it.second > 1)
        {
            cout<<it.first<<"^"<<it.second<<" ";
        }
        else
        {
            cout<<it.first<<" ";
        }
        if(factors.size() > count )
        {
            cout<<"* ";
        }
        
    }

    return 0;
}