#include "magic_dragon.hpp"

// Define MagicDragon's methods here
void MagicDragon::Eat(std::list<Food>& food)
{
    for (auto it = food.begin(); it != food.end();)
    {
        if (it->type == FoodType::Herbs)
        {
            this->size_++;
            std::cout << "Magic dragon ate: " << it->name << std::endl;
            it=food.erase(it);
        }
        else it++;
    }
}
void MagicDragon::Hoard(std::list<Treasure>& treasure)
{
    for(auto it = treasure.begin(); it != treasure.end(); )
    {
        if (it->type == TreasureType::Potions)
        {
            this->treasures_.push_back(*it);
            std::cout << "Magic dragon received: " << it->name << std::endl;
            it=treasure.erase(it);
        }
        else it++;
    }
}