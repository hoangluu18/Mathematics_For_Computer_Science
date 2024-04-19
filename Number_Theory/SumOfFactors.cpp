//tong cac uoc so bang bao nhieu

#include<iostream>
#include<map>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

long long power(long long base, int exponent)
{
    long long result = 1;
    while (exponent > 0)
    {
        // Nếu số mũ là lẻ, nhân kết quả với cơ số
        if (exponent % 2 == 1)
        {
            result *= base;
        }
        // Chia số mũ cho 2 và bình phương cơ số
        exponent /= 2;
        base *= base;
    }
    return result;
}

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



long long sumOfFactors(map<long long,int>& factors)
{
    long long sum = 1;
    for(auto it : factors)
    {
        sum *= (power(it.first , it.second + 1)-1)/(it.first - 1);
    }
    return sum;
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
    cout<<"Sum of factors is "<<sumOfFactors(factors);
    return 0;
}