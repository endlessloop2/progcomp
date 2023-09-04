#include <bits/stdc++.h>
using namespace std;

void cases()
{
    int n, tmp, dif_menor = INT_MAX;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n-1; i++)
    {
        dif_menor = min(dif_menor, abs(arr[i] - arr[i+1]));
    }
    cout << dif_menor << endl;    
}
int main() 
{
    int t;
    cin >> t;

    while(t--)
    {
        cases();
    }

    return 0;
}
