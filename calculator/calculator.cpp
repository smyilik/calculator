#include "Header.h"

int main()
{
    calculator();
    help();
    string input;
    getline(cin, input);
    while (input != "shutdown") {
        if (itc_isFirstInSecond("+", input)) cout << "--------------------------------------------------------------------------------" << endl
            << summator(input) << endl << "--------------------------------------------------------------------------------" << endl;
        else if (itc_isFirstInSecond("*", input)) cout << "--------------------------------------------------------------------------------" << endl
            << multiply(input) << endl << "--------------------------------------------------------------------------------" << endl;
        else if (itc_isFirstInSecond("-", input)) cout << "--------------------------------------------------------------------------------" << endl
            << subtractor(input) << endl << "--------------------------------------------------------------------------------" << endl;
        else if (input == "help") help();
        else cout << "--------------------------------------------------------------------------------" << endl
            << "Wrong command!" << endl << "--------------------------------------------------------------------------------" << endl;
        getline(cin, input);
    }
}
