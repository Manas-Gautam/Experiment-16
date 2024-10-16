//Name: - Manas Gautam
//PRN: - 23070123081
//Batch: - E&Tc {B}

// Experimnet 16 A: -

#include<iostream>
using namespace std;

int main() {
    float a;
    cout << "Enter a positive number: ";
    cin >> a;

    try {
        if (a < 0) {
            throw a;
        } else {
            cout << "The number is: " << a << endl;
        }
    } catch (const float n) {
        cout << "You entered " << a << " which is a negative number: " << n << endl;
    }
    return 0;
}


// Experimnet 16 B: -

#include<iostream>
using namespace std;

int main() {
    int year;
    cout << "Enter year greater than 2000: ";
    cin >> year;

    try {
        if (year < 2000) {
            throw "You entered a year less than 2000";
        } else {
            cout << "Entered year is: " << year << endl;
        }
    } catch (const char* msg) {
        cout << msg << endl;
    }
    return 0;
}
