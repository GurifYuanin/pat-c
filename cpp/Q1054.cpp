#include<iostream>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int row, col;
	cin >> col >> row;
	int color = -1, tmp, count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//scanf("%d", &tmp);
			cin >> tmp;
			if (color == tmp) {
				count++;
			}
			else {
				if (count == 0) {
					color = tmp;
				}
				else {
					count--;
				}
			}
		}
	}
	cout << color;
	return 0;
}