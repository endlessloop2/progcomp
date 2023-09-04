#include <iostream>
#include <set>
using namespace std;
int main() 
{   
    int n;
    set<string> s;
    cin>>n;
    for(int i=0;i<n ;i++)
    {
        string temp;
        cin >> temp;
        if(s.find(temp) != s.end())
        {
            cout << "YES" << endl;
        }
        else
        {
            s.insert(temp);
            cout << "NO" << endl;
        }
    }
    return 0;
}
