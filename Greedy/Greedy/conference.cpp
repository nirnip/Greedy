#include <iostream>
using namespace std;

class Confer {
	int startTime;
	int endTime;
public:
	void setStart(int start) { startTime = start; }
	void setEnd(int end) { endTime = end; }
	int getStart() { return startTime; }
	int getEnd() { return endTime; }
};

void merge(Confer list[], int left, int right);

int main() {
	int num;
	int result = 1;
	Confer* list = NULL;

	cin >> num;

	list = new Confer[num];

	int start, end;
	for (int i = 0; i < num; i++) {
		cin >> start >> end;
		list[i].setStart(start);
		list[i].setEnd(end);
	}

	merge(list, 0, num - 1);

	end = list[0].getEnd();
	for (int i = 1; i < num; i++) {
		if (list[i].getStart() >= end) {
			end = list[i].getEnd();
			result++;
		}
	}

	cout << result;
}

void merge(Confer list[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge(list, left, mid);
		merge(list, mid + 1, right);

		int fnum = left;
		int lnum = mid + 1;

		Confer* tmp = new Confer[right - left + 1];

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
			else if (list[fnum].getEnd() == list[lnum].getEnd()) {
				if (list[fnum].getStart() < list[lnum].getStart()) {
					tmp[k] = list[fnum];
					fnum++;
				}
				else {
					tmp[k] = list[lnum];
					lnum++;
				}
			}
			else if (list[fnum].getEnd() < list[lnum].getEnd()) {
				tmp[k] = list[fnum];
				fnum++;
			}
			else {
				tmp[k] = list[lnum];
				lnum++;
			}
			k++;
		}

		for (int i = 0; i <= (right - left); i++) {
			list[i + left] = tmp[i];
		}
	}
}