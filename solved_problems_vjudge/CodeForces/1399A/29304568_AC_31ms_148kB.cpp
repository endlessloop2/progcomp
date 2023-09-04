#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
void solve();
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);

    int c;
    cin >> c;
    while(--c + 1)
    {
        solve();
    }
    return 0;
}

void solve() 
{
    int n;
    cin >> n;

    vector<int> v(n,0);

    for(int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());

    for(int i = 1; i < v.size(); ++i)
    {
        if(v[i] - v[i-1] <= 1) 
        {
            //v[i-1] = v[i];
            //v[i] = -1;
            //da igual v[i] ya no se usa
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
        
    }
    cout << "YES" << endl;
}