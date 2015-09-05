#include <iostream>
#include <vector>
 
using namespace std;

int main() {
    int t,n; cin >> t;
    while(t--){
        cin >> n;
        int day = 1;
        long long food = 0;
         
        for (int i = 0; i < 6; i++) {
            int data; cin >> data;
            food += data;
        }
 
        while (food <= n) {
            food = food*4;
            day++;
        }
 
        cout << day << endl;
    }
    return 0;
}
 
