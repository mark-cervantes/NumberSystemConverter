#ifndef NUMBER_HPP
#define NUMBER_HPP 

#include <string>

class Number
{
    public:
        Number (int base, std::string value) : _base(base), _value(value)
        { 
            if (base == 2 ) {
                _binary_value = _value;
            }
            if (base == 10) {
                _decimal_value = _value;
            }
        }

        Number (int base, int value) 
        { 
            Number(base, std::to_string(value));
        }

        std::string binary();
        std::string decimal();
        std::string octal();
        std::string hex();

        /**
         * Eto yung low level necessary conversions na kailangan
         */
        class Converter
        {
            static std::string binary_to_hex(std::string binary_value);
            static std::string binary_to_octal(std::string binary_value);
            static std::string any_to_binary(int base, std::string value);
            static std::string binary_to_any(int base, std::string binary_value);
            static std::string any_to_decimal(int base, std::string value);
            static std::string decimal_to_any(int base, std::string decimal_value);

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
         * serves as cache kasi maraming conversions ang manggagaling sa binary
         * ex. imbis na decimal -> binary -> hex/oct
         * magigi na lang siyang _binary_value -> hex/oct
         */
        std::string _binary_value;
        std::string _decimal_value;
};

#endif