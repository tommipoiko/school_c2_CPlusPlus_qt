#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

const std::string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";


std::vector<std::string> split(const std::string& s, const char delimiter, bool ignore_empty = false){
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

void print_all(std::map<std::string, std::vector<std::string>> relation, std::string id, int counter)
{
    std::string start = "";
    int rnd = 0;

    while (rnd < counter) {
        start += "..";
        ++rnd;
    }

    ++counter;

    if (relation.find(id) != relation.end()) {
        std::cout << start << id << std::endl;
        for (auto i : relation.at(id)) {
            print_all(relation, i, counter);
        }
    } else {
        std::cout << start << id << std::endl;
    }
}

int count_all_parties(std::map<std::string, std::vector<std::string>> relation, std::string id, int& amount)
{
    if (relation.find(id) != relation.end()) {
        for (auto i : relation.at(id)) {
            ++amount;
            amount = count_all_parties(relation, i, amount);
        }
    }
    return amount;
}

int count_some_parties(std::map<std::string, std::vector<std::string>> relation, std::string id, int& amount, int& longest, std::string starting)
{
    if (relation.find(id) != relation.end()) {
        for (auto i : relation.at(id)) {
            ++amount;
            amount = count_some_parties(relation, i, amount, longest, starting);
            if (amount > longest) {
                longest = amount;
            }
            --amount;
        }
    }
    if (id == starting) {
        return longest;
    }
    return amount;
}

int main()
{
    std::map<std::string, std::vector<std::string>> relation;


    while(true){
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        std::string command = parts.at(0);

        if(command == "S" or command == "s"){
            if(parts.size() != 3){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);

            if (relation.find(id1) != relation.end()) {
                relation.at(id1).push_back(id2);
            } else {
                std::vector<std::string> recruited;
                recruited.push_back(id2);
                relation.insert({id1, recruited});
            }

        } else if(command == "P" or command == "p"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            int counter = 0;
            print_all(relation, id, counter);

        } else if(command == "C" or command == "c"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            int amount = 0;
            amount = count_all_parties(relation, id, amount);
            std::cout << amount << std::endl;

        } else if(command == "D" or command == "d"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            int amount = 1;
            int longest = 1;
            std::string starting = id;
            amount = count_some_parties(relation, id, amount, longest, starting);
            std::cout << amount << std::endl;

        } else if(command == "Q" or command == "q"){
           return EXIT_SUCCESS;
        } else {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
