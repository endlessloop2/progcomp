#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, tmp;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());

    cout << arr[n/2] << endl;

    return 0;
}