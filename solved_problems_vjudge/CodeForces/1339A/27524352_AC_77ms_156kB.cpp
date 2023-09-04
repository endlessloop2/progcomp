#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int test_count;
    cin >> test_count;
    vector<int> test_data;
    for(int i = 0; i < test_count; i++)
    {
        int a;
        cin >> a;
        test_data.push_back(a);
    }
    
    for(int i = 0; i < test_data.size(); i++)
    {
        cout << test_data[i] << endl;
    }
}