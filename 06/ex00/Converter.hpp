#ifndef EX00_CONVERTER_HPP
#define EX00_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream> // for std::stringstream
#include <cmath>


class Converter
{
private:
    std::string _input;
    double _dInput;
    float _fInput;
    int _iInput;
    char _cInput;
    std::string _displayValues[4];

    bool isInfNan();
    bool isNonNumericStr();
    void convertFromInfNan();
    void convertToChar();
    void convertToNumeric();

public:
    Converter();
    explicit Converter(const std::string &input);

    Converter(const Converter &source);
    Converter& operator=(const Converter &source);

    std::string getDisplayValues(int index) const;
    std::string buffToString(std::stringstream &buff);
    const std::string &getInput() const;


    void Convert();

    ~Converter();
};

std::ostream& operator<<(std::ostream &out, const Converter &converter);

#endif //EX00_CONVERTER_HPP
