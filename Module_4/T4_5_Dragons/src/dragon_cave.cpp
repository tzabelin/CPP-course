#include "dragon_cave.hpp"
#include "dragon.hpp"

// Define DragonCave's methods here
const std::list<Dragon*>& DragonCave::GetDragons() const
{
    return dragons_;
}
void DragonCave::Accommodate(Dragon* dragon)
{
    dragons_.push_back(dragon);
}
void DragonCave::Evict(const std::string& name)
{
    for(auto it = dragons_.begin(); it != dragons_.end();)
    {
        if ((*it)->GetName() == name)
        {
            dragons_.erase(it);
            break;
        }
    }
}
DragonCave::~DragonCave()
{
    for (auto i : dragons_) 
    {
        delete i;
    }
}
std::ostream& operator<<(std::ostream& os, const DragonCave& cave)
{
    os<< "DragonCave dwellers:"<<std::endl<<std::endl;
    for( auto dragon : cave.GetDragons())
    {
        if (dragon)
        {os << *dragon<<std::endl;}
    }
    return os;
}