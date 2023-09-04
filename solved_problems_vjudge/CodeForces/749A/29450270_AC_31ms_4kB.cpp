#include <bits/stdc++.h>

using namespace std;

typedef long long int li;
typedef long double ld;

typedef pair<int,int> ii;
typedef vector<ii> vii;

#define INF INT_MAX;
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(7);
    solve();
}

void solve()
{
    int n, k=0;
    cin >> n;

    if(n % 2 == 0)
    {
        cout << n/2 << endl;
        for(int i = 0; i < n/2; ++i)
        {
            cout << "2 ";
        }
    }
    else
    {
        cout << (n-1)/2 << endl;
        for(int i = 0; i < ( (n - 1) / 2) - 1; ++i)
        {
            cout << "2 ";
        }
        cout << "3 ";

    }
    cout << endl;
    
}