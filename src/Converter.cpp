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
        int remainder = decimal_value % base;
        result.insert(result.begin(), to_hex(remainder));
        decimal_value /= base;
    }
    return result;
}

long long Number::Converter::any_to_decimal(int base, std::string value)
{
    long long decimal_result = 0;
    for (int i = value.length() - 1; i >= 0; --i) {
        decimal_result += (from_hex_char(value[i])) * static_cast<long long>(pow(base,  value.length() - 1 - i));
    }
    return decimal_result;
}

int Number::Converter::from_hex_char(char hex_char)
{
    if (std::isalpha(hex_char)) {
        if (hex_char < 'a') {
            return hex_char - 'A' + 10;
        } else {
            return hex_char - 'a' + 10;
        }
    }
    return hex_char - '0';
}

char Number::Converter::to_hex(int value, bool is_capital)
{
    if (value >= 10 && value <= 15) {
        char hex = is_capital ? 'A' : 'a';
        return (value - 10) + hex;
    } else if (value >= 0 && value <= 9) {
        return value + '0';
    }

    return value;
}

char Number::Converter::to_hex(std::string value, bool is_capital)
{
    return to_hex(std::stoi(value), is_capital);
}

