#include <iostream>
#include <string>
#include <ctime>
using namespace std;
bool checkyearbirthd(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}
bool checkyear(int currentYear) {
	if (currentYear % 4 == 0) {
		if (currentYear % 100 == 0) {
			if (currentYear % 400 == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}
void main() {
	setlocale(LC_ALL, "RU");
	int day, month, year, dayone = 0, monthone = 0;
	string date;
	int everymonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (true) {
		cout << "������� ���� �������� � ������� ��������: ";
		cin >> date;
		if (size(date) != 8 || cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "���� ������� �� ���������" << endl;
			exit(0);
		}
		year = stoi(date.substr(4, 4));
		day = stoi(date.substr(0, 2));
		month = stoi(date.substr(2, 2));
		if (checkyearbirthd(year)) {
			int everymonth[1] = { 29 };
		}
		else {
			if (day == 29) {
				cout << "������ ������� �����������." << endl;
				exit(0);
			}
		}
		if (day < 10) {
			dayone = stoi(date.substr(1, 1));
			day = dayone;
		}
		for (int i = 0; i < 12; i++) {
			if (day >= 1 && day <= everymonth[i]) {
				break;
			}
			else {
				cout << "������ ������� �����������" << endl;
				exit(0);
			}

		}
		if (month < 10) {
			monthone = stoi(date.substr(3, 1));
			month = monthone;
		}
		if (month >= 1 && month <= 12) {

		}
		else {
			cout << "������ ������� �����������" << endl;
			exit(0);
		}
		break;
	}
	int dayNum = 0;
	for (int i = 0; i < month - 1; ++i) {
		dayNum += everymonth[i];
	}
	dayNum += day;
	string currentdate;
	int currentDay, currentMonth, currentYear, currentDayOne = 0, currentMonthOne = 0;
	while (true) {
		cout << "������� ����������� ���� � ������� ��������: ";
		cin >> currentdate;
		if (size(currentdate) != 8 || cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "���� ������� �� ���������" << endl;
			exit(0);
		}
		currentDay = stoi(currentdate.substr(0, 2));
		currentMonth = stoi(currentdate.substr(2, 2));
		currentYear = stoi(currentdate.substr(4, 4));
		if (checkyear(currentYear)) {
		}
		else {
			if (currentDay == 29) {
				cout << "������ ������� �����������. " << endl;
				exit(0);
			}
		}
		if (currentDay < 10) {
			currentDayOne = stoi(date.substr(1, 1));
			currentDay = currentDayOne;
		}
		for (int i = 0; i < 12; i++) {
			if (currentDay >= 1 && currentDay <= everymonth[i]) {
				break;
			}
			else {
				cout << "������ ������� �����������" << endl;
				exit(0);
			}
			return;
		}
		if (currentMonthOne < 10) {
			monthone = stoi(date.substr(3, 1));
			currentMonthOne = monthone;
		}
		if (currentMonth >= 1 && currentMonth <= 12) {

		}
		else {
			cout << "������ ������� �����������" << endl;
			exit(0);
		}
		break;
	}
	if (currentYear < year) {
		cout << "������ ����� ���� ��������." << endl;
		exit(0);
	}
	int currentDayNum = 0;
	for (int i = 0; i < currentMonth - 1; ++i) {
		currentDayNum += everymonth[i];
	}
	currentDayNum += currentDay;
	cout << "���������� ����� ��� � ���� ����: " << currentDayNum << endl;
	if (checkyear(currentYear)) {
		cout << "������� ��� ����������" << endl;
	}
	else {
		cout << "������� ��� �� ����������" << endl;
	}
	cout << "���������� ����� ��� � ��� ��������: " << dayNum << endl;
	if (checkyear(year)) {
		cout << "��� �������� ����������" << endl;
	}
	else {
		cout << "��� �������� �� ����������" << endl;
	}
	int noLeapYear = 365;
	int leapYear = 366;
	int a = 0;
	int difference = 0;
	if (!checkyear(currentYear) and !checkyearbirthd(year)) {
		if (currentDay < day) {
			difference = dayNum - currentDayNum;
			cout << "�� ���������� ��� �������� ��������: " << difference << " ����" << endl;
		}
		else {
			difference = noLeapYear - dayNum - currentDayNum;
			cout << "�� ���������� ��� �������� ��������: " << difference << " ����" << endl;
		}
	}
	else if (checkyearbirthd(year)) {
		if (day == 29 && month == 2) {
			while (true) {
				if (currentYear % 4 != 0) {
					currentYear++;
					a++;
				}
				else {
					break;
				}
			}
			if (currentYear == year) {
				difference = 4 * noLeapYear + dayNum - currentDayNum;
				cout << "�� ���������� ��� �������� ��������: " << abs(difference) << " ����" << endl;

			}
			else {
				if (currentDayNum > dayNum) {
					a = 1;
				}
					difference = a * noLeapYear + dayNum - currentDayNum;
					cout << "�� ���������� ��� �������� ��������: " << abs(difference) << " ����" << endl;
				
			}
		}
		else {
			if (currentDay > day) {
				difference = dayNum - currentDayNum;
				cout << "�� ���������� ��� �������� ��������: " << abs(difference) << endl;
			}
			else {
				difference = noLeapYear - dayNum - currentDayNum;
				cout << "�� ���������� ��� �������� ��������: " << abs(difference) << " ����" << endl;
			}
		}
	}
	else if (checkyear(currentYear)) {
		if (currentDay > day) {
			difference = dayNum - currentDayNum;
			cout << "�� ���������� ��� �������� ��������: " << abs(difference) << endl;
		}
		else {
			difference = noLeapYear - dayNum - currentDayNum;
			cout << "�� ���������� ��� �������� ��������: " << abs(difference) << " ����" << endl;
		}
	}
}
