#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
set<int> cache;
void setCache(int n);
 
int main(){
    setCache(0);
    int t; cin >> t;
 
    while (t--){
        int n, m, k,data;
        set<int> result;
        vector<int> a, b, c;
        cin >> n;
 
        for (int i = 0; i < n; i++) {
            cin >> data; a.push_back(data);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> data; b.push_back(data);
        }
 
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> data; c.push_back(data);
        }
        for (int i = 0; i < a.size(); i++){
            for (int j = 0; j < b.size(); j++)
            for (int k = 0; k < c.size(); k++)
            if (cache.find(a[i] + b[j] + c[k]) != cache.end()){
                result.insert(a[i] + b[j] + c[k]);
            }
        }
 
        cout << result.size() << endl;
    }
 
    return 0;
}
 
void setCache(int n){
    if (n > 100000) return;
    cache.insert(n);
    setCache(n * 10 + 5);
    setCache(n * 10 + 8);
}
