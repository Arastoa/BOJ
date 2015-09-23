#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <string>

using namespace std;

const int ALPHABETS = 26;
int toNumber(char ch) { return ch - 'a'; }


// 트라이의 한 노드를 나타내는 객체
struct TrieNode {
	TrieNode* children[ALPHABETS];
	// 현 위치에서 끝나는 문자열의 번호
	int terminal;

	// 이 노드에서 매칭이 실패했을 때 이 곳으로 가서 계속한다.
	// 이 노드에 대응되는 문자열의 접미사이면서 트라이에 포함된 최대 문자열.
	TrieNode* fail;
	// 이 노드가 방문되었을 때 등장하는 문자열들의 번호
	vector<int> output;

	TrieNode() : terminal(-1) {
		memset(children, 0, sizeof(children));
	}

	~TrieNode() {
		for (int i = 0; i < ALPHABETS; i++)
		if (children[i])
			delete children[i];
	}

	// 이 노드를 루트로 하는 트라이에 번호가 id 인 문자열 key 를 추가한다
	void insert(const char* key, int id) {
		// 문자열이 끝나면 terminal 만 참으로 바꾸고 종료
		if (*key == 0)
			terminal = id;
		else {
			int next = toNumber(*key);
			// 해당 자식 노드가 없다면 생성한다
			if (children[next] == NULL)
				children[next] = new TrieNode();
			// 해당 자식 노드로 재귀호출
			children[next]->insert(key + 1, id);
		}
	}

	TrieNode* find(const char* key) {
		if (*key == 0) return this;
		int next = toNumber(*key);
		if (children[next] == NULL) return NULL;
		return children[next]->find(key + 1);
	}
};

// 트라이가 주어질 때 각 노드에 대해 실패 연결과 출력 문자열 목록을 계산한다.
void computeFailFunc(TrieNode* root) {
	// 루트에서부터 시작해 한 단계씩 아래로 내려가며 각 노드의 실패 연결을 계산한다.
	queue<TrieNode*> q;
	// 루트의 실패 연결은 자기 자신
	root->fail = root;
	q.push(root);

	while (!q.empty()) {
		TrieNode* here = q.front();
		q.pop();
		// here 의 모든 노드에 대해 실패 연결을 계산하고 이들을 큐에 넣는다
		for (int edge = 0; edge < ALPHABETS; ++edge) {
			TrieNode* child = here->children[edge];
			if (!child) continue;

			// 1레벨 노드의 실패 연결은 항상 루트
			if (here == root)
				child->fail = root;
			else {
				// 아닌 경우 부모의 실패 연결을 따라가면서 실패 연결을 찾는다
				TrieNode* t = here->fail;
				while (t != root && t->children[edge] == NULL)
					t = t->fail;
				if (t->children[edge]) t = t->children[edge];
				child->fail = t;
			}
			// 출력 문자열 목록: 실패 연결에서 가져온 뒤, 이 위치에서 끝나는 문자열이 있으면 추가한다
			child->output = child->fail->output;
			if (child->terminal != -1)
				child->output.push_back(child->terminal);
			q.push(child);
		}
	}
}

// trie 에 포함된 패턴들을 s 에서 찾는다.
// s 내에서 패턴이 출현할 때마다 (마지막 글자, 패턴 번호) 의 쌍을 저장한다
bool ahoCorasick(const string& s, TrieNode* trie) {
	vector<pair<int, int> > ret;

	TrieNode* state = trie;
	// 실제 루프 내는 KMP 와 별로 다를 것이 없다
	for (int i = 0; i < s.size(); i++) {
		int chr = toNumber(s[i]);
		while (state != trie && state->children[chr] == NULL)
			state = state->fail;
		if (state->children[chr]) state = state->children[chr];
		for (int j = 0; j < state->output.size(); ++j)
			return true;
	}
	return false;
}
int main() {

	int n; cin >> n;
	TrieNode* node = new TrieNode();

	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		node->insert(s[i].c_str(), i);
	}
	computeFailFunc(node);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		bool flag = false;

		vector<pair<int, int> > aho;
		for (int i = 0; i < s.size() && !flag; i++){
			flag = ahoCorasick(str, node);
			if (flag) {
				cout << "YES" << endl;
				//flag = true;
				break;
			}
		}

		if (!flag) cout << "NO" << endl;
	}

	return 0;
}
