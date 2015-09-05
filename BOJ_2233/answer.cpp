#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
 
using namespace std;
 
pair<int, int> indexTree[2001];
int applePosition[4001][2] = { 0, };
string path;
void dfs();
void findCommonParent(int x, int y);
 
int main() {
 
    int n, x, y; cin >> n;
    cin >> path >> x >> y;
    dfs();
 
    findCommonParent(x, y);
     
    return 0;
}
 
void findCommonParent(int x, int y) {
    int xPos = x, yPos = y;
    vector<int> xParents, yParents;
 
    if (!applePosition[xPos][0]) {
        xPos--;
    }
    if (!applePosition[yPos][0]) yPos--;
 
    while (xPos != 1) {
        if (applePosition[xPos][0] == 0) {
            xPos = indexTree[applePosition[xPos][1]].first - 1;
        }
        else {
            xParents.push_back(applePosition[xPos][0]);
            xPos--;
        }
    }
    xParents.push_back(xPos);
 
    while (yPos != 1) {
        if (applePosition[yPos][0] == 0) {
            yPos = indexTree[applePosition[yPos][1]].first - 1;
        }
        else {
            yParents.push_back(applePosition[yPos][0]);
            yPos--;
        }
    }
    yParents.push_back(yPos);
 
    for (int i = 0; i < xParents.size(); i++) {
        for (int j = 0; j < yParents.size(); j++) {
            if (xParents[i] == yParents[j]) {
                cout << indexTree[xParents[i]].first << ' ' << indexTree[xParents[i]].second << endl;
                return;
            }
        }
    }
}
 
void dfs() {
    int num = 1;
    stack<int> st;
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == '0') {
            indexTree[num].first = i+1;
            applePosition[i+1][0] = num;
            st.push(num++);
        }
        else {
            applePosition[i+1][1] = st.top();
            indexTree[st.top()].second = i + 1;
            st.pop();
        }
    }
}
