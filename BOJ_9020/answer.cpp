#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
 
using namespace std;
 
void setting();
 
vector<int>pNums;
bool pNum[10001] = { false, };
 
 
int main(){
    setting();
    int t; cin >> t;
    while (t--){
        int  a, b,n; cin >> n;
         
        for (int i = 0; i < pNums.size() && pNums[i] <= n/2; i++){
            if (binary_search(pNums.begin(), pNums.end(), n - pNums[i])){
                a = pNums[i]; // b = n - pNum[i];
            }
 
        }
        cout << a << ' ' << n-a << endl;
    }
    return 0;
}
 
 
void setting(){
    int sqrtn = sqrt(10001);
    for (int i = 2; i <= sqrtn; i++)
    if (!pNum[i]){
        pNums.push_back(i);
        for (int j = i*i; j < 10001; j += i)
            pNum[j] = true;
    }
    for (int i = sqrtn + 1; i < 10001; i++)
    if (!pNum[i])
        pNums.push_back(i);
}
