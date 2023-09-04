#include <bits/stdc++.h>

using namespace std;

int main(){
   
    ios_base::sync_with_stdio (false);
    cin.tie(NULL);
    cout.setf(ios::fixed);

    string txt;
    cin >> txt;
    stack <char> texto;
    for(int i = 0; i < txt.size(); i++)
    {
        if(txt[i] == '<'){
           texto.pop();     
        }
        else
        {
            texto.push(txt[i]);
        }
    }

    //
    string nueva;
    while(!texto.empty())
    {
        nueva += texto.top();
        texto.pop();
    }
    reverse(nueva.begin(), nueva.end());
    cout << nueva << endl;
    
    

    return 0;
}
