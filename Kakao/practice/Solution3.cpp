#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
  //vector<vector<int> >의 값은 다음과 같이 읽어올 수 있습니다.
    //cout << v[0][0] << " ";
    int x = v[0][0] ^ v[1][0] ^ v[2][0];
    int y = v[0][1] ^ v[1][1] ^ v[2][1];
    vector<int> ans;
    ans.push_back(x), ans.push_back(y);
    return ans;
}
