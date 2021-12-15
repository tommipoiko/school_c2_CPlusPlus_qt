#include <iostream>
#include <string>
#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif

bool palindrome_recursive(std::string s)
{
  RECURSIVE_FUNC

    if (s.length() < 4) {
        if (s.front() == s.back()) {
            return true;
        } else {
            return false;
        }
    } else {
        if (s.front() == s.back()) {
            s.erase(0,1);
            s.erase(s.length()-1);
            return palindrome_recursive(s);
        }
    }
    return false;
}

#ifndef UNIT_TESTING
int main()
{
    std::cout << "Enter a word: ";
    std::string word;
    std::cin >> word;

    if(palindrome_recursive(word)){
        std::cout << word << " is a palindrome" << std::endl;
    } else {
        std::cout << word << " is not a palindrome" << std::endl;
    }
}
#endif
