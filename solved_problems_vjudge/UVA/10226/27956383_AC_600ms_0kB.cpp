#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    cin.clear();
    string a;
    getline(cin, a);//linea del principio
    for(int i = 0; i < t; ++i)//caso
    {
        map <string, int> trees;
        string tree;//tree
        if(i == 0)
        {
            getline(cin, tree);
        }

        getline(cin, tree);
        int treeCount = -1;
        /*treeCount == -1 ||*/ /*(tree != "" && tree != "\n")*/
        while(!tree.empty())
        {
            if(treeCount == -1) treeCount = 1;

            //bool treeAlreadyThere = false;
            map<string, int>::iterator it;

            /*for(it = trees.begin(); it != trees.end(); ++it)
            {
                if(it->first == tree)//si estaba antes
                {
                    treeAlreadyThere = true;
                    break;
                }
            }*/
            it = trees.find(tree);
            //if treeAlreadyThere
            if(it == trees.end()) trees[tree] = 1;//no esta
            else trees[tree]++;

            treeCount++;//ESTO ESTA MAL
            getline(cin, tree);
            //cin >> tree;
        }

        map<string, int>::iterator it;
        treeCount--;
        for(it = trees.begin(); it != trees.end(); ++it)
        {   
            string s = it->first;
            double division = (it->second * 100) / (double) treeCount;
            cout << s << " ";//sol :/
            printf("%.4f\n", division);
        }
        if(i != t-1) cout << endl;
    //round 4 decimal
    }//end for
}