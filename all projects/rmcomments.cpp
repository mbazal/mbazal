
/*
#include <cstdio> // printf and friends
// strings might help if you want to do a nice job removing whitespace
#include <iostream>
using std::string;
using std::cout;
using std::cin;
 
string newState(string oldState)
{
    int n = oldState.length();
    string erase;

    bool commentA, commentB = false;
 
    for (int i = 0; i < n; i++)
    {
        if (commentA == true && oldState[i] == '\n')
            commentA = false;
 
        else if  (commentB == true && oldState[i] == '*' && oldState[i+1] == '/')
            commentB = false,  i++;
 
        else if (commentA || commentB)
            continue;
 
        else if (oldState[i] == '/' && oldState[i+1] == '/')
            commentA = true, i++;
        else if (oldState[i] == '/' && oldState[i+1] == '*')
            commentB = true,  i++;
 
        else erase
         += oldState[i];
    }
    return erase;
}
 
int main()
{
    string input;

    getline (cin,input);
    
    cout << newState(input);
    
    return 0;
}
*/



#include <iostream>
#include <string>

std::string removeComments(const std::string &input) {
    std::string codeWithoutComments = input;
    bool inSingleLineComment = false;
    bool inMultiLineComment = false;

    for (size_t i = 0; i < codeWithoutComments.length(); ++i) {
        if (inSingleLineComment && codeWithoutComments[i] == '\n') {
            inSingleLineComment = false;
        } else if (inMultiLineComment && codeWithoutComments[i] == '*' && codeWithoutComments[i + 1] == '/') {
            inMultiLineComment = false;
            ++i; // Skip the '/' in "*/"
        } else if (inSingleLineComment || inMultiLineComment) {
            codeWithoutComments.erase(i, 1); // Erase the character
            --i; // Move back to check the current index again
        } else if (codeWithoutComments[i] == '/' && codeWithoutComments[i + 1] == '/') {
            inSingleLineComment = true;
            ++i; // Skip the '/' in "//"
        } else if (codeWithoutComments[i] == '/' && codeWithoutComments[i + 1] == '*') {
            inMultiLineComment = true;
            ++i; // Skip the '*' in "/*"
        }
    }

    return codeWithoutComments;
}

int main() {
    std::string input;
    
    // Read until the end of input
    while (std::getline(std::cin, input)) {
        std::cout << removeComments(input) << '\n';
    }

    return 0;
}

