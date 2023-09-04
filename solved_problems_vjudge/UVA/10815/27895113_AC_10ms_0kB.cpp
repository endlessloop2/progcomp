#include <bits/stdc++.h>
using namespace std;

string aMinuscula(string cadena);

int main() {
    string word;
    set <string> s;
    set <string> :: iterator it;
    while(cin >> word)//word
    {
        //a.insert(aMinuscula(n));
        word = aMinuscula(word);
        string temp;        
        for (int i = 0; i < word.size(); ++i)//loop through chars
        {
            if(isalpha(word[i])) //o usar el truco de ascii
            {
                temp += word[i];
            }
            else
            {
                if(!temp.empty())
                {
                    s.insert(temp);
                    temp.clear();
                }
            }
            
            //string.clear();
        }
        if(!temp.empty())//para el caso que toda la word sea buena
        {
            s.insert(temp);
        }

    }

    for (it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << endl;
    }
}


string aMinuscula(string cadena) 
{
    for (int i = 0; i < cadena.length(); i++) cadena[i] = tolower(cadena[i]);
    return cadena;
}