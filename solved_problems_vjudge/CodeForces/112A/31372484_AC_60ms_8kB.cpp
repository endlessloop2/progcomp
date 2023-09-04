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
    //cout.precision(7);
    solve();
    return 0;
}

void solve() 
{
    string s1,s2;
    cin >> s1 >> s2;
    int out = 0;

    for(int i = 0; i < s1.size(); ++i)
    {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
        if(s1[i] > s2[i])
        {
            out = 1;
            break;
        }
        else if(s1[i] < s2[i])
        {
            out = -1;
            break;
        }
    }
    cout << out << endl;
}
