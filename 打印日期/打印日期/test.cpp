#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;



void printDate(int year, int n) {

	int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)

		days[2]++;

	int sum = 31, i = 1;

	while (sum <= n) {

		sum += days[++i];

	}

	//月份和号数

	int month = i;

	int day = days[month] - (sum - n);



	printf("%04d-%02d-%02d\n", year, month, day);

}

int main() {

	int year = 0, n = 0;

	scanf("%d %d", &year, &n);

	printDate(year, n);

	return 0;

}