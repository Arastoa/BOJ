#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

struct Tree
{
	Tree* child[10];
	bool isTerminal;
	Tree() {
		memset(child, NULL, sizeof(child));
		isTerminal = false;
	}
	~Tree()
	{
		for (int i = 0; i < 10; i++)
			if (child[i] != NULL)
				delete child[i];
	}

	void Insert(const char* telNum, int size, int index, bool& isCon)
	{
		if (size == index)
		{
			isTerminal = true;
			for (int i = 0; i < 10; i++)
				if(child[i]!=NULL)
					isCon = false;
		}
		else
		{
			int next = telNum[index] - '0';
			if (child[next] == NULL)
				child[next] = new Tree();
			if (isTerminal)
				isCon = false;

			child[next]->Insert(telNum, size, index + 1, isCon);
		}
	}
};

int main() {
	int t; cin >> t;

	while (t--) {
		bool isCon = true;
		int n; 
		char buffer[16];
		Tree* tri = new Tree();

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", buffer);
			tri->Insert(buffer, strlen(buffer), 0, isCon);
		}

		cout << (isCon ? "YES" : "NO") << endl;
		delete tri;
	}

	return 0;
}
