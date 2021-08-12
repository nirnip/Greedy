#include <iostream>

using namespace std;

int N, K;

int main() {
    scanf("%d %d", &N, &K);

    int* num = new int[N + 1];
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < N; i++) {
        printf("%d\n", num[i]);
    }

    int sum = 0; //최대 나눌 수 있는 수
    for (int i = 0; i < N; i++) {
        if (num[i] == 1) {
            break;
        }
        else if (K / num[i] == 0) {
            sum = i - 1;
            printf("%d. : K= %d sum = %d num[i] = %d", i, K, sum, num[i]);
            break;
        }
    }
    printf("sum : %d\n", sum);

    int number = 0; //동전 개수
    while (K != 0) {
        number += K / num[sum];
        K = K % num[sum--];
        printf("K= %d sum = %d num[sum] = %d\n", K, sum, num[sum]);
    }

    printf("%d", number);

    delete[] num;
    return 0;
}

/* 내 코드 */
//#include <iostream>
//using namespace std;
//
//int main() {
//	int type, price;
//	int result = 0;
//	int* list = NULL;
//
//	cin >> type >> price;
//
//	list = new int[type];
//
//	for (int i = 0; i < type; i++) {
//		cin >> list[i];
//	}
//
//	for (int i = type - 1; i >= 0; i--) {
//		if (!price) { break; }
//		while (list[i] <= price) {
//			price -= list[i];
//			result++;
//		}
//	}
//
//	cout << result;
//}

