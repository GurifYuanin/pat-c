#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

#define SIZE 100001

int list[SIZE];

int divSearch(int number, int size) {
	int max = size, min = 0;
	int mid;
	do {
		mid = (max + min) / 2;
		if (list[mid] == number) {
			return mid;
		}
		if (list[mid] > number) {
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}
	} while (true);
}

void popList(int number, int size) {
	int index = divSearch(number, size);
	for (int i = index; i < size - 1; i++) {
		list[i] = list[i + 1];
	}
}

void pushList(int number, int size) {
	int i = size - 1;
	for (; i >= 0; i--) {
		if (number <= list[i]) {
			list[i + 1] = list[i];
		}
		else {
			break;
		}
	}
	if (i == -1) {
		i++;
	}
	list[i] = number;
}

int getMid(int size) {
	return list[(size - 1) / 2];
}

int main() {
	char command[20];
	int lineNumber, tmp;
	stack<int> stack;
	cin >> lineNumber;
	for (int i = 0; i < lineNumber; i++) {
		cin >> command;
		switch (command[1]) {
		case 'o': {
			// pop
			if (stack.empty()) {
				cout << "Invalid" << endl;
			}
			else {
				cout << stack.top() << endl;
				popList(stack.top(), stack.size());
				stack.pop();
			}
			break;
		}
		case 'e' : {
			if (stack.empty()) {
				cout << "Invalid" << endl;
			}
			else {
				cout << getMid(stack.size()) << endl;
			}
			break;
		}
		case 'u' : {
			cin >> tmp;
			pushList(tmp, stack.size());
			stack.push(tmp);
		}
		}

	}
	return 0;
}