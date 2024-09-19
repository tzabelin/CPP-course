#include "troll.hpp"

class Troll : public Creature {
public:
    // Construct Troll, use following arguments for Creature initialization
    Troll(const std::string& name) : Creature(name, "Troll", 10) { }
    virtual std::string WarCry() const { return "Ugazaga!"; }
};

