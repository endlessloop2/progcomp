#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  
  string n;
  while(t--)
  {
    cin >> n;
    cout << (n[0] - '0') + (n[n.length()-1] - '0') << '\n';
    //cout << stoi(to_string(n[0])) + stoi(to_string(n[n.size()-1])) << endl;
    
  }

	return 0;
}
