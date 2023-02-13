#include <iostream>
using namespace std;

struct Date {
    int day = 0, month = 0, year = 0;
};

void Input(Date& d);
void Output(Date d);
bool LeapYear(int year);
Date findTomorrow(Date d);
Date findYesterday(Date d);
void printDaysOfTheWeek(Date d);

int main() {
    Date d;
    Input(d);
    //cout << "Tomorrow is "; Output(findTomorrow(d));
    //cout << "Yesterday is "; Output(findYesterday(d));
    cout << "The date you inputed is "; printDaysOfTheWeek(d);
    return 0;
}

void Input(Date& d) {
    int day_max[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cout << "Input day, month, year (seperated with a blank)\n";
    while (1) {
        cin >> d.day >> d.month >> d.year;
        if (d.year > 0 && d.month > 0 && d.month <= 12) {
            if (LeapYear(d.year) && d.month == 2 && d.day > 0 && d.day <= 29) break;
            if (d.day > 0 && d.day <= day_max[d.month]) break;
        }
        cout << "Error ! Try again !\n";
    }
}

void Output(Date d) {
    cout << d.day << "/" << d.month << "/" << d.year << endl;
}

bool LeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)? 1 : 0;
}

Date findTomorrow(Date d) {
    int day_max[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (LeapYear(d.year) && d.day == 28 && d.month == 2) {
        d.day++;
        return d;
    }
    if (d.day >= day_max[d.month]) {
        d.day = 1;
        if (d.month == 12) {
            d.month = 1;
            d.year++;
        }
        else 
            d.month++;
    }
    else 
        d.day++;
    return d;
}

Date findYesterday(Date d) {
    int day_max[] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d.day == 1) {
        if (d.month == 3)
            if (LeapYear(d.year))
                d.day = 29;
            else d.day = 28;
        else 
            d.day = day_max[d.month - 1];
        if (d.month == 1) {
            d.month = 12;
            d.year--;
        }
        else d.month--;
    }
    else d.day--;
    return d;
}

void printDaysOfTheWeek(Date d) {
    Date mark;
    mark.day = 1;
    mark.month = 1;
    mark.year = 2023;
    int day = 8;
    string day_name[] = {"", "", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    if (d.year < 2023) 
        while(mark.day != d.day || mark.month != d.month || mark.year != d.year) {
            mark = findYesterday(mark);
            day--;
            if (day < 2) day = 8;
        }
    else
        while(mark.day != d.day || mark.month != d.month || mark.year != d.year) {
            mark = findTomorrow(mark);
            day++;
            if (day > 8) day = 2;
        }
    cout << day_name[day] << endl;
}
