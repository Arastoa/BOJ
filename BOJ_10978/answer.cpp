#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        long long result = 0;
        for (int i = 2; i <= n; i++){
            result = i*result + (i % 2 == 0 ? 1 : -1);
        }
        cout << result << endl;
    }
    return 0;
}
