#include <iostream>
#include <string>
#include <algorithm>
#include <random>

int main()
{
    // This is a random number generator that should be given as parameter to the
    // function of the algorithm library to shuffle letters
    std::minstd_rand generator;

    std::cout << "Enter some text. Quit by entering the word \"END\"." << std::endl;
    std::string word;

    while (std::cin >> word)
    {
        if (word == "END")
        {
            return EXIT_SUCCESS;
        }
        char temp_start = word.at(0);
        std::string start = "";
        std::string end = "";
        start += temp_start;
        int length = word.length();
        if (length > 1) {
            char temp_end = word.at(length-1);
            end += temp_end;
        }

        word.erase(0, 1);
        if (length > 1) {
            word.erase(length-2, 1);
        }

        shuffle(word.begin(), word.end(), generator);
        word.insert(0, start);
        if (length > 1) {
            word.insert(length-1, end);
        }
	
        std::cout << word << std::endl;
    }
}
