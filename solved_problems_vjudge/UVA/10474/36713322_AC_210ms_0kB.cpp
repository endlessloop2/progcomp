#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, q, tmp, c = 0;

    while(cin >> n >> q && (n != 0 && q != 0))
    {
        cout << "CASE# " << c+1 << ":" << endl;
        vector<int> arr;
        for(int i = 0; i < n; i++)
        {
            cin >> tmp;
            arr.push_back(tmp);
        }
        sort(arr.begin(), arr.end());

        for(int i = 0; i < q; i++)
        {
            cin >> tmp;
            if(binary_search(arr.begin(), arr.end(), tmp))
            {
                cout << tmp << " found at " << (lower_bound(arr.begin(), arr.end(), tmp) - arr.begin() + 1) << endl;
            }
            else
            {
                cout << tmp << " not found" << endl;
            }
        }
        c++;
    }

    return 0;
}
