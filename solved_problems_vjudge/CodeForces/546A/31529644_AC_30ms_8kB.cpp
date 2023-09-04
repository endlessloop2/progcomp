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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(7);

    solve();

    return 0;
}

void solve()
{
    int k,n,w,b=0; //1st b cost, in numb of $, n of banans buy
    cin >> k >> n >> w;

    for(int i = 0; i < w; ++i)
    {
        n-=k*(i+1);
    }
    if(n < 0) b = abs(n);
    cout << b << endl;
}