#include <iostream>
#include <string.h>

using namespace std;
int indexOf(char *str, char target);
void output(char *str, int sig, int start);
int findStart(char *str);
int main() {
	int sig, start1, start2, dotStart1, dotStart2, len1, len2, upper;
	bool flag = true;
	char num1[100], num2[100];
	cin >> sig >> num1 >> num2;
	upper = sig;
	len1 = strlen(num1);
	len2 = strlen(num2);
	start1 = findStart(num1);
	start2 = findStart(num2);
	dotStart1 = indexOf(num1, '.');
	dotStart2 = indexOf(num2, '.');
	if (len1 - start1 < sig) {
		if (dotStart1 == 0 && len1 < sig) {
			num1[len1] = '.';
			for (int i = len1 + 1; i <= start1 + sig; i++) {
				num1[i] = '0';
			}
			num1[start1 + sig + 1] = '\0';
		}
		else {
			for (int i = len1; i < start1 + sig; i++) {
				num1[i] = '0';
			}
			num1[start1 + sig] = '\0';
		}

	}
	if (len2 - start2 < sig) {
		if (dotStart2 == 0 && len2 < sig) {
			num2[len2] = '.';
			for (int i = len2 + 1; i <= start2 + sig; i++) {
				num2[i] = '0';
			}
			num2[start2 + sig + 1] = '\0';
		}
		else {
			for (int i = len2; i < start2 + sig; i++) {
				num2[i] = '0';
			}
			num2[start2 + sig] = '\0';
		}

	}
	for (int i = 0; i < upper; i++) {
		if (num1[start1 + i] != num2[start2 + i]) {
			flag = false;
			break;
		}
		else {
			if (num1[start1 + i] == '.' && num2[start2 + i] == '.') {
				upper++;
			}
		}
	}
	if (flag) {
		if (dotStart1 != 0 && dotStart2 != 0) {
			if (start1 != start2) {
				flag = false;
			}
		}
		else {
			if (dotStart1 == 0) {
				if (num2[dotStart2 - 1] == '0') {
					flag = false;
				}
			}
			if (dotStart2 == 0) {
				if (num1[dotStart1 - 1] == '0') {
					flag = false;
				}
			}
		}
	}
	if (flag) {
		cout << "YES";
		output(num1, sig, start1);
	}
	else {
		cout << "NO";
		output(num1, sig, start1);
		output(num2, sig, start2);

	}
	return 0;
}
int indexOf(char *str, char target) {
	int index = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] == target) {
			index = i;
			break;
		}
	}
	return index;
}
int findStart(char *str) {
	int index = 0, len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] != '0' && str[i] != '.') {
			return index;
		}
		else {
			index++;
		}
	}
	return index;
}
void output(char *str, int sig, int start) {
	int len = strlen(str);
	cout << " 0.";
	for (int i = 0; i < sig; i++) {
		if (str[start + i] != '.') {
			cout << str[start + i];
		}
		else {
			sig++;
		}
	}
	if (strchr(str, '.') == NULL) {
		cout << "*10^" << len;
	}
	else {
		cout << "*10^" << indexOf(str, '.') - start + 1;
	}
}