#include <iostream>
#include <cmath>

using namespace std;

int check_balls(int balls, int drawn)
{
    int continued = 1;

    if (balls < 0 or drawn < 0) {
        cout << "The number of balls must be a positive number." << endl;
        continued = 0;
    } else if (drawn > balls) {
        cout << "The maximum number of drawn balls is the total amount of balls." << endl;
        continued = 0;
    }

    return continued;
}

int count_balls(int balls, int drawn)
{
    unsigned long int odds = 0;

    unsigned long int n = balls;
    int rnd = balls;
    while (rnd > 1) {
        --rnd;
        n *= rnd;
    }
    if (balls == 1 or balls == 0) {
        n = 1;
    }

    unsigned long int p = drawn;
    rnd = drawn;
    while (rnd > 1) {
        --rnd;
        p *= rnd;
    }
    if (drawn == 1 or drawn == 0) {
        p = 1;
    }

    unsigned long int np = balls - drawn;
    rnd = balls - drawn;
    while (rnd > 1) {
        --rnd;
        np *= rnd;
    }
    if (balls - drawn == 1 or balls - drawn == 0) {
        np = 1;
    }

    odds = n / (np * p);

    return odds;
}

int main()
{
    int balls = 0;
    cout << "Enter the total number of lottery balls: ";
    cin >> balls;

    int drawn = 0;
    cout << "Enter the number of drawn balls: ";
    cin >> drawn;

    int continued = check_balls(balls, drawn);
    if (continued == 0) {
        return 0;
    }

    unsigned long int odds = count_balls(balls, drawn);

    cout << "The probability of guessing all " << drawn << " balls correctly is 1/" << odds << endl;

    return 0;
}
