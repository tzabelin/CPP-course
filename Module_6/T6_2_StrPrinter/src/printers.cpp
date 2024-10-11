
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