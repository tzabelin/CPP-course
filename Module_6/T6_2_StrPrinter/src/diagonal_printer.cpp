#include "diagonal_printer.hpp"

DiagonalPrinter::DiagonalPrinter(const std::string& first_line, const std::string& last_line, std::ostream& os) : StringPrinter(os), first_line_(first_line), last_line_(last_line) {}

StringPrinter* DiagonalPrinter::Clone() const 
{
    return new DiagonalPrinter(first_line_, last_line_, os_);
}

StringPrinter& DiagonalPrinter::operator()(const std::string& str) 
{
    if (first_line_ != "") 
    {
        os_ << first_line_ << std::endl;
    }
    //std::cout << "Test" << std::endl;
    int i = 0;
    int n = str.length();
    for (char c : str) 
    {
        os_ << std::string(i, ' ') << c <<  std::string(n - 1 - i, ' ') << std::endl;
        i += 1;
    }
    if (last_line_ != "") 
    {
        os_ << last_line_ << std::endl;
    }

    return *this;
}