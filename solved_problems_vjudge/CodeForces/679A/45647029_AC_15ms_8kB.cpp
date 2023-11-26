#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

typedef pair<int,int> ii;
typedef vector<ii> vii;

#define MP make_pair
#define INF INT_MAX-1
#define INF2 10e9

void solve();
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(7);

    solve();

    return 0;
}

void solve()
{
    // los primos parten en 2,
    // 2 x lo q sea mayor a 50 excedera 100
    vector<int> prime_factors = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 49};
    // creo q solo es necesario el caso del 4
    //vector<int> prime_factors = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4};
    // si es posible dividir el numero en 2 de estos, entonces es compuesto
    // el 4 se divide 2 veces?
    // reivsar los primos al cuadrado, pero solo bajo 100
    // 2(4), 3(9), 5(25), 7 (49), 11 (121), // esos serian casos de compuestos que se dividen 2 veces
    // pueden afectar a otros casos? revisar // el problema seria para si se verifica si 4, 9, 25, 49 son primos

    bool flag = 0;
    string response;
    for (int i = 0; i < prime_factors.size(); i++)
    {
        cout << prime_factors[i] << endl; // endl tiene flush
        cin >> response;
        if (!flag && response == "yes")
        {
            flag = 1;
            continue;
        }
        if(flag && response == "yes")
        {
            cout << "composite" << endl;
            return;
        }
    }
    
    cout << "prime" << endl;
}