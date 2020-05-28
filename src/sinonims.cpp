#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>

using namespace std;

bool check_word(map<string, vector<string>>& sl, string& word1, string& word2) {
	for (auto& x : sl[word1]) {
		if (x == word2) {
			return false;
		}
	}
	return true;
}

void add_words(map<string, vector<string>>& sl) {
	string word1, word2;
	cin >> word1 >> word2;
	if (check_word(sl, word1, word2)) {
		sl[word1].push_back(word2);
	}
	if (check_word(sl, word2, word1)) {
		sl[word2].push_back(word1);
	}
}

void count_word(map<string, vector<string>>& sl) {
	string word;
	cin >> word;
	if (sl.count(word) == 0) {
		sl.erase(word);
		cout << "0" << endl;
	} else {
		cout << sl[word].size() << endl;
	}
}

void check_word(map<string, vector<string>>& sl) {
	string word1, word2;
	int zzz = 0;
	cin >> word1 >> word2;
	for (auto& x : sl[word1]) {
		if (x == word2) {
			cout << "YES" << endl;
			zzz = 1;
			break;
		}
	}
	if (zzz == 0) {
		for (auto& x : sl[word2]) {
			if (x == word1) {
				cout << "YES" << endl;
				zzz = 1;
				break;
			}
		}
	}
	if (zzz == 0) {
		cout << "NO" << endl;
	}
}

int main() {
	map<string, vector<string>> sl;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string cmd;
		cin >> cmd;
		if (cmd == "ADD") {
			add_words(sl);
		} else if (cmd == "COUNT") {
			count_word(sl);
		} else if (cmd == "CHECK") {
			check_word(sl);
		}
	}
	return 0;
}
