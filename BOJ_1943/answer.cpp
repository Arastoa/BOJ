#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#pragma warning (disable : 4996)
 
using namespace std;
 
int cache[101][50001];
int n;
int sum;
vector<pair<int, int> > vt;
int divCoin(int index, int s);
 
int main(){
    while (~scanf("%d", &n)){
        sum = 0;
        vt.assign(n+1, make_pair(0, 0));
        memset(cache, -1, sizeof(cache));
        for (int i = 1; i <= n; i++){
            cin >> vt[i].first >> vt[i].second;
            sum += vt[i].first*vt[i].second;
        }
        if (sum % 2 == 1) cout << 0 << endl;
        else{
            sum /= 2;
            cout << divCoin(0, 0) << endl;
        }
    }
 
 
    return 0;
}
 
int divCoin(int index, int s){
    //cout << index << ' ' << s << endl;
    if (s == sum) return 1;
    if (s > sum) return 0;
    if (index == n) return s == sum;
    int& ret = cache[index][s];
    if (ret != -1) return ret;
    ret = 0;
 
    for (int i = index + 1; i <= n && !ret; i++){
        for (int j = 1; j <= vt[i].second && !ret; j++) ret |= divCoin(i, s + vt[i].first * j);
    }
    return ret;
}
