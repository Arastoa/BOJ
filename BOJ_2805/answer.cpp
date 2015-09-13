#include <iostream>
#include <vector>
 
using namespace std;
 
int cut(const vector<int>& vt, int k);
 
int main(){
 
    vector<int> vt;
    int n, k;
 
    cin >> n >> k;
 
    for (int i = 0; i < n; i++){
        int data; cin >> data;
        vt.push_back(data);
    }
 
    cout << cut(vt, k) << endl;
 
 
    return 0;
}
 
int cut(const vector<int>& vt, int k){
    int hi = 1000000001, low = 1;
 
    while (low + 1<hi){
        long long tmp = 0, mid = (hi + low) / 2;
        for (int j = 0; j < vt.size(); j++)
            tmp += (vt[j] - mid > 0 ? vt[j] - mid : 0);
 
        if (tmp < k) hi = mid;
        else low = mid;
    }
 
    return low;
}
