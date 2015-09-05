#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int candyWar(vector<int>& vt);
 
int main(){
 
    int t; cin >> t;
 
    while (t--){
        int n; cin >> n;
        vector<int> vt;
        while (n--){
            int data; cin >> data;
            if (data % 2 == 1) data++;
            vt.push_back(data);
        }
        cout << candyWar(vt) << endl;
    }
 
    return 0;
}
 
int candyWar(vector<int>& vt){
    int ret = 0;
    while (true){
        vector<int> candy(vt.size(), vt[0]);
         
        if (vt == candy) break;
 
        vector<int> temp;
 
        for (int i = 0; i < vt.size() - 1; i++){
            temp.push_back(vt[i] / 2);
            vt[i] /= 2;
        }
        temp.insert(temp.begin(), vt.back() / 2);
        vt.back() /= 2;
 
        for (int i = 0; i < vt.size(); i++){
            vt[i] += temp[i];
            if (vt[i] % 2 == 1) vt[i]++;
        }
 
        ret++;
    }
    return ret;
}
