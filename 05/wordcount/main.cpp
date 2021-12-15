#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <utility>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string file_from = "";
    map <string, pair <int, vector <int>>> words;

    cout << "Input file: ";
    getline(cin, file_from);

    ifstream from(file_from);
    if (not from) {
        cout << "Error! The file " << file_from << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }

    string row;
    int row_num = 1;

    while (getline(from, row)) {
        istringstream iss(row);
        string word;

        while (iss >> word) {
            if (words.find(word) != words.end()) {
                if (count(words.at(word).second.begin(), words.at(word).second.end(), row_num) == 0) {
                    words.at(word).first += 1;
                    words.at(word).second.push_back(row_num);
                }
            } else {
                pair <int, vector <int>> info (0, {});
                words.insert({word, info});
                words.at(word).first += 1;
                words.at(word).second.push_back(row_num);
            }
        }

        ++row_num;
    }

    map<string, pair <int, vector <int>>>::iterator start;
    string trow;
    int rnd = 0;
    start = words.begin();
    while (start != words.end()) {
        trow = "";
        int length = start->second.second.size();
        rnd = 0;
        while (rnd < length) {
            if (trow.length() == 0) {
                trow += to_string(start->second.second.at(rnd));
            } else {
                trow += ", ";
                trow += to_string(start->second.second.at(rnd));
            }
            ++rnd;
        }
        cout << start->first << " " << start->second.first << ": " << trow << endl;
        ++start;
    }

    from.close();

    return EXIT_SUCCESS;
}
