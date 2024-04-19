#include <iostream>
#include <math.h>

using namespace std;
const int maxn = 1000001;
bool nt[maxn];

void sieve()
{
    for (int i = 0; i <= maxn; i++)
    {
        nt[i] = true;
    }
    nt[0] = nt[1] = false;
    for (int i = 2; i <= sqrt(maxn); i++)
    {
        if (nt[i])
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                nt[j] = false;
            }
        }
    }
}

void findClosestPrime(int n)
{

    if (n <= 2)
    {
        cout << "Closest prime number is: " << 2;
        return;
    }

    if (nt[n] == true)
    {
        cout << "Closest prime number is: " << n;
        return;
    }

    int left = n - 1, right = n + 1;
    while (true)
    {
        if (nt[left] == true)
            break;
        left--;
    }
    while (true)
    {
        if (nt[right] == true)
            break;
        right++;
    }
    if (abs(n - left) < abs(n - right))
    {
        cout << "Closest prime number is: " << left;
    }
    else if (abs(n - left) > abs(n - right))
    {
        cout << "Closest prime number is: " << right;
    }
    else
    {
        cout << "Closest prime numbers are: " << left << " and " << right;
    }
}
int main()
{
    sieve();
    int n;
    cout << "Enter integer n: ";
    cin >> n;
    findClosestPrime(n);

    return 0;
}