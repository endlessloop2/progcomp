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
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
      vector<int> vec;
      int l;
      cin >> l;
      for(int j = 0; j < l; ++j)
      {
          int tmp;
          cin >> tmp;
          vec.push_back(tmp);
      }
      cout << "Optimal train swapping takes " << insertion_sort(vec) << " swaps." << endl;
    
    }

}