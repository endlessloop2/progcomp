#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;//perdido
    long long p = 0;
    cin >> n >> m; // N: nro de tamaños de pintura, M: nro de colores requeridos
    multiset<long long> s1;

    int tmp;
    while(1 + --n)
    {
        cin >> tmp;
        s1.insert(tmp);
    }
    while(1 + --m)
    {
        cin >> tmp;
        //s2.insert(tmp);
        long long tarro = *s1.lower_bound(tmp);
        //s1.erase(s1.lower_bound(tmp));
        p += abs(tmp - tarro);
    }
    cout << p << endl;
}