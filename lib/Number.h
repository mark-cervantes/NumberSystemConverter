#ifndef NUMBER_HPP
#define NUMBER_HPP 

#include <string>

class Number
{
    public:
        Number (int base, std::string value) : _base(base), _value(value)
        { 
            if (base == 10) {
                _decimal_value = std::stoll(_value;
            } else {
                _decimal_value = Number::Converter::any_to_decimal(base, value);
            }
        }

        Number (int base, int value) 
        { 
            Number(base, std::to_string(value));
        }

        std::string binary(int spacing = 4, std::string delimiter = " ");
        std::string decimal(int spacing = 3, std::string delimiter = ",");
        std::string octal(int spacing = 3, std::string delimiter = " ");
        std::string hex(int spacing = 2, std::string delimiter = " ");

        /**
         * Eto yung low level necessary conversions na kailangan
         */
        struct Converter
        {
            //static long long binary_to_decimal(std::string binary_value);
            static std::string decimal_to_any(int base, long long decimal_value);
            static std::string binary_to_any(int base, std::string binary_value);
            static long long any_to_decimal(int base, std::string value);

            // per character functions
            static int from_hex_char(char hex_char);
            static char to_hex(int value, bool is_capital = true);
            static char to_hex(std::string value, bool is_capital = true);
        };
    
    protected:
        int _base; 
        std::string _value;

    private:
        /** 
         * optimizer
         * serves as cache kasi maraming conversions ang manggagaling sa decimal
         * ex. imbis na oct -> decimal -> hex
         * magigi na lang siyang _decimal_value -> hex nalang siya.
         */
        
        long long _decimal_value;
};

#endif