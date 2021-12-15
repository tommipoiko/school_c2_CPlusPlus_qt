#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int number = 0;
    cout << "Enter a number: ";
    cin >> number;

    int calculated = number * number * number;
    if (cbrt(calculated) == number) {
        cout << "The cube of " << number << " is " << calculated << "." << endl;
    } else {
        cout << "Error! The cube of " << number << " is not " << calculated << "." << endl;
    }

    return 0;
}
