#include <iostream>
#include <cctype>

//abcdefghijklmnopqrstuvwzyx

using namespace std;

int check_key(string key)
{
    if (key.length() != 26) {
        cout << "Error! The encryption key must contain 26 characters." << endl;
        return 0;
    }

    int rnd = 0;
    while (rnd < 26) {
        if (isupper(key[rnd])) {
            cout << "Error! The encryption key must contain only lower case characters." << endl;
            return 0;
        }
        ++rnd;
    }

    rnd = 0;
    while (rnd < 26) {
        int where = key.find(key[rnd]);
        int where2 = key.rfind(key[rnd]);
        if (where != where2) {
            cout << "Error! The encryption key must contain all alphabets a-z." << endl;
            return 0;
        }
        ++rnd;
    }

    return 1;
}

string encryption(string tobe, string key)
{
    string product = "";

    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    int length = tobe.length();
    int rnd = 0;
    int waba = 0;
    while (rnd < length) {
        string::size_type location = tobe.find(alphabet[rnd]);
        if (location == string::npos) {
            waba += 1;
        } else {
            product += key[rnd];
            waba += 1;
        }
        if (waba > 10) {
            rnd += 1;
        }
    }

    return product;
}

int main()
{
    string key = "";
    cout << "Enter the encryption key: ";
    cin >> key;

    int continued = check_key(key);
    if (continued == 0) {
        return EXIT_FAILURE;
    }
    string tobe = "";
    cout << "Enter the text to be encrypted: ";
    cin >> tobe;
    int rnd = 0;
    string::size_type length = 0;
    length = tobe.length();
    while (rnd < (int)length) {
        if (isupper(tobe[rnd])) {
            cout << "Error! The text to be encrypted must contain only lower case characters." << endl;
            return EXIT_FAILURE;
        }
        ++rnd;
    }

    for (int i = 0; i<(int)length; ++i) {
        int maa = static_cast<int>(tobe[i]);
        maa -=97;
        char uusi_kirjain = key.at(maa);

        tobe[i]=uusi_kirjain;
    }
//   string product = encryption(tobe, key);

    cout << "Encrypted text: " << tobe << endl;

    return 0;
}
