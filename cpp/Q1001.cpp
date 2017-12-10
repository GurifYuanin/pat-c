#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char arr[10], newArr[20];
	int num1, num2, sum, len, tail;
	cin >> num1 >> num2;
	sum = num1 + num2;
	sprintf(arr, "%d", sum);
	if (arr[0] == '-') {
		cout << "-";
		len = strlen(arr);
		for (int i = 0; i < len - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[len - 1] = '\0';
	}
	len = strlen(arr);
	for (int i = len - 1, j = 0; i >= 0; j++) {
		if ((j + 1) % 4 == 0) {
			newArr[j] = ',';
		}
		else {
			newArr[j] = arr[i];
			i--;
		}
		tail = j;
	}
	len = tail + 1;
	for (int i = len - 1; i >= 0; i--) {
		cout << newArr[i];
	}
	return 0;
}