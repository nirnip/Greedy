#include<iostream>
#include<string>
using namespace std;

int main() {
	int result = 0;
	string list = "";

	cin >> list;

	int k = 0;
	int digit = 0;
	int dlist[10000] = { 0, };
	bool bracket = false;
	int ibrack = 0;
	int ilast = 0;
	while (k < list.length()) {
		if (!isdigit(list[k])) {

			string substr = list.substr(ilast, k - ilast);
			int num = stoi(substr);

			ilast = k + 1;
			if (list[k] == '-') {
				if (bracket) {
					ibrack += num;
					result -= ibrack;
					ibrack = 0;
				}
				else {
					result += num;
					bracket = true;
				}
			}
			else {
				if (bracket) {
					ibrack += num;
				}
				else {
					result += num;
				}
			}
		}
		else {
			dlist[digit] = stoi(list);
			digit++;
		}
		k++;
	}


	int num = stoi(list.substr(ilast, k - ilast));


	if (list[ilast + 1] == '-') {
		result -= num;
	}
	else {
		if (bracket) {
			ibrack += num;
			result -= ibrack;
		}
		else {
			result += num;
		}
	}

	cout << result;
}