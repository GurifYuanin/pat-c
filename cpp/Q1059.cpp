#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long int number = 0;
	int time = 1, upper = 0, len = 0;
	int arr[32];
	cin >> number;
	cout << number << "=";
	if (number < 4) {
		cout << number;
		return 0;
	}
	upper = sqrt(number);
	for (int i = 2, j = 0; i <= upper;) {
		if (number % i == 0) {
			number /= i;
			arr[j] = i;
			j++;
			len++;
		}
		else {
			i++;
		}
	}
	for (int i = 0; i < len - 1; i++) {
		if (arr[i] != arr[i + 1]) {
			if (time > 1) {
				cout << arr[i] << "^" << time << "*";
			}
			else {
				cout << arr[i] << "*";
			}
			time = 1;
		}
		else {
			time++;
		}
	}
	if (time > 1) {
		cout << arr[len - 1] << "^" << time;
	}
	else {
		cout << arr[len - 1];
	}
	return 0;
}