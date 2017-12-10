#include<iostream>
using namespace std;

int main() {
	int g1, s1, k1, g2, s2, k2;
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	k1 += k2;
	if (k1 >= 29) {
		s1++;
		k1 %= 29;
	}
	s1 += s2;
	if (s1 >= 17) {
		g1++;
		s1 %= 17;
	}
	g1 += g2;
	printf("%d.%d.%d", g1, s1, k1);
	return 0;
}