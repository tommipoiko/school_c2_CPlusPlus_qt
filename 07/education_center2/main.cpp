//--------------------------------------------------
//  COMP.CS.110 Ohjelmointi 2: Rakenteet -pohjakoodi
//  Copyright © 2021
//--------------------------------------------------


/*Projektin kuvaus:
 *Ohjelmalla pyritään mallintamaa eräänlaista kurssitietojen tallennus- ja luku-
 *järjestelmmää. Ohjelman alussa pyydetään käyttäjää syöttämään jonkin luettavan
 *tiedoston nimi, joka sitten pyritään lukemaan.
 *Tiedot tallennetaan sen jälkeen tietorakenteeseen nimeltä 'themes'. Tietorakenne
 *on muotoa map, josta löytyy teeman nimellä vektori kaikista sen kursseista. Vek-
 *tori sisältää Course-structeja.
 *Ohjelmassa toimii käyttöliittymä, jossa voidaan lukea ja rajallisesti muokata
 *tietorakenteen tietoja.
 *
 *Kirjoittaja:
 *Tommi Poikolainen
 *050093232
 *tommi.poikolainen@tuni.fi
*/
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

//Struct toimii osana ohjelman tietorakennetta. Struct on toteutettu projektin
//ohjeiden mukaan.
struct Course {
    string name;
    string location;
    int enrollments;
};

vector<string> split_ignoring_quoted_delim(const string& str,
                                                     char delimiter)
{
    vector<string> result = {""};
    bool inside_quotation = false;
    for(char current_char : str)
    {
        if(current_char == '"')
        {
            inside_quotation = not inside_quotation;
        }
        else if(current_char == delimiter and not inside_quotation)
        {
            result.push_back("");
        }
        else
        {
            result.back().push_back(current_char);
        }
    }
    if(result.back() == "")
    {
        result.erase(--result.end());
    }
    return result;
}

void print_themes(map<string, vector<Course>> theme)
//Funktio tulostaa kaikki ohjelmassa/tietorakenteessa esiintyvät teemat.
{
    for (auto key : theme) {
        cout << key.first << endl;
    }
}

void print_courses(map<string, vector<Course>> theme, vector<string> command)
//Tulostaa paikkakunnalta ja teemasta löytyvät kurssit. Parametreina
//esiintyy tietorakenne ja osiin jaettava komentorivi.
{
    if (command.size() != 3) {
        cout << "Error: error in command " << command.at(0) << endl;
        return;
    } else if (theme.find(command.at(2)) == theme.end()) {
        cout << "Error: unknown theme" << endl;
        return;
    }
    map<string, int> temporary;
    for (auto course : theme.at(command.at(2))) {
        if (course.location == command.at(1)) {
            temporary.insert({course.name, course.enrollments});
        }
    }
    for (auto key : temporary) {
        if (key.second < 50) {
            cout << key.first << " --- " << key.second << " enrollments" << endl;
        } else {
            cout << key.first << " --- full" << endl;
        }
    }
}

bool compare(string a, string b) {return a<b;}
//Vertailufunktio vektorien aakkosjärjestykseen asettamiseksi.

void print_available(map<string, vector<Course>> theme)
//Tulostetaan jokainen kurssi, mihin mahtuu lisää ihmisiä. Parametrina
//esiintyy tietorakenne.
{
    vector<string> to_print;
    for (auto teema : theme) {
        map<string, vector<string>> loca_name = {};
        for (auto course : teema.second) {
            if (course.enrollments < 50) {
                if (loca_name.find(course.location) != loca_name.end()) {
                    loca_name.at(course.location).push_back(course.name);
                } else {
                    loca_name.insert({course.location, {course.name}});
                }
            }
        }
        for (auto a : loca_name) {
            for (auto b : a.second) {
                string line;
                line += teema.first + " : " + a.first + " : " + b;
                if (find(to_print.begin(), to_print.end(), line) == to_print.end()) {
                    to_print.push_back(line);
                }
            }
        }
    }
    sort(to_print.begin(), to_print.end(), compare);
    for (auto line : to_print) {
        cout << line << endl;
    }
}

