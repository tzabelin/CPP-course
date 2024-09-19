#ifndef AALTO_ELEC_CPP_TROLL_CLASS
#define AALTO_ELEC_CPP_TROLL_CLASS

#include "creature.hpp"

/**
 * \brief Inherits class Creature.
 *
 * Here, you will need to define the necessary features that support the
 * required functionalities outlined in the given main function
 */
class Troll : public Creature {
public:
    // Construct Troll, use following arguments for Creature initialization
    Troll(const std::string& name) : Creature(name, "Troll", 10) { }
    virtual std::string WarCry() const { return "Ugazaga!"; }
};

#endif