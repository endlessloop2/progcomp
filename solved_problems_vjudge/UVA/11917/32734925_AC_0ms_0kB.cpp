#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define MP make_pair

void solve();
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
        cout << "Case " << i+1 << ": ";
        solve();
    } 

    return 0;
}

void solve() 
{
    int n, tmp2, d; // n of subjects, tmp, time to do homework
    cin >> n;
    map<string, int> sbj;
    string tmp1;
    for(int i = 0; i < n; ++i)
    {
        cin >> tmp1 >> tmp2;
        sbj.insert(MP(tmp1, tmp2));
    }
    cin >> d >> tmp1;
    map<string,int>::iterator it = sbj.find(tmp1);
    if(it != sbj.end() && it->second <= (d+5))
    {
        (it->second <= d) ? cout << "Yesss" : cout << "Late";
        cout << "\n";
    }
    else
    {
        cout << "Do your own homework!" << "\n";
    }
}
