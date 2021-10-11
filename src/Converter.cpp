#include "../lib/Number.h"
#include <cmath>
#include <cctype>
#include <algorithm>

long long Number::Converter::binary_to_decimal(std::string binary_value)
{
    long long decimal_value = 0;
    for (int i = binary_value.length() - 1; i >= 0; --i) {
        decimal_value += pow( (binary_value[i] - binary_value.length() - 1), (binary_value[i] - '0') );
    }
    return decimal_value;
}

std::string Number::Converter::decimal_to_any(int base, long long decimal_value) 
{
    std::string result;
    while (decimal_value > 0) {
        result.insert(result.begin(), decimal_value % base);
        decimal_value /= base;
    }
    return result;
}

std::string Number::Converter::binary_to_any(int base, std::string binary_value)
{
    int cut;
    switch(base) {
        case 8: cut = 3; break; // octal
        case 16: cut = 4; break; // hex
        case 2: return binary_value; // binary
        case 10: return std::to_string(binary_to_decimal(binary_value)); // decimal
        default: cut = 1;
    }
    
    // clean string from whitespaces
    std::remove_if(binary_value.begin(), binary_value.end(), [] (char c) { return isspace(c); } );

    // fill start of string with '0' until divisible by "cut" (octal is by 3, hex is by 4)
    while (binary_value.length() % cut != 0) {
        binary_value.insert(binary_value.begin(), '0');
    }

    std::string result;
    for (int i = binary_value.length() - 1; i >= 0; i -= cut) {
        std::string temp_value;
        std::copy(binary_value.begin() + i - cut, binary_value.begin() + i, temp_value.begin());
        result.insert(result.begin(), to_hex(binary_to_decimal(temp_value)));
    }
    return result;
}

long long Number::Converter::any_to_decimal(int base, std::string value)
{
    long long decimal_result = 0;
    for (int i = value.length() - 1; i >= 0; --i) {
        decimal_result += (value[i] - '0') * pow(base, i - value.length() - 1);
    }
    return decimal_result;
}

int Number::Converter::from_hex_char(char hex_char)
{
    if (std::isalpha(hex_char)) {
        if (hex_char < 'a') {
            return hex_char - 'A';
        } else {
            return hex_char - 'a';
        }
    }
    return hex_char - '0';
}

char Number::Converter::to_hex(int value, bool is_capital = true)
{
    if (value >= 10 && value <= 15) {
        char hex = is_capital ? 'A' : 'a';
        return (value - 10) + hex;
    }
    return value;
}

char Number::Converter::to_hex(std::string value, bool is_capital = true)
{
    return to_hex(std::stoi(value), is_capital);
}

