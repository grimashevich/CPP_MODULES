#include "Converter.hpp"

Converter::Converter(): _dInput(0), _fInput(0), _iInput(0), _cInput(0)
{

}

Converter::Converter(const std::string &input) : _input(input), _dInput(0),
                    _fInput(0), _iInput(0), _cInput()
{

}

Converter::Converter(const Converter &source)
{
    *this = source;
}

Converter &Converter::operator=(const Converter &source)
{
    this->_input = source._input;
    this->_cInput = source._cInput;
    this->_iInput = source._iInput;
    this->_fInput = source._fInput;
    this->_dInput = source._dInput;
    for (int i = 0; i < 4; ++i)
        this->_displayValues[i] = source._displayValues[i];
    return *this;
}


bool Converter::isInfNan()
{
    const std::string initValues[8] = {
            "inf", "nan", "-inf", "+inf",
            "inff", "nanf", "-inff", "+nanff"};
    for (int i = 0; i < 8; ++i)
    {
        if (_input == initValues[i])
            return true;
    }
    return false;
}

void Converter::convertFromInfNan()
{
    std::stringstream buffer;
    _dInput = strtod(&_input[0], NULL);
    buffer << _dInput;
    _displayValues[0] = buffToString(buffer);
    _fInput = static_cast<float>(_dInput);
    buffer << _fInput;
    _displayValues[1] = buffToString(buffer);
    _displayValues[2] = "impossible";
    _displayValues[3] = "impossible";
}

std::string Converter::buffToString(std::stringstream &buff)
{
    std::string result = buff.str();
    buff.str("");
    return result;
}

void Converter::Convert()
{
    if (isInfNan())
        return convertFromInfNan();
    if (_input.size() > 1 && isNonNumericStr())
    {
        for (int i = 0; i < 4; ++i)
            _displayValues[i] = "impossible";
        return;
    }
    _dInput = strtod(&_input[0], NULL);
    convertToChar();
    convertToNumeric();
}

std::string Converter::getDisplayValues(int index) const
{
    return _displayValues[index];
}

bool Converter::isNonNumericStr()
{
    char *residue;
    strtod(&_input[0], &residue);
    if (residue[0] == 0 || (residue[0] == 'f' && residue[1] == 0))
        return false;
    return true;
}

void Converter::convertToChar()
{
    double _tmp;

    if (modf(_dInput, &_tmp) > 0.0 || _dInput > 127 || _dInput < -127)
        _displayValues[3] = "impossible";
    else if (_dInput < 32)
        _displayValues[3] = "non printable";
    else
    {
        _cInput = static_cast<char>(_dInput);
        _displayValues[3] = _cInput;
    }
}

const std::string &Converter::getInput() const
{
    return _input;
}

void Converter::convertToNumeric()
{
    std::stringstream buffer;

    buffer << _dInput;
    _displayValues[0] = buffToString(buffer);

    _fInput = static_cast<float>(_dInput);
    buffer << _fInput;
    _displayValues[1] = buffToString(buffer);

    _iInput = static_cast<int>(_dInput);
    buffer << _iInput;
    _displayValues[2] = buffToString(buffer);
}

Converter::~Converter()
{

}


std::ostream& operator<<(std::ostream &out, const Converter &converter)
{
    out << "string: " << converter.getInput() << std::endl;
    out << "char: " << converter.getDisplayValues(3) << std::endl;
    out << "int: " << converter.getDisplayValues(2) << std::endl;
    out << "float: " << converter.getDisplayValues(1) << std::endl;
    out << "double: " << converter.getDisplayValues(0);
    return out;
}
