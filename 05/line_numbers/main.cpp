#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string file_from = "";
    string file_to = "";
    cout << "Input file: ";
    getline(cin, file_from);
    cout << "Output file: ";
    getline(cin, file_to);

    ifstream from(file_from);
    if (not from) {
        cout << "Error! The file " << file_from << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }

    ofstream to;
    to.open(file_to);

    string row;
    int row_num = 1;

    while (getline(from, row)) {
        to << row_num << " " << row << endl;
        ++row_num;
    }

    from.close();
    to.close();

    return 0;
}
