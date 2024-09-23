#include "dragon.hpp"

const std::string& Dragon::GetName() const {return name_;}
size_t Dragon::GetAge() const {return age_;}
size_t Dragon::GetSize() const {return size_;}
const std::list<Treasure>& Dragon::GetTreasures() const {return treasures_;}
std::ostream& operator<<(std::ostream& os, const Dragon& dragon)
{
    os << "Dragon named: " << dragon.GetName() << ", age: " << dragon.GetAge() << ", size: " << dragon.GetSize() << std::endl<<"Treasures:"<<std::endl;
    for(auto it = dragon.GetTreasures().begin(); it != dragon.GetTreasures().end(); it++)
    {
        os << it->name << std::endl;
    }
};