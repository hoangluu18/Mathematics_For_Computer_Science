// sang nguyen to va tim so luong, liet ke trong doan

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

int countPrime(int left, int right)
{
    int count = 0;
    for (int i = left; i <= right; i++)
    {
        if (nt[i] == true)
            count++;
    }
    return count;
}

void listPrime(int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        if (nt[i] == true)
            cout << i << " ";
    }
}
int main()
{
    sieve();
    int left, right;
    cout << "Enter left and right: ";
    cin >> left >> right;

    if (left > right)
    {
        cout << "Invalid input!";
        return 0;
    }
    if (left < 0 || right < 0)
    {
        cout << "Invalid input!";
        return 0;
    }
    cout << "Number of prime numbers in the range [" << left << "," << right << "] is: " << countPrime(left, right);
    cout << "\nList of prime numbers in the range [" << left << "," << right << "] is: \n";
    listPrime(left, right);

    return 0;
}