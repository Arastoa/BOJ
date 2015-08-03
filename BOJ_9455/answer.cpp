#include <iostream>
 
using namespace std;
 
int field[100][100];
int cnt(int n, int m);
 
int main(){
 
    int t; cin >> t;
 
    while (t--){
        int n, m;
        cin >> n >> m;
 
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                cin >> field[i][j];
        }
 
        cout << cnt(n, m) << endl;
         
    }
 
 
    return 0;
}
 
int cnt(int n, int m){
    int ret = 0;
 
    for (int j = 0; j < m; j++){
        int length=n-1;
 
        for (int i = n-1; i >=0 ; i--){
            if (field[i][j]){
                ret += length - i;
                length--;
            }
        }
    }
    return ret;
}
