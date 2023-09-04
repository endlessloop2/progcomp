#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
void solve();
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);

    solve();

    return 0;
}

void solve() 
{
    int x,c=0,s=0;
    cin >> x;
    //parte en 0, llegar a X
    // 1, 2, 3, 4, 5

    while(c != x)
    {
        for(int i = 5; i > 0; --i)
        {
            if(c+i == x)
            {
                ++s;
                c+=i;
                break;
            } 
            if(c+i < x)
            {
                ++s;
                c+=i;
                break;                
            }
        }
    }
    cout << s << endl;
}