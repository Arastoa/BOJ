#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
#include <string>
#pragma warning(disable : 4996)
 
using namespace std;
 
const int ALPHABETS = 4;
 
int n, m;
int num[26]; 
char target[1000001],tMarker[101];
// 트라이의 한 노드를 나타내는 객체
struct TrieNode {
    TrieNode* children[ALPHABETS];
    int terminal;
    TrieNode* fail;
    bool output;
 
    TrieNode() : terminal(-1), output(false) {
        memset(children, 0, sizeof(children));
    }
 
    ~TrieNode() {
        for (int i = 0; i < ALPHABETS; i++)
        if (children[i])
            delete children[i];
    }
 
    void insert(const string& key,int index) {
        if (m == index)
            terminal = 1;
        else {
            int next = num[key[index]];
            if (children[next] == NULL)
                children[next] = new TrieNode();
            children[next]->insert(key,index+1);
             
        }
    }
};
void computeFailFunc(TrieNode* root) {
    queue<TrieNode*> q;
    root->fail = root;
    q.push(root);
 
    while (!q.empty()) {
        TrieNode* here = q.front();
        q.pop();
        for (int edge = 0; edge < ALPHABETS; ++edge) {
            TrieNode* child = here->children[edge];
            if (!child) continue;
            if (here == root)
                child->fail = root;
            else {
                TrieNode* t = here->fail;
                while (t != root && t->children[edge] == NULL)
                    t = t->fail;
                if (t->children[edge]) t = t->children[edge];
                child->fail = t;
            }
            child->output = child->fail->output;
            if (child->terminal != -1)
                child->output = true;
            q.push(child);
        }
    }
}
int ahoCorasick(const string& s, TrieNode* trie) {
    int ret = 0;
 
    TrieNode* state = trie;
    for (int i = 0; i < n; i++) {
        int chr = num[s[i]];
        while (state != trie && state->children[chr] == NULL)
            state = state->fail;
        if (state->children[chr]) state = state->children[chr];
        if (state->output)
            ret++;
    }
    return ret;
}
 
int main() {
    int t; scanf("%d", &t);
    num['A'] = 0, num['C'] = 1, num['G'] = 2, num['T'] = 3;
    while (t--){
        scanf("%d %d %s %s", &n, &m, target, tMarker);
        string str(target), marker(tMarker);
        TrieNode* node = new TrieNode();
        vector<string> vt;
        vt.push_back(marker);
        for (int i = 2; i <= m; i++) {
            for (int j = 0; j + i <= m; j++){
                reverse(marker.begin() + j, marker.begin() + (j + i));
                vt.push_back(marker);
                reverse(marker.begin() + j, marker.begin() + (j + i));
            }
        }
        sort(vt.begin(), vt.end());
        vt.erase(unique(vt.begin(), vt.end()),vt.end());
        for (int i = 0; i < vt.size(); i++)
            node->insert(vt[i],0);
        computeFailFunc(node);
 
        cout << ahoCorasick(str, node) << endl;
        delete node;
    }
 
    return 0;
}
