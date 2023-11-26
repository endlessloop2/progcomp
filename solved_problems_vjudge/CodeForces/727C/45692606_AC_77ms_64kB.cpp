#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

typedef pair<int,int> ii;
typedef vector<ii> vii;

#define MP make_pair
#define INF INT_MAX-1
#define INF2 10e9

void solve();
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(7);

    solve();

    return 0;
}

void solve()
{
    int n;
    cin >> n;

    // first query for everything
    int a, b, c;

    int x, y, z; 
    // x = a + b
    // y = b + c
    // z = a + c // reemplazar aqui
    // x y z conocidos
    // a = x - b
    // c = y - b
    // z = a + c
    // z = (x - b) + (y - b)
    // z = x + y - 2b
    // z = x + y - 2b // x y z conocidos
    // z - x - y = -2b
    // -2b = z-x-y
    // 2b = -z+x+y
    // b = (x+y-z) / 2 // AAAaaa 

    // x = a + b
    // a = x - b

    // y = b + c
    // c = y - b

    cout << "? 1 2" << endl;
    cin >> x;
    cout << "? 2 3" << endl;
    cin >> y;
    cout << "? 1 3" << endl;
    cin >> z;

    b = (x + y - z) / 2;
    a = x - b;
    c = y - b;


    vector <int> new_vector = {a, b, c};
    // start from 4th element
    // ask for prev and current
    int prev_element = c, curr_sum, curr;

    for (int i = 3; i < n; i++)
    {
        // 1 indexed (+1)
        // ask for prev + current
        cout << "? " << (i+1) - 1 << " " << (i+1) << endl;
        cin >> curr_sum;
        curr = curr_sum - prev_element; // varialbe poco necesaria
        new_vector.push_back(curr); // no tan eficiente
        prev_element = curr;
    }
    

    cout << "! ";
    for (int i = 0; i < new_vector.size(); i++)
    {
        cout << new_vector[i] << " ";
    }
    cout << endl;
    
    
}