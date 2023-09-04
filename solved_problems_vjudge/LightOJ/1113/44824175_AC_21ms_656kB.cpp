#include <bits/stdc++.h>

using namespace std;

void solve();

const string START_URL = "http://www.lightoj.com/";

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cases;
    cin >> cases;
    for(int i = 0; i < cases; ++i)
    {
        cout << "Case " << i+1 << ":" << endl;
        solve();
    }
    return 0;
}

void solve()
{
    string cmd1, url;
    string current_url = START_URL;
    stack<string> back, forward;

    while(cin >> cmd1 && cmd1 != "QUIT")
    {
        // bool flag = 0;
        // for (int i = 0; i < full_cmd.size(); i++)
        // {
        //     if(full_cmd[i] == ' ')
        //     {
        //         flag = 1;
        //         continue;
        //     }
        //     (!flag) ? cmd += full_cmd[i] : url += full_cmd[i];
            
        // }
        if(cmd1 == "BACK")
        {
            if(back.empty())
            {
                cout << "Ignored" << endl;
            }
            else
            {
                forward.push(current_url);
                current_url = back.top();
                back.pop();
                cout << current_url << endl;
            }
        }
        else if(cmd1 == "FORWARD")
        {
            if(forward.empty())
            {
                cout << "Ignored" << endl;
            }
            else
            {
                back.push(current_url);
                current_url = forward.top();
                forward.pop();
                cout << current_url << endl;
            }
        }
        else if(cmd1 == "VISIT")
        {
            cin >> url;
            forward = stack<string>();// memory inefficient
            back.push(current_url);
            current_url = url;
            cout << current_url << endl;
        }
    }

}