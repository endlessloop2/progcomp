#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

int bubble_sort(vector<int> &vec)
{
    int counter = 0;
    for(int r = vec.size()-1; r > 0; --r)
    {
        bool finished = true;
        for(int i = 0; i < vec.size()-1; ++i)//pass
        {
            int tmp;
            if (vec[i] > vec[i+1])
            {
                swap(vec[i], vec[i+1]);
                finished = false;
                ++counter;
            }
        }
        if(finished) break;
    }
    return counter;
}

int main()
{
    int N;
    //cin >> N;
    while(cin >> N)
    {
        vector<int> v;
        while(1 + --N)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        cout << "Minimum exchange operations : " << bubble_sort(v) << endl;
    }
}