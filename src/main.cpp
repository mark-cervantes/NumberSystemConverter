#include <iostream>
#include "../lib/Number.h"

/**
 * yung template <typename T> parang generics siya ng Java
 * ang gamit lang naman nun, para pwede kahit anong datatype maging datatype nung variable "input"
 * para pwede mag input kunwari ng double, o ng string, o ng int. etc.
 */
// function to display message then get input
template <typename T>
static T get_input(std::string message, bool is_newline = false)
{
    T input;
    std::cout << (is_newline ? "\n" : "") << message;
    std::cin >> input;
    return input;
}

int main() 
{
    char yn;
    do {
        int base = get_input<int>("Enter base: ");
        std::string value = get_input<std::string>("Enter value: ");
        Number number(base, value);
        std::cout << "Binary: " << number.binary() << std::endl;
        std::cout << "Decimal: " << number.decimal() << std::endl;
        std::cout << "Octal: " << number.octal() << std::endl;
        std::cout << "hex: " << number.hex() << std::endl;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        yn = get_input<char>("Continue?[y/n]: ", true);
    } while (std::toupper(yn) != 'N');
}