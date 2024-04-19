//tu 1 -> n co bao nhieu so nguyen to
#include <iostream>
#include <math.h>

using namespace std;

long long DensityOfPrimes(long long n){
    return n/log(n);
}
int main(){
    long long n, result = 0;
    cout<<"Enter integer n: ";
    cin>>n;

    result = DensityOfPrimes(n);
    cout <<"The density of prime numbers is approximately: " << result << endl;
    return 0;
}