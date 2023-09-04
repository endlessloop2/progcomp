#include <bits/stdc++.h>

using namespace std;

void solve();
typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(7);

    int cases;
    cin >> cases;
    for(int i = 0; i < cases; ++i)
    {
        solve();
    }
}

void solve()
{
    int alice, bob, bWins = 0, aWins = 0;
    cin >> alice >> bob;
    //alice juega primero, el ganador del juego empieza la siguiente.
    if(alice == bob)
    {
        //cout << "0 1" << endl;
        cout << bob-1 << " " << bob;
        //return;
    }
    else if(alice > bob)
    {
        cout << alice-1 << " " << bob;
    }
    else
    {
        cout << alice-1 << " " << bob;
    }
    //cout << aWins << bWins << endl;
    cout << endl;
}