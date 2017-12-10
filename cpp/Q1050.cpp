#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1, str2;
	bool table[256] = { false };
	int len1, len2;
	getline(cin, str1);
	getline(cin, str2);
	char tmp;
	len1 = str1.size();
	len2 = str2.size();
	for (int i = 0; i < len2; i++) {
		table[str2[i]] = true;
	}
	str2.clear();
	for (int i = 0; i < len1; i++) {
		tmp = str1[i];
		if (!table[tmp]) {
			str2 += tmp;
		}
	}
	cout << str2;
	return 0;
}