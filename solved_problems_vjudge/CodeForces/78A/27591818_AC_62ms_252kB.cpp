#include <iostream>

using namespace std;
int countVowels(string s);
int main()
{
    string s[3];
    getline (cin, s[0]);
    getline (cin, s[1]);
    getline (cin, s[2]);

    if(countVowels(s[0]) == 5 && countVowels(s[1]) == 7 && countVowels(s[2]) == 5)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}

int countVowels(string s)
{
    int vowels;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            vowels++;
        }
    }
    return vowels;
}