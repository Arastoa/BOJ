#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> vt;
pair<int, int> findNum(int a);
long long fNum(pair<int, int> a);
void setting();
 
int main() {
    int t; cin >> t;
    setting();
    while (t--) {
        int a, b; cin >> a >> b;
        pair<int, int> ap, bp;
        ap = findNum(a), bp = findNum(b);
         
    //  cout << ap.first <<' '<<ap.second<<' '<< bp.first << ' '<< bp.second << endl;
 
        cout << fNum(make_pair(ap.first + bp.first, bp.second + ap.second)) << endl;
    }
}
 
pair<int, int> findNum(int a) {
    pair<int, int> ret;
 
    int index = lower_bound(vt.begin(), vt.end(), a) - vt.begin();
    index++;
    int gap = abs(vt[index-1]-a);
    //cout << gap << endl;
    ret.second = (gap==0 ? index : gap);
    ret.first = (index-gap == index ? 1 : index - gap);
 
    return ret;
}
 
long long fNum(pair<int, int> a) {
    long long ret = 1, plus = 2;
     
    int x = a.first, y = a.second;
 
    ret = (y-1) * (2 * x + (y - 2)) / 2 + x*(2 + (x - 1)) / 2;
 
    return ret;
}
 
void setting() {
    vt.push_back(1);
    for (int i = 1; i <= 10000; i++)
        vt.push_back(vt.back() + i);
}
