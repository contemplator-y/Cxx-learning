#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;



int getMonthDay(int year, int month) {

	int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 2

		&& (year % 400 == 0 || year % 4 == 0 && year % 100 != 0))

		days[2]++;



	return days[month];

}



void printDate2(int y, int m, int d, int n) {

	d -= n;

	while (d <= 0) {

		m--;

		if (m == 0) {

			m = 12;

			y--;

		}

		d += getMonthDay(y, m);

	}



	printf("%04d-%02d-%02d\n", y, m, d);

}



void printDate(int y, int m, int d, int n) {

	if (n < 0) {

		printDate2(y, m, d, -n);

		return;

	}

	d += n;

	while (d > getMonthDay(y, m)) {

		d -= getMonthDay(y, m);

		m++;

		if (m == 13) {

			m = 1;

			y++;

		}

	}

	printf("%04d-%02d-%02d\n", y, m, d);



}





int main() {

	int m, year, month, day, n;

	while (cin >> m) {

		for (int i = 0; i < m; i++) {

			cin >> year >> month >> day >> n;

			printDate(year, month, day, n);

		}

	}

	return 0;

}