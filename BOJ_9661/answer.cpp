#include <iostream>
 
using namespace std;

int main() {
    long long n; cin >> n;
    int i = 1;
    if (n % 5 == 2 || n % 5 == 0) cout << "CY" << endl;
    else cout << "SK" << endl;
 
    return 0;
}
