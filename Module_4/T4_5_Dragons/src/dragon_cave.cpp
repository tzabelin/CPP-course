#include "dragon_cave.hpp"

// Define DragonCave's methods here
const std::list<Dragon*>& DragonCave::GetDragons() const
{
    return &dragons_;
}
void DragonCave::Accommodate(Dragon* dragon)
{
    dragons_.push_back(dragon);
}
void DragonCave::Evict(const std::string& name)
{
    for(auto it = dragons_.begin(); it != dragons_.end(); it++)
    {
        if (it->GetName() == name)
        {
            dragons_.erase(it);
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