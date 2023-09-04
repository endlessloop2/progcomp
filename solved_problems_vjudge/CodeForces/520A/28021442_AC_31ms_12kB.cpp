#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;//number of chars in str
    string s;
    //bool isPangram = true;
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //para que usar map? mejor ir vaciando esa wea
    cin >> n;
    cin.clear();
    cin.ignore();
    getline(cin, s);

    if(n < 26)
    {
        cout << "NO" << endl;
        return 0;
    }

    for(int i = 0; i < s.length(); ++i)
    {
        //loop through letters, if found, remove it.
        //if not found, continue.
        char letterOriginal = toupper(s[i]);
        for(int j = 0; j < letters.length(); ++j)
        {
            if(letterOriginal == letters[j])
            {
                letters.erase(letters.begin() + j);
            }
        }
    }

    if(letters.empty()) cout << "YES" << endl;//n >= tiene que ir antes del loop
    else cout << "NO" << endl;
    
}