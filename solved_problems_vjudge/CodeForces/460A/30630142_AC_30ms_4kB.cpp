#include <bits/stdc++.h>
using namespace std;


int main() 
{
    int n, m, c=0;//n pares, m dias cada par
    cin >> n >> m;

    while(n > 0)
    {
        ++c;
        --n;
        if(c % m == 0)
        {
            ++n;
        }
    }

    cout << c << endl;
}
