#include <iostream>
#include <string>
#include <vector>
#include <math.h>
 
using namespace std;
 
bool toBool(char a) {
    return a == '1';
}
 
int main() {
 
    int t; cin >> t;
    while (t--) {
        string str; cin >> str;
        long long result = 0;
        int n = str.size()-1;
        vector<bool> vt(n+1, false);
        for (int i = 0; i < str.size() - 1; i++) {
            if (toBool(str[i]) != vt[i]) {
                result += pow(2, n);
                vt[i + 1] = !vt[i + 1];
            }
            n--;
        }
        if (vt[vt.size()-1] != toBool(str[str.size()-1])) result++;
        cout << result << endl;
    }
 
    return 0;
}
