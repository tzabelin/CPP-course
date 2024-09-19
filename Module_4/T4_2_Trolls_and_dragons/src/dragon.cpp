#include "dragon.hpp"

class Dragon : public Creature {
public:
    // Construct Dragon, use following arguments for Creature initialization
    Dragon(const std::string& name) : Creature(name, "Dragon", 50) { }
    virtual std::string WarCry() const { return "Whoosh!"; }
};