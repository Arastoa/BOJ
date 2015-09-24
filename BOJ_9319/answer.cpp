#include <iostream>
 
using namespace std;
 
int main(){
    int t; cin >> t;
 
    while (t--){
        long long n, x, y, tm;
        double b, s = 0, rm = 0;
        cin >> n >> b>>x>>y;
        for (int i = 1; i <= n; i++){
            long long x1, y1;
            cin >> x1 >> y1 >> s;
            double r = s / ((x1 - x)*(x1 - x) + (y1 - y)*(y1 - y));
            if (r > rm) {
                rm = r; tm = i;
            }
            b += r;
        }
        b -= rm;
        if (rm > 6 * b) cout << tm << endl;
        else cout << "NOISE" << endl;
    }
    return 0;
}
