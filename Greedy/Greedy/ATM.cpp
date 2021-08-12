#include<iostream>
using namespace std;

void merge(int list[], int left, int right);

int main() {
	int N;
	cin >> N;

	int* list = new int[N];
	for (int i = 0; i < N; i++){
		cin >> list[i];
	}

	merge(list, 0, N - 1);

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			result += list[j];
		}		
	}

	cout << result;
}

void merge(int list[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge(list, left, mid);
		merge(list, mid+1, right);

		int fnum = left;
		int lnum = mid + 1;

		int* tmp = new int[right - left + 1];

		int k = 0;
		while (k <= (right - left)) {
			if (fnum > mid) {
				tmp[k] = list[lnum];
				lnum++;
			}
			else if (lnum > right) {
				tmp[k] = list[fnum];
				fnum++;
			}
			else if (list[fnum] < list[lnum]) {
				tmp[k] = list[fnum];
				fnum++;
			}
			else {
				tmp[k] = list[lnum];
				lnum++;
			}
			k++;
		}

		for (int i = left; i <= right; i++) {
			list[i] = tmp[i - left];
		}
	}
}