void print_courses_in_theme(map<string, vector<Course>> theme, vector<string> command)
//Tulostetaan komentoparametrista selville saatavasta teemasta jokainen
//kurssi. Parametreina toimii tietorakenne ja komentorivi, joka jaetaan
//asianmukaisiin osiin.
{
    if (command.size() != 2) {
        cout << "Error: error in command " << command.at(0) << endl;
        return;
    } else if (theme.find(command.at(1)) == theme.end()) {
        cout << "Error: unknown theme" << endl;
        return;
    }
    map<string, vector<string>> to_print;
    vector<string> lines;
    for (auto course : theme.at(command.at(1))) {
        if (to_print.find(course.location) != to_print.end()) {
            to_print.at(course.location).push_back(course.name);
        } else {
            to_print.insert({course.location, {course.name}});
        }
    }
    for (auto loca : to_print) {
        for (auto course : loca.second) {
            string line;
            line += loca.first + " : " + course;
            if (find(lines.begin(), lines.end(), line) == lines.end()) {
                lines.push_back(line);
            }
        }
    }
    for (auto line : lines) {
        cout << line << endl;
    }
}

void print_courses_in_location(map<string, vector<Course>> theme, vector<string> command)
//Tulostetaan komentoparametrista selville saatavalta paikkakunnalta jokainen
//kurssi. Parametreina toimii tietorakenne ja komentorivi, joka jaetaan
//asianmukaisiin osiin.
{
    if (command.size() != 2) {
        cout << "Error: error in command " << command.at(0) << endl;
        return;
    }
    vector<string> locations;
    for (auto teema : theme) {
        for (auto course : teema.second) {
            locations.push_back(course.location);
        }
    }
    if (find(locations.begin(), locations.end(), command.at(1)) == locations.end()) {
        cout << "Error: unknown location" << endl;
        return;
    }
    vector<string> courses;
    for (auto teema : theme) {
        for (auto course : teema.second) {
            if (course.location == command.at(1)) {
                if (find(courses.begin(), courses.end(), course.name) == courses.end()) {
                    courses.push_back(course.name);
                }
            }
        }
    }
    sort(courses.begin(), courses.end(), compare);
    for (auto line : courses) {
        cout << line << endl;
    }
}

void print_favorite(map<string, vector<Course>> theme)
//Selvitetään ja tulostetaan suosituimmat teemat. Parametrina toimii tietorakenne.
{
    vector<map<string, int>> people;
    int highest = 0;
    vector<string> test;
    for (auto teema : theme) {
        int sum = 0;
        for (auto course : teema.second) {
            string row;
            row += teema.first + course.name + course.location;
            if (find(test.begin(), test.end(), row) == test.end()) {
                test.push_back(row);
                sum += course.enrollments;
            }
        }
        if (sum > highest) {
            highest = sum;
        }
        people.push_back({{teema.first, sum}});
    }
    if (highest == 0) {
        cout << "No enrollments" << endl;
        return;
    }
    vector<string> to_print;
    for (auto themes : people) {
        for (auto teema : themes) {
            string line;
            if (teema.second == highest) {
                line += "--- " + teema.first;
                to_print.push_back(line);
            }
        }
    }
    cout << highest << " enrollments in themes" << endl;
    sort(to_print.begin(), to_print.end(), compare);
    for (auto line : to_print) {
        cout << line << endl;
    }
}

