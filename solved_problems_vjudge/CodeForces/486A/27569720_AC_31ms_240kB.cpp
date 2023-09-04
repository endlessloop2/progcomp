#include <iostream>
#include <math.h>
using namespace std;

long long funcionF(long long n);
int main()
{
    long long n;
    cin >> n;
    cout << funcionF(n);
}

//version v4 + cerda
//no entiendo bien pq funciona :S
long long funcionF(long long n)
{
    if(n % 2 == 0) //es par
    {
        return n/2;
    }
    //es impar
    return -(n/2) - 1;
}