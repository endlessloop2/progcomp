#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

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
    int n, q, tmp, c=1; // marbles, queries.
    while(cin >> n >> q && (n != 0 && q != 0))
    {
        cout << "CASE# " << c << ":" << endl;
        vector<int> marbles(n);
        for (int i = 0; i < n; i++)
        {
            cin >> marbles[i];
        }
        sort(marbles.begin(), marbles.end());
        for (int i = 0; i < q; i++)
        {
            cin >> tmp;
            if(binary_search(marbles.begin(), marbles.end(), tmp))
            {
                vector<int>::iterator iterador = lower_bound(marbles.begin(), marbles.end(), tmp);
                cout << *iterador << " found at " << (iterador-marbles.begin()) + 1 << endl;
            }
            else
            {
                cout << tmp << " not found" << endl;
            }
        }
        c++;
    }
    
}
