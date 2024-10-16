/* Add include guards here */

/**
 * @brief: A minimal StringPrinter implementation with no special functionality.
 * 
 * TODO: Implement the following:
 * ------------
 * Functions:
 * A constructor that takes a single parameter:
 *  - A reference to the output stream, which is std::cout by default
 * 
 * Overrides the necessary members from the base class.
 * ------------
 * Other:
 * StandardPrinter prints a string like one normally would but with a 
 * newline at the end. For the string "like this":
 * like this\n
*/
#ifndef AALTO_STANDARDPRINTER_H
#define AALTO_STANDARDPRINTER_H

#include "string_printer.hpp"
#include <iostream>
#include <string>

class StandardPrinter : public StringPrinter 
{
public:
    StandardPrinter(std::ostream& os = std::cout);
    virtual StringPrinter* Clone() const override;
    virtual StringPrinter& operator()(const std::string& str) override;
};

#endif
