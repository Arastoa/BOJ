#include <stdio.h>
#include <iostream>
 
using namespace std;
 
int main() {
 
    int n; cin >> n;
 
    while (n--) {
        int h, w; cin >> h >> w;
        int sw = 1;
        printf("1\n");
        printf("(0,0)\n");
        for (int i = 0; i < h; i++) {
            int start = (sw == 1 ? 1 : w - 1); int end = (sw == 1 ? w - 1 : 1);
 
            if (sw == 1) {
                for (; start <= end; start++) printf("(%d,%d)\n", i, start);
            }
            else {
                for (; start >=end ; start--) printf("(%d,%d)\n", i, start);
            }
            sw = sw*-1;
        }
 
        for (int i = h - 1; i > 0; i--)
            printf("(%d,%d)\n", i, 0);
    }
 
    return 0;
}
