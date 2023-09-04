#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c; //num of chapters
    cin >> c;

    vector<pair<int,int>> v;
    for(int i = 0; i < c; ++i)// for each chapter
    {
        pair <int, int> p;//pair <int, char> NO XD
        int a, b; //first and last page of c chapter
        cin >> a >> b;
        p.first = a;
        p.second = b;
        v.push_back(p);

    }
    int marked;//marked page
    cin >> marked;
    //how many chapters haven't been read fully

    int unfinishedChapters = -1;
    //int unfinishedChapters = 0;
    for(int i = 0; i < v.size(); ++i)// for each chapter
    {
        if(unfinishedChapters != -1)
        {
            ++unfinishedChapters;
        }
        else if(marked >= v[i].first && marked <= v[i].second)//no era +1?
        {
            unfinishedChapters = 1;
        }
        /*if(marked >= v[i].first && marked <= v[i].second+1)
        {
            ++unfinishedChapters;
        }*/
    }

    if(unfinishedChapters == -1) unfinishedChapters = 0;
    cout << unfinishedChapters << endl;    
}