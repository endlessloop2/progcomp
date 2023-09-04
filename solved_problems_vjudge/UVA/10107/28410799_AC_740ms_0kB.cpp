#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    ll tmp;
    vector<ll> vec;
    for(int i = 0; cin >> tmp; ++i)
    {
        int c = i+1;
        vec.push_back(tmp);
        if(c == 1)
        {
            cout << tmp << endl;
            continue;
        }

        sort(vec.begin(), vec.end());
        if(c % 2 == 1) cout << vec[ceil( (c/2) )] << endl;
        else cout << (vec[(c/2) - 1] + vec[c/2]) / 2 << endl;
        
    }
}