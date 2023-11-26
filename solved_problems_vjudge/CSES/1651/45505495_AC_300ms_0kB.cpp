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

// Test implementation of Segment Tree with point query and lazy range updates
// Credits to cp-algorithms for most of the algorithm

struct SegmentTree
{
    vector<ll> ST;
    int N; // the size of the original vector

    SegmentTree(vector<ll> &v)
    {
        N = v.size();
        ST.resize(N*4);
        build(1, 0, N - 1, v);
    }

    // we store at each vertex in the Segment Tree how many we should add to all numbers in the corresponding segment!!!!
    // we need to build starting from a certain node, in this case it will be the top node that will be set after all the recursive
    // calls are done
    void build(int node, int ls, int rs, vector<ll> &v)
    {
        // cout << "a" << endl;
        // divide and conquer topdown recursion
        // base case: the segment is a single value in the vector, it is a leaf in ST[]
        if(ls == rs)
        {
            // ls or rs is the location in the original vector
            ST[node] = v[ls];// store the value of the array at that pos
            return;
        }


        int mid = (ls + rs) / 2;
        // find the sum of the left child (first half of the current segment in original array) stored in ST[2*node]
        build(2*node, ls, mid, v);

        // right child sum (2nd half of the current segment in original array) (stored in ST[2*node+1])
        build((2*node)+1, mid+1, rs, v);

        // understand better
        ST[node] = 0; // nothing to add to that node. if it is not a leaf that will have its value stored
    }

    // go from the parent segment until you find the node,
    // adding the values to add found
    ll point_value_query(int current_node, int ls, int rs, int point_q)
    {
        // c1 (base): it is the same segment
        if(ls == rs && rs == point_q)
        {
            return ST[current_node]; // returns the value to add there
        }

        // c2: it is contained in a child subsegment
        int mid = (ls + rs) / 2;
        if(point_q <= mid)
        {
            // it is contained in the left subsegment (from ls to mid)
            // return the value in this subsegment plus query the child
            return ST[current_node] + point_value_query(current_node*2, ls, mid, point_q);
        }
        else
        {
            // it is contained in the right subsegment (from mid+1 to rs)
            // return the value in this subsegment plus query the child
            return ST[current_node] + point_value_query(current_node*2+1, mid+1, rs, point_q);
        }

    }

    // start from the top, and go updating from the bottom
    // update a range
    // revisar codigo y entender mejor despues
    void update(int current_node, int ls, int rs, int lq, int rq, int value_to_add)
    {
        if (lq > rq) return; // check if this fixes crash

        if(lq < ls || rq > rs) return; //trying to update for a range not contained in the current segment
        
        if(ls == lq && rs == rq) // base case, it is the parent node of the segment containing the updated node
        {
            ST[current_node] += value_to_add;
            return;
        }

        int mid = (ls + rs) / 2;

        // try to find root in both parents and try to propagate
        update(current_node*2, ls, mid, lq, min(rq, mid), value_to_add);
        update(current_node*2+1, mid+1, rs, max(lq, mid+1), rq, value_to_add);

    }
};


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
    int n, q; // n of elements, queries
    cin >> n >> q;
    vector<ll> values;

    int tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        values.push_back(tmp);
    }
    // cout << values.size() << endl;
    SegmentTree ST(values);

    for (int i = 0; i < q; ++i)
    {
        cin >> tmp;
        if(tmp == 1)
        {
            // 1 a b u
            int a, b, u;
            cin >> a >> b >> u;
            a--;
            b--;
            ST.update(1, 0, values.size()-1, a, b, u);
        }
        else
        {
            // 2 k (query)
            cin >> tmp;
            tmp--;
            // query
            cout << ST.point_value_query(1, 0, values.size()-1, tmp) << endl;
        }
    }
    
    
}