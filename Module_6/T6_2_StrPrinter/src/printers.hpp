/* Add include guards here */

/**
 * @brief: A storage for StringPrinter pointers associated with a name. The
 * class has ownership of the objects.
 * 
 * TODO: Implement the following:
 * ------------
 * Functions:
 * 
 * A default constructor that initializes the object with zero printers.
 * 
 * A copy constructor that copies the object.
 * 
 * Add: A function that adds a new StringPrinter object to the collection
 * and associates it with a name.
 * Takes two parameters:
 *  - a string that contains the name
 *  - the StringPrinter pointer to be added
 * Throws:
 *  - std::invalid_argument if an association for the name already exists ("Duplicate index").
 *  - std::invalid_argument if the pointer is null ("Invalid printer").
 * Note: The Printers object takes ownership of the pointer and is
 *  therefore responsible for eventually calling delete on the pointer.
 * 
 * Indexing operator: The collection is indexed using the
 * name (string) and returns a reference to the associated StringPrinter.
 * Throws:
 *  - std::invalid_argument if an association does not exist ("Unknown index").
 * 
 * Copy assignment operator: copies the object given to self.
 * ------------
 * Members:
 * Whatever you deem necessary.
 * ------------
 * Other:
 * Copying means copying the contained StringPrinters as well.
 * Remember to also implement the destructor.
 */
#ifndef AALTO_PRINTERS_H
#define AALTO_PRINTERS_H

#include <unordered_map>
#include "string_printer.hpp"

class Printers 
{
    public:
    Printers();
    Printers(const Printers& a);
    ~Printers();
    void Add(const std::string& name, StringPrinter* printer);
    StringPrinter& operator[](const std::string& name);
    Printers& operator=(const Printers& other);

private:
    std::unordered_map<std::string, StringPrinter*> printers_;
};

#endif