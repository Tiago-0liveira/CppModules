#include <ScalarConverter.hpp>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter & copy) {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const & rhs)
{
    (void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

const char *ScalarConverter::ErrorException::what() const throw()
{
    return "Conversion Error";
}

bool ScalarConverter::isPseudoLiteral(const std::string &param)
{
    static std::string pseudoLiterals[6] = {
        "-inff", "+inff", "nanf", "-inf", "+inf", "nan"
    }; 
    int i = 0;
    for (; i < 6; i++) {
        if (param.compare(pseudoLiterals[i]) == 0)
            return true;
    }
    return false;
}

ScalarConverter::Type ScalarConverter::getType(const std::string &param)
{
    if (param.empty()) return Undefined;
    else if (isPseudoLiteral(param)) return PseudoLiteral;
    
    size_t dot_idx = param.find('.');
    if (dot_idx != param.npos)
    {
        size_t fchar_idx = param.find('f');
        if (fchar_idx != param.npos)
        {
            bool minus = false;
            for (size_t i = 0; i < param.length(); i++)
            {
                char c = param.at(i);
                if (isdigit(c)) {

                } else if (c == '-') {
                    if (minus)
                }

            }
        }
    }
}

void ScalarConverter::convert(const std::string &param)
{
    char    res_char;
    int     res_int;
    float   res_float;
    double  res_double;

    switch (getType(param))
    {
    case Char:
        /* code */
        break;
    case Int:
        /* code */
        break;
    case Float:
        /* code */
        break;
    case Double:
        /* code */
        break;
    case PseudoLiteral:
        /* code */
        break;
    default:
        break;
    }
}

char ScalarConverter::string_to_char(const std::string &param)
{

}

int ScalarConverter::string_to_int(const std::string &param)
{

}

float ScalarConverter::string_to_float(const std::string &param)
{

}

double ScalarConverter::string_to_double(const std::string &param)
{
    
}


