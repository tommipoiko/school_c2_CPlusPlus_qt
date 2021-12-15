#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int main()
{
    string file_from = "";
    map<string, int> points;

    cout << "Input file: ";
    getline(cin, file_from);

    ifstream from(file_from);
    if (not from) {
        cout << "Error! The file " << file_from << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }

    string row;

    while (getline(from, row)) {
        int location = row.find(":");
        string name;

        name += row.substr(0, location);
        row.erase(0, location+1);
        if (points.find(name) != points.end()) {
            points.at(name) += stoi(row);
        } else {
            points.insert({name, stoi(row)});
        }
    }

    from.close();

    cout << "Final scores:" << endl;

    map<string, int>::iterator start;
    start = points.begin();
    while (start != points.end()) {
        cout << start->first << ": " << start->second << endl;
        ++start;
    }

    return EXIT_SUCCESS;
}
