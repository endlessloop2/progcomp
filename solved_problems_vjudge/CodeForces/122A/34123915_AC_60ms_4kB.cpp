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


bool isAlmostLucky(int n, int div = 0)
{
    if(div != 0 && n % div == 0) return true;
    if(div != 0 && div > n) return false;

    return isAlmostLucky(n, stoi(to_string(div).append("4")) ) || isAlmostLucky(n, stoi(to_string(div).append("7")) );
}

void solve() 
{
    int n;
    cin >> n;
    isAlmostLucky(n) ? cout << "YES" : cout << "NO";
    cout << endl;
}
