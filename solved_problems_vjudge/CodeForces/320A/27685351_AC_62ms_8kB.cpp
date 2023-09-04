#include <iostream>
#include <vector>
#include <algorithm> //reverse
#include <string>

using namespace std;
int main()
{
    int n;
    vector <int> v; //digits
    cin >> n;
    bool isMagic = true;

    while (n != 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(), v.end());


    for(int i = 0; i < v.size(); i++)
    {
        string current = to_string(v[i]);
        string next2 = "";
        string next3 = "";

        if(i+1 < v.size())
        {
            next2 = current + to_string(v[i+1]);
        }
        if(i+2 < v.size())
        {
            next3 = next2 + to_string(v[i+2]);
        }

        if(next3 != "" && next3 == "144") // and not null
        {
            i += 2;
        }
        else if(next2 != "" && next2 == "14")
        {
            i += 1;
        }
        else if (current == "1")
        {
            
        }
        else// :/
        {
            isMagic = false;
            break;
        }
        
    }

    if(isMagic)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
}