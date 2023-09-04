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

void bubblesort(vector<int> &v)
{
    for (int i = 0; i < v.size()-1; i++)
    {
        for (int j = 0; j < v.size()-1-i; j++)
        {
            if(v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
                for (int k = 0; k < 5; k++)
                {
                    cout << v[k] << " ";
                }
                cout << endl;
            }
                
        }
        
    }
    
}

void solve() 
{
    vector<int> v(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> v[i];
    }
    bubblesort(v);
    
}
