#include <bits/stdc++.h>

using namespace std;

int main()
{
    string h, t;//heading, text
    getline(cin, h);
    getline(cin, t);

    //loop through h, add to map
    map <char, int> letras;
    bool canWrite = true;
    for(int i = 0; i < h.length() ; ++i)
    {
        //añadir h[i] al map si no esta, si esta h[i]++
        map <char, int>::iterator it;
        it = letras.find(h[i]);
        if(it == letras.end()) letras[h[i]] = 1;
        else letras[h[i]]++;
        /*for(it = letras.begin(); it != letras.end(); ++it)
        {
            
        }*/
    }

    for(int i = 0; i < t.length() ; ++i)
    {
        map <char, int>::iterator it;
        //t[i];
        if(!isalpha(t[i])) continue;
        it = letras.find(t[i]);
        if(it != letras.end())
        {
            if(it->second > 1)
            {
                it->second--;
            }
            else
            {
                letras.erase(it);
            }
            
        }
        else
        {
            canWrite = false;
            break;
        }
        
    }

    if(canWrite) cout << "YES" << endl;
    else cout << "NO" << endl;
}