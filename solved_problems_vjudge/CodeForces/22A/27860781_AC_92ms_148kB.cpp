#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; //num
    cin >> n;
    set<int> s;

    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    set<int>::iterator it;
    bool firstValue = true;
    int num = NULL;
    for (it = s.begin(); it != s.end(); ++it) 
    {
        if(!firstValue)
        {
            num = *it;
            break;
        }
        firstValue = false;
    }
    if(num != NULL) cout << num << endl;
    else cout << "NO" << endl;

}