map<string, vector<Course>> cancel_course(map<string, vector<Course>> theme, vector<string> command)
//Kurssin peruutuksen funktio. Parametreina tietorakenne, sekä komentorivi, joka jaetaan
//asianmukaisiin osiin. Palautustuotteena toimii onnistuneessa tilanteessa muokattu
//tietorakenne.
{
    if (command.size() != 2) {
        cout << "Error: error in command " << command.at(0) << endl;
        return theme;
    }
    vector<string> names;
    for (auto teema : theme) {
        for (auto course : teema.second) {
            names.push_back(course.name);
        }
    }
    if (find(names.begin(), names.end(), command.at(1)) == names.end()) {
        cout << "Error: unknown course" << endl;
        return theme;
    }
    for (auto& teema : theme) {
        int item = 0;
        int size = teema.second.size();
        while (item < size) {
            if (teema.second.at(item).name == command.at(1)) {
                teema.second.erase(teema.second.begin()+item);
                --size;
            } else {
                ++item;
            }
        }
    }
    cout << command.at(1) << " cancelled in all locations" << endl;
    return theme;
}

void run_program(map<string, vector<Course>>& theme)
//Ohjelman käyttöliittymä ilmenee funktiossa, sekä ohjelman varsinainen
//suoritus tapahtuu tässä. Parametrina toimii tietorakenne.
{
    while (true) {
        string line;
        cout << "> ";
        getline(cin, line);
        string limit = " ";
        char limiter = limit.at(0);
        vector<string> command = split_ignoring_quoted_delim(line, limiter);

        if (command.at(0) == "quit") {
            return;
        } else if (command.at(0) == "themes") {
            print_themes(theme);
        } else if (command.at(0) == "courses") {
            print_courses(theme, command);
        } else if (command.at(0) == "available") {
            print_available(theme);
        } else if (command.at(0) == "courses_in_theme") {
            print_courses_in_theme(theme, command);
        } else if (command.at(0) == "courses_in_location") {
            print_courses_in_location(theme, command);
        } else if (command.at(0) == "favorite_theme") {
            print_favorite(theme);
        } else if (command.at(0) == "cancel") {
            theme = cancel_course(theme, command);
        } else {
            cout << "Error: Unknown command: " << command.at(0) << endl;
        }
    }
}

map<string, vector<Course>> write_map(map<string, vector<Course>> theme, vector<string> parts)
//Parametreinä toimii tietorakenne ja tiedostosta luettu rivi. Rivi jaetaan osiin ja
//lisätään tietorakenteeseen, joka palautetaan lopuksi takaisin mainiin.
{
    int num;
    if (isdigit(parts.at(3).at(0))) {
        num = stoi(parts.at(3));
    } else {
        num = 50;
    }
    if (theme.find(parts.at(0)) != theme.end()) {
        for (auto course:theme.at(parts.at(0))) {
            if (course.name == parts.at(1)) {
                if (course.location == parts.at(2)) {
                    course.enrollments = num;
                } else {
                    theme.at(parts.at(0)).push_back({parts.at(1), parts.at(2), num});
                }
            } else {
                theme.at(parts.at(0)).push_back({parts.at(1), parts.at(2), num});
            }
        }
    } else {
        theme.insert({parts.at(0), {{parts.at(1), parts.at(2), num}}});
    }
    return theme;
}

int main()
//Luetaan tiedostoa ja siirretään rivit funktioon write_map tietorakenteeseen
//tallennusta varten. Suoritus tapahtuu tämän jälkeen.
{
    map<string, vector<Course>> theme;
    string file_from = "";
    cout << "Input file: ";
    getline(cin, file_from);
    ifstream from(file_from);
    if (not from) {
        cout << "Error: the input file cannot be opened" << endl;
        return EXIT_FAILURE;
    }
    string row;
    vector<string> parts;
    string limit = ";";
    char limiter = limit.at(0);
    while (getline(from, row)) {
        parts = split_ignoring_quoted_delim(row, limiter);
        if (parts.size() != 4) {
            cout << "Error: empty field" << endl;
            return EXIT_FAILURE;
        }
        string tname = parts.at(0);
        if (parts.at(0) == "" or parts.at(1) == "" or parts.at(2) == "") {
            cout << "Error: empty field" << endl;
            return EXIT_FAILURE;
        }
        theme = write_map(theme, parts);
    }
    run_program(theme);
    from.close();
    return EXIT_SUCCESS;
}
