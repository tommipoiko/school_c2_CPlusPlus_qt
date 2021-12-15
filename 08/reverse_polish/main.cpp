#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    string input;
    cout << "Input an expression in reverse Polish notation (end with #):" << endl;
    cout << "EXPR> ";
    getline(cin, input);

    istringstream iss (input);

    char n;
    vector<int> lista;
    while (iss) {
        iss >> n;

        if (n == '#') {
            break;
        }

        if (isdigit(n)) {
            int lisa = stoi(string(1, n));
            lista.push_back(lisa);
        } else {

            if (lista.size() == 0) {
                cout << "Error: Expression must start with a number" << endl;
                return EXIT_FAILURE;
            }

            if (lista.size() < 2) {
                cout << "Error: Too few operands" << endl;
                return EXIT_FAILURE;
            }

            int tulos = lista.at(lista.size()-2);
            if (n == '+') {
                tulos += lista.back();
            } else if (n == '-') {
                tulos -= lista.back();
            } else if (n == '*') {
                tulos *= lista.back();
            } else if (n == '/') {
                if (lista.back() == 0) {
                    cout << "Error: Division by zero" << endl;
                    return EXIT_FAILURE;
                } else {
                    tulos /= lista.back();
                }
            } else {
                cout << "Error: Unknown character" << endl;
                return EXIT_FAILURE;
            }
            lista.pop_back();
            lista.pop_back();
            lista.push_back(tulos);
        }
    }

    if (lista.size() == 1) {
        cout << "Correct: " << lista.front() << " is the result" << endl;
        return EXIT_SUCCESS;
    } else {
        cout << "Error: Too few operators" << endl;
        return EXIT_FAILURE;
    }
}
