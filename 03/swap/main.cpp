#include <cstdlib>
#include <iostream>

using namespace std;

void swap(int& i, int& j)
{
    int temp = 0;
    temp = i;
    i = j;
    j = temp;
}

#ifndef UNIT_TESTING
int main()
{
    cout << "Enter an integer: ";
    int i = 0;
    cin >> i;

    cout << "Enter another integer: ";
    int j = 0;
    cin >> j;

    swap(i, j);
    cout << "The integers are " << i << " and " << j << endl;

    return EXIT_SUCCESS;
}
#endif
