#include <iostream>
#include <string>
#include <vector>


std::vector< std::string > split(std::string line, char separator, bool ignore = false)
{
    std::vector< std::string > parts;

    int rnd = 0;
    int length = line.length();
    while(rnd < length) {
        std::string temp = "";
        std::string::size_type location = 0;
        location = line.find(separator);

        if (location != std::string::npos && location != 0) {
            int place = location;
            temp += line.substr(0, place);
            parts.push_back(temp);
            line.erase(0, place+1);
        } else if (location != std::string::npos && location == 0) {
            int place = location;

            if (ignore == false) {
                if (line.length() == 1) {
                    parts.push_back(" ");
                }
                temp += " ";
                parts.push_back(temp);
                line.erase(0, place+1);
            } else {
                line.erase(0, place+1);
            }
        } else {
            if (line.length() != 0) {
                temp += line;
                parts.push_back(temp);
                line.erase(0);
            }
        }

        ++rnd;
    }

    return parts;
}


int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
