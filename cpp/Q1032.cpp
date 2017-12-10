#include<iostream>
int main() {
	int s1, s2, num, tmp;
	char c;
	scanf("%d%d%d", &s1, &s2, &num);
	int next[100005];
	char ch[100005];
	bool visited[100005] = {false};
	for (int i = 0; i < num; i++) {
		scanf("%d", &tmp);
		scanf("%c%c", &ch[tmp], &c);
		scanf("%d", &next[tmp]);
	}
	while (s1 != -1) {
		visited[s1] = true;
		s1 = next[s1];
	}
	while (s2 != -1 && visited[s2] == false) {
		s2 = next[s2];
	}
	if (s2 != -1) {
		printf("%05d", s2);
	}
	else {
		printf("%d", -1);
	}
	return 0;
}

