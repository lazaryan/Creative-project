#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    time_t rawtime;
    struct tm *timeinfo;
    char arr [50];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(arr, 50, "Время: %H:%M:%S", timeinfo);
    cout << arr << endl;
    return 0;
}
