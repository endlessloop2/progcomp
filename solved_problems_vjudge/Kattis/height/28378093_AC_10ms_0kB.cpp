#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}
int insertion_sort(vector<int> &vec)
{
    int counter = 0;
    for(int i = 1; i < vec.size(); ++i)
    {
        int key = vec[i];
        for(int j = i-1, c = 0; (j >= 0) && (key < vec[j]); --j, ++c)//retroceder
        {
            swap(vec[j], vec[i-c]);
            ++counter;
        }
    }
    return counter;
}

int main() 
{
    //no es con selection
    int p;// n of datasets
    cin >> p;
    for(int i = 0; i < p; ++i)
    {
        vector<int> vec;
        int k; // dataset id
        cin >> k;
        for(int j = 0; j < 20; ++j)
        {
            int tmp; //height in mm
            cin >> tmp;
            vec.push_back(tmp);

        }
        cout << k << " " << insertion_sort(vec) << endl;
    }

}