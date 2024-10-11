
#include "printers.hpp"
#include <stdexcept>

Printers::Printers() = default;

Printers::Printers(const Printers& other) 
{
    for (const auto& pair : other.printers_) 
    {
        const std::string& name = pair.first;
        StringPrinter* cloned_printer = pair.second->Clone();
        printers_.emplace(name, cloned_printer);
    }
}

    Printers::~Printers() 
    {
    for (auto& pair : printers_) 
    {
        delete pair.second;
    }
    printers_.clear();
}

    void Printers::Add(const std::string& name, StringPrinter* printer) 
    {
        if (!printer) 
        {
            throw std::invalid_argument("Invalid printer");
        }
        if (printers_.count(name) > 0) 
        {
            throw std::invalid_argument("Duplicate index");
        }
        printers_[name] = printer;
    }

    StringPrinter& Printers::operator[](const std::string& name) 
    {
        auto it = printers_.find(name);
        if (it == printers_.end()) {
            throw std::invalid_argument("Unknown index");
        }
        return *(it->second);
    }

    Printers& Printers::operator=(const Printers& other) 
    {
    if (this != &other) 
    {
        for (auto& pair : printers_) 
        {
            delete pair.second;
        }
        printers_.clear();
        for (const auto& pair : other.printers_) 
        {
            const std::string& name = pair.first;
            StringPrinter* cloned_printer = pair.second->Clone();
            printers_.emplace(name, cloned_printer);
        }
    }
    return *this;
}
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

#include "diagonal_printer.hpp"

DiagonalPrinter::DiagonalPrinter(const std::string& first_line, const std::string& last_line, std::ostream& os) : StringPrinter(os), first_line_(first_line), last_line_(last_line) {}

StringPrinter* DiagonalPrinter::Clone() const 
{
    return new DiagonalPrinter(first_line_, last_line_, os_);
}

StringPrinter& DiagonalPrinter::operator()(const std::string& str) 
{
    if (!first_line_.empty()) 
    {
        os_ << first_line_ << '\n';
    }

    int i = 0;
    for (char c : str) 
    {
        if (c == ' ') 
        {
            os_ << '\n';
            i += 3;
        } 
        else 
        {
            os_ << std::string(i, ' ') << c << '\n';
            i += 1;
        }
    }
    if (!last_line_.empty()) 
    {
        os_ << last_line_ << '\n';
    }

    return *this;
}