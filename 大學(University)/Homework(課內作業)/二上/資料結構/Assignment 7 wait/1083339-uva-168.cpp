#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

typedef vector<char> vc;
vector<vc> arr(26);
int k;
int book[26];
stack<char> sk;
void dfs(char m, char t) {
	stack<char>().swap(sk);
	sk.push(t);
	int i;
	while (!sk.empty()) {
		int cnt = sk.size() - 1;
		if (cnt > 0 && cnt % k == 0) {
			printf("%c ", sk.top());
			book[sk.top() - 'A'] = 1;
		}
		vc& v = arr[m - 'A'];
		for (i = 0; i < v.size(); i++) {
			if (v[i] != sk.top() && book[v[i] - 'A'] == 0) {
				sk.push(m);
				m = v[i];
				break;
			}
		}
		if (i == v.size()) {
			printf("/%c\n", m);
			break;
		}
	}
	return;
}
int main() {
	string s;
	char M='\0', T='\0';
	while (getline(cin, s)) {
		if (s[0] == '#') break;
		memset(book, 0, sizeof(book));
		arr.assign(26, vc());
		for (int i = 0; s[i];) {
			if (s[i] == ':') {
				char a = s[i - 1];
				int j = i + 1;
				while (s[j] != ';' && s[j] != '.')
					arr[a - 'A'].push_back(s[j++]);
				i = j + 1;
			}
			else if (s[i] == ' ') {
				M = s[i + 1];
				T = s[i + 3];
				sscanf_s(s.c_str() + i + 4, "%d", &k);
				break;
			}
			else i++;
		}

		dfs(M, T);
	}
}