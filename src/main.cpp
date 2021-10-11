#include <iostream>

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
    std::cout << is_newline ? "\n" : "" << message;
    std::cin >> input;
    return input;
}

int main() 
{

}