#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#pragma warning( disable : 4996)
 
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t--){
        int n,target,inteval=987654321,result=987654321; scanf("%d %d", &target,&n);
        int arr[4][1000];
 
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < n; j++) 
                scanf("%d", &arr[i][j]);
        }
         
        vector<int> vt;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)vt.push_back(arr[0][i] + arr[1][j]);
        }
 
        sort(vt.begin(), vt.end());
 
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int tmp = arr[2][i] + arr[3][j];
                vector<int>::iterator itr = lower_bound(vt.begin(), vt.end(), target - tmp);
                if (itr == vt.end()) itr--;
                int ab = abs(target - (*itr + tmp));
                 
            //  cout <<  tmp <<' '<<*itr << endl;
                if (inteval > ab){
                    inteval = ab;
                    result = *itr + tmp;
                     
                }
                else if (inteval == ab) result = min(result, *itr + tmp);
                if (itr != vt.begin()) {
                    itr--;
                    ab = abs(target - (*itr + tmp));
                    if (inteval >= ab){
                        inteval = ab;
                        result = *itr + tmp;
                    }
                }
            }
        }
 
        cout << result << endl;
 
    }
    return 0;
}
