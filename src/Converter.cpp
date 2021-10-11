#include "../lib/Number.h"

std::string Number::Converter::binary_to_hex(std::string binary_value)
{

}

std::string binary_to_octal(std::string binary_value)
{

}

std::string Number::Converter::any_to_binary(int base, std::string value)
{

}

std::string binary_to_any(int base, std::string binary_value)
{

}

std::string any_to_decimal(int base, std::string value)
{

}

std::string decimal_to_any(int base, std::string decimal_value)
{

}

int from_hex_char(char hex_char)
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

char to_hex(int value, bool is_capital = true)
{
    if (value >= 10 && value <= 15) {
        char hex = is_capital ? 'A' : 'a';
        return (value - 10) + hex;
    }
    return value;
}

char to_hex(std::string value, bool is_capital = true)
{
    return to_hex(std::stoi(value), is_capital);
}

