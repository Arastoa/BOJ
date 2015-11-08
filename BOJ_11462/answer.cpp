#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    while (true) {
        string str; cin >> str;
        if (str == "END") break;
        int i = str.size() - 1;
        for (; i >= 0; i--) if (str[i] != '0') break;
        str[i]--;
        cout << stoi(str) << endl;  
    }
    return 0;
}
