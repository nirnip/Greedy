#include <iostream>

int main() {
	int N;
	unsigned long long distance[100003];
	unsigned long long fprice = 0;
	unsigned long long lprice = 0;

	scanf("%d", &N);

	unsigned long long result = 0;
	for (int i = 0; i < N - 1; i++) {
		scanf("%llu", &distance[i]);
	}

	for (int i = 0; i < N; i++) {
		if (i == N - 1) {
			scanf("%llu", &lprice);
			break;
		}
		if (!i) {
			scanf("%llu", &fprice);
		}
		else {
			scanf("%llu", &lprice);
			if (lprice < fprice) {
				fprice = lprice;
			}
		}
		result += fprice * distance[i];
	}
	printf("%llu", result);
}