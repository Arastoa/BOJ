#include <iostream>
#include <string>
#include <stack>

using namespace std;

char raws(const string& expression,int result);

int main(){
	string expression;
	int result;

	cin >> expression >> result;
	cout << raws(expression, result)<<endl;

	return 0;
}

char raws(const string& expression,int result){
	stack<int> st;
	int firstRaw=0, secondRaw=0,tmp;
	//cal firstRaw;

	for (int i = 0; i < expression.size(); i++){
		switch (expression[i]){
			case '*': {
				tmp = (st.top()) * (expression[++i] - '0');
				st.pop();
				st.push(tmp);
				break;
			}
			case '+':{
				break;
			}
			default:
				st.push(expression[i] - '0');
		}
	}

	while (!st.empty()){
		firstRaw += st.top();
		st.pop();
	}

	//cal secondRaw
	secondRaw = expression[0] - '0';
	for (int i = 1; i < expression.size(); i++){
		switch (expression[i]){
		case '*': {
					  secondRaw *= expression[++i] - '0';
					  break;
		}
		case '+':{
					 secondRaw += expression[++i] - '0';
					 break;
		}
		default:
			break;
		}
	}

	if (firstRaw == result){
		if (firstRaw == secondRaw)
			return 'U';
		else
			return 'M';
	}
	if (secondRaw == result)
		return 'L';

	return 'I';
}
