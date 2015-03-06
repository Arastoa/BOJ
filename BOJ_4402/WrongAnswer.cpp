#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
void vtSetting(vector<int>& vt,const string& str);
void printVt(const vector<int>& vt);
 
int main(){
 
    string str;
    while (true){
        if (cin.eof()){
            break;
        }
        cin >> str;
        vector<int> vt;
        vtSetting(vt, str);
        printVt(vt);
    }
 
    return 0;
}
 
void printVt(const vector<int>& vt){
    if (vt[0] != 0)
        cout << vt[0];
 
    for (int i = 1; i < vt.size(); i++){
        if (vt[i] != 0 && vt[i] != vt[i - 1])
            cout << vt[i];
    }
    cout << endl;
}
 
void vtSetting(vector<int>& vt, const string& str){
    for (int i = 0; i < str.length(); i++){
        switch (str[i]){
        case 'B': case 'F': case 'V': case 'P':
            vt.push_back(1);
            break;
        case 'C': case 'G':case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z':
            vt.push_back(2);
            break;
        case 'D': case 'T':
            vt.push_back(3);
            break;
        case 'L':
            vt.push_back(4);
            break;
        case 'M': case 'N':
            vt.push_back(5);
            break;
        case 'R':
            vt.push_back(6);
            break;
        default:
            vt.push_back(0);
            break;
        }
    }
}
