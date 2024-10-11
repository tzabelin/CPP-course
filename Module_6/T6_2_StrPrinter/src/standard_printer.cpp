#include "standard_printer.hpp"
StandardPrinter::StandardPrinter(std::ostream& os) : StringPrinter(os) {}
StringPrinter* StandardPrinter::Clone() const 
{
    return new StandardPrinter(os_);
}
StringPrinter& StandardPrinter::operator()(const std::string& str) 
{
    os_ << str << '\n';
    return *this;
}