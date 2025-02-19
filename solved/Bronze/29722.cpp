#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int N;

    cin >> str >> N;
    int year = stoi(str.substr(0, 4));
    int month = stoi(str.substr(5, 2));
    int day = stoi(str.substr(8, 2));

    day += N;
    month += day/30;
    day = day%30;
    if(day==0) {
        month--;
        day=30;
    }
    year += month/12;
    month = month%12;
    if(month==0) {
        year--;
        month=12;
    }

    printf("%d-%02d-%02d", year, month, day);

    return 0;
}