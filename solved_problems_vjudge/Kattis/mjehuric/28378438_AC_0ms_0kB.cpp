#include <bits/stdc++.h>

using namespace std; 

void swap(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void print_array(vector<int> &vec)
{
    //vector<int> v = *vec;
    //for(auto i : vec)
    for(int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void bubble_sort(vector<int> &vec)
{
    for(int r = vec.size()-1; r > 0; --r)
    {
        bool finished = true;
        for(int i = 0; i < vec.size()-1; ++i)//pass
        {
            if (vec[i] > vec[i+1])
            {
                swap(vec[i], vec[i+1]);
                finished = false;
                //print array
                print_array(vec);
            }
        }
        if(finished) break;
    }
}

int main()
{
    vector<int> vec;
    int i = 6;
    while(--i)
    {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    bubble_sort(vec);


}