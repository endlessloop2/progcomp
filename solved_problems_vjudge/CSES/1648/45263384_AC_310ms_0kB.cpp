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

// My implementation of a simple point update range sum query Segment Tree
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

    // we need to build starting from a certain node, in this case it will be the top node that will be set after all the recursive
    // calls are done
    void build(int node, int ls, int rs, vector<ll> &v)
    {
        // divide and conquer topdown recursion
        // base case: the segment is a single value in the vector, it is a leaf in ST[]
        if(ls == rs)
        {
            // ls or rs is the location in the original vector
            ST[node] = v[ls];// idk
            return;
        }


        int mid = (ls + rs) / 2;
        // find the sum of the left child (first half of the current segment in original array) stored in ST[2*node]
        build(2*node, ls, mid, v);

        // right child sum (2nd half of the current segment in original array) (stored in ST[2*node+1])
        build((2*node)+1, mid+1, rs, v);

        // build the parent summing both.
        ST[node] = ST[2*node] + ST[2*node+1];
    }

    // start traversing at the start, current_node 1
    //understand better
    ll sum_query(int current_node, int ls, int rs, int lq, int rq)
    {
        if(lq > rq) return 0;

        // c1 (base): it is the same segment
        if(ls == lq && rs == rq)
        {
            return ST[current_node];
        }

        // c2: it is fully contained in a child subsegment
        int mid = (ls + rs) / 2;
        if(ls <= lq && rq <= rs)
        {
            // call left child
            if(lq == ls && rq == mid)
            {
                return sum_query(current_node*2, ls, mid, lq, min(rq, mid));
            }
            // call right child
            else if(lq == mid+1 && rq == rs)
            {
                return sum_query(current_node*2+1, mid+1, rs, max(mid+1, lq), rq);
            }
            // sum in first half of a subsegment equal to lq, min(rq, mid)
            // min r(rq, mid)
            //return sum_query(current_node*2, ls, mid, lq, min(rq, mid)) +
            //sum_query(current_node*2+1, mid+1, rs, max(mid+1, lq), rq); // sum in the second half of a subsegment equal to max(lq, mid), rq
        }

        // c3: it is contained in parts of both children
        return sum_query(current_node*2, ls, mid, lq, min(rq, mid)) + 
        sum_query(current_node*2+1, mid+1, rs, max(mid+1, lq), rq);
    }

    // start from the top, and go updating from the bottom
    void update(int current_node, int ls, int rs, int node_to_update, ll new_value)
    {
        if(node_to_update < ls || node_to_update > rs) return; //trying to update for a node not contained in the current segment
        
        if(ls == rs && ls == node_to_update) // base case
        {
            ST[current_node] = new_value; // aqui esta el problema
            return;
        }

        int mid = (ls + rs) / 2;

        update(current_node*2, ls, mid, node_to_update, new_value);

        //update the right parent
        update(current_node*2 + 1, mid+1, rs, node_to_update, new_value);

        // update parent
        ST[current_node] = ST[current_node*2] + ST[current_node*2+1];


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
    int n, q; // n of values and n of queries
    cin >> n >> q;

    vector<ll> vv;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        vv.push_back(tmp);
    }
    SegmentTree tree(vv); 

    int qt, a, b;
    for (int i = 0; i < q; i++)
    {
        cin >> qt >> a >> b;
        a--;
        if(qt == 1)
        {
            tree.update(1, 0, vv.size()-1, a, b);
        }
        else
        {
            b--;
            cout << tree.sum_query(1, 0, vv.size()-1, a, b) << endl;
        }
    }
    
}