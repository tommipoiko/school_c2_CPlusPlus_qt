#include <iostream>

using namespace std;

int main()
{
    int amount = 0;
    cout << "How many numbers would you like to have? ";
    cin >> amount;

    int rnd = 1;
    while (rnd <= amount) {
        if (rnd % 3 == 0 && rnd % 7 == 0) {
            cout << "zip boing" << endl;
        } else if (rnd % 7 == 0) {
            cout << "boing" << endl;
        } else if (rnd % 3 == 0) {
            cout << "zip" << endl;
        } else {
            cout << rnd << endl;
        }
        ++rnd;
    }

    return 0;
}
