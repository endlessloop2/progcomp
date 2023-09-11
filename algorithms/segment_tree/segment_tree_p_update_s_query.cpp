// My implementation of a simple point update range sum query Segment Tree

#include <bits/stdc++.h>

using namespace std;


struct SegmentTree
{
    vector<int> ST;
    int N; // the size of the original vector

    SegmentTree(vector<int> &v)
    {
        N = v.size();
        ST.resize(N*4);
        build(1, 0, N - 1, v);
    }

    // we need to build starting from a certain node, in this case it will be the top node that will be set after all the recursive
    // calls are done
    void build(int node, int ls, int rs, vector<int> &v)
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
    int sum_query(int current_node, int ls, int rs, int lq, int rq)
    {
        if(lq > rq) return 0;

        // c1 (base): it is the same segment
        if(ls == lq && rs == rq)
        {
            return ST[current_node];
        }

        // c2: it is contained in a child subsegment
        int mid = (ls + rs) / 2;
        if(ls <= lq && rq <= rs)
        {
            // sum in first half of a subsegment equal to lq, min(rq, mid)
            // min r(rq, mid)
            return sum_query(current_node*2, ls, mid, lq, min(rq, mid)) +
            sum_query(current_node*2+1, mid+1, rs, max(mid+1, lq), rq); // sum in the second half of a subsegment equal to max(lq, mid), rq
        }
    }

    // start from the top, and go updating from the bottom
    void update(int current_node, int ls, int rs, int node_to_update, int new_value)
    {
        if(node_to_update < ls || node_to_update > rs) return; //trying to update for a node not contained in the current segment
        
        if(ls == rs && ls == node_to_update) // base case
        {
            ST[node_to_update] = new_value;
            return;
        }

        int mid = (ls + rs) / 2;

        if(node_to_update <= mid)
        {
            // update the parent
            update(current_node*2, ls, mid, node_to_update, new_value);
        }
        if(node_to_update >= mid+1)
        {
            //update the parent
            update(current_node*2, mid+1, rs, node_to_update, new_value);
        }

        // update parent
        ST[current_node] = ST[current_node*2] + ST[current_node*2+1];


    }
};