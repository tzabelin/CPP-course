/* Add include guards here */

/**
 * @brief An abstract class that works as a base class for different string
 * printers.
 * 
 * TODO: Implement the following;
 * ------------
 * Functions:
 * 
 * A single constructor that takes std::ostream& as a parameter with the 
 * default value std::cout to which the function call operator prints.
 *
 * Clone: a function that copies the object and returns a StringPrinter pointer.
 * The function should not alter the state of the object it is called for.
 * 
 * Function call operator (operator()) overload, i.e. this base class is 
 *  a function object:
 *    - Takes one std::string argument (the string should not be modified).
 *    - Prints out the string in the format specified in the child class's
 *      specification to the ostream that was given in the constructor.
 *    - Returns a reference to the StringPrinter object meaning that this
 *      function call operation can be "chained", e.g.
 *      object("First")("Second")("Third");
 * ------------
 * Protected members:
 *  An std::ostream reference to the output stream, named os_
 * ------------
 * Other:
 * Do not forget the virtual destructor.
 * As to what functions should be pure virtual (this is an abstract class after all)
 * is left for you to figure out.
 */

#ifndef AALTO_STRINGPRINTER_H
#define AALTO_STRINGPRINTER_H

#include <iostream>
#include <string>

class StringPrinter 
{
public:
    StringPrinter(std::ostream& os = std::cout) : os_(os) {}
    virtual ~StringPrinter() {}
    virtual StringPrinter* Clone() const = 0;
    virtual StringPrinter& operator()(const std::string& str) = 0;
protected:
    std::ostream& os_;
};

#endif