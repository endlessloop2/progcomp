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
    int n, m, k; // size of array, num of operations, num of queries
    cin >> n >> m >> k;

    vector<ll> v;
    vector<ll> change_vector(n+1, 0);// currently subtracting one position later.
    int tmp;
    // store array
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    //operations
    int l, r, d;
    vector<vector<ll>> ops(m, vector<ll>());
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r >> d;
        ops[i].push_back(l);
        ops[i].push_back(r);
        ops[i].push_back(d);
        //ops[i].push_back(0); // the operation will be applied 0 times
    }

    // for each query, increase the times it will be applied
    vector<ll> times_operation(m+1, 0);// how many times the operation at x position will be applied
    int x, y;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        x--; // 0-indexed
        y--; // same
        times_operation[x]++;
        times_operation[y+1]--;
        // increase the times the operation will be applied
        // for (int j = x; j <= y; j++)
        // {
        //     ops[j][3]++;
        //     // l = ops[j][0], r = ops[j][1], d = ops[j][2]

        //     // apply operation j in temp vector
        //     change_vector[ops[j][0]-1] += ops[j][2];
        //     change_vector[ops[j][1]-1+1] -= ops[j][2];
        //     // O(1) !!
        // }
    }
    


    // for each operation, modify change_vector
    ll op_times = 0;
    for (int i = 0; i < ops.size(); i++)
    {
        op_times += times_operation[i];
        // l = ops[j][0], r = ops[j][1], d = ops[j][2]
        change_vector[ops[i][0]-1] += ops[i][2] * op_times;
        change_vector[ops[i][1]-1+1] -= ops[i][2] * op_times; 
    }
    

    // Apply the saved changes into the original array // O(n)
    ll current_op = 0;
    for (int i = 0; i < v.size(); i++)
    {
        current_op += change_vector[i];
        v[i] += current_op;
    }
    
    
    for(int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
}