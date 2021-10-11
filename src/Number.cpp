#include "../lib/Number.h"
#include <string>

/**
 * formats the number output with delimiters(ex. decimals shall have commas every 3 digits 100,000)
 */
void Number::insert_delimiters(std::string * value, int spacing, std::string delimiter) 
{
    bool first = true;
    for (int i = 1; i < value->length(); ++i) {
        if (i % (spacing + 1) == 0) {
            value->insert(value->length()+1 - i++, delimiter);
        }
    }
}

std::string Number::binary(int spacing, std::string delimiter)
{
    std::string binary = _base == 2 ? _value : 
        Number::Converter::decimal_to_any(2, _decimal_value);

    insert_delimiters(&binary, spacing, delimiter);
    return binary;
}

std::string Number::decimal(int spacing, std::string delimiter)
{
    std::string decimal = std::to_string(_decimal_value);
    insert_delimiters(&decimal, spacing, delimiter);
    return decimal;
}

std::string Number::hex(int spacing, std::string delimiter)
{
    std::string hex = Number::Converter::decimal_to_any(16, _decimal_value);
    insert_delimiters(&hex, spacing, delimiter);
    return hex;
}

std::string Number::octal(int spacing, std::string delimiter)
{
    std::string octal = Number::Converter::decimal_to_any(8, _decimal_value);
    insert_delimiters(&octal, spacing, delimiter);
    return octal;
}