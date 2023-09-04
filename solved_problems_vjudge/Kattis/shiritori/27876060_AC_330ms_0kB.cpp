#include <bits/stdc++.h>

using namespace std;

char getFirstLetter(string s);
char getLastLetter(string s);

// VERSION NUEVA CON SET Y FIND
int main()
{
    int n; //num of lines
    cin >> n;

    char last_letter;
    set<string> prevWords;
    for(int i = 0; i < n; ++i)
    {
        int currentPlayer = i+1;
        if(currentPlayer % 2 == 0) currentPlayer = 2;
        else currentPlayer = 1;

        string word;
        cin >> word;
        bool wordRepeated = false;
            //auto it = prevWords.find(word);
        if(prevWords.find(word) != prevWords.end()) wordRepeated = true;
        
        if(wordRepeated || (i > 0 && last_letter != getFirstLetter(word)) )
        {
            cout << "Player " << currentPlayer << " lost" << endl;
            return 0;
        }

        prevWords.insert(word);
        last_letter = getLastLetter(word);
    }

    cout << "Fair Game" << endl;

}

char getFirstLetter(string s)
{
    //substr.s()
    return s.at(0);
}

char getLastLetter(string s)
{
    return s.at(s.length()-1);//-2 pq cuenta de 0 y ademas s.length tiene 1 mas // MALO, SOLO RESTAR 1
}