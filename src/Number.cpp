#include "../lib/Number.h"
#include <string>

void Number::insert_delimiters(std::string * value, int spacing, std::string delimiter) 
{
    for (int i = value->length() - 1; i >= 0; --i) {
        size_t delimit_pos = value->length() - i;
        if (delimit_pos % i == 0) {
            value->insert(delimit_pos, delimiter);
        }
    }
}

std::string Number::binary(int spacing = 4, std::string delimiter = " ")
{
    std::string binary = Number::Converter::decimal_to_any(2, _decimal_value);
    insert_delimiters(&binary, spacing, delimiter);
    return binary;
}

std::string Number::decimal(int spacing = 3, std::string delimiter = ",")
{
    std::string decimal = std::to_string(_decimal_value);
    insert_delimiters(&decimal, spacing, delimiter);
    return decimal;
}

std::string Number::hex(int spacing = 2, std::string delimiter = " ")
{
    std::string hex = Number::Converter::decimal_to_any(16, _decimal_value);
    insert_delimiters(&hex, spacing, delimiter);
    return hex;
}

std::string Number::octal(int spacing = 3, std::string delimiter = " ")
{
    std::string octal = Number::Converter::decimal_to_any(8, _decimal_value);
    insert_delimiters(&octal, spacing, delimiter);
    return octal;
}