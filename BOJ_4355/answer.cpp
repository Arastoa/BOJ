#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
 
using namespace std;
 
int euler(int n);
 
int main() {
 
    while (true) {
        int data; cin >> data;
        if (!data) break;
        cout << euler(data) << endl;
    }
 
    return 0;
}
 
int euler(int n) {
    int sqrtn = sqrt(n);
    int temp = n;
    vector<pair<int, int> >  vt;
    for (int i = 2; i <= sqrtn + 10; i++) {
        bool flag = false;
        int cnt = 0;
        while (temp%i == 0) {
            flag = true;
            cnt++;
            temp /= i;
        }
        if (flag) vt.push_back(make_pair(i, cnt));
        if (temp == 1) break;
    }
 
    if (vt.size() == 0) return n - 1;
 
    int ret = 1;
    if(temp!=1)
        vt.push_back(make_pair(temp, 1));
    for (int i = 0; i < vt.size(); i++) {
        //  cout << vt[i].first << ' ' << vt[i].second << endl;
        ret = ret* (pow(vt[i].first, vt[i].second) - pow(vt[i].first, vt[i].second - 1));
    }
    return ret;
}
