#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
 
using namespace std;
 
int main() {
 
    long long h, root, depth = 1; string str;
    cin >> h;
    root = pow(2, h + 1) - 1;
 
    char ch=getchar(), front;
    front = 'R';
    if (ch == '\n') {
        cout << root << endl;
        return 0;
    }
 
    while ((ch=getchar()) != '\n') {
        switch (front) {
        case 'R':
            switch (ch) {
            case 'L':
                root -= (depth * 2 - 1);
                depth = (depth * 2 - 1);
                break;
            default:
                root -= (depth * 2);
                depth=(depth * 2);
                break;
            }
            break;
        case 'L':
            switch (ch) {
            case 'R':
                root -= (depth * 2 + 1);
                depth = (depth * 2 + 1);
                break;
            default:
                root -= (depth * 2);
                depth = (depth * 2);
                break;
            }
            break;
        }
        front = ch;
         
    //  cout << root << ' ' << depth << endl;
    }
    cout << root << endl;
    return 0;
}
