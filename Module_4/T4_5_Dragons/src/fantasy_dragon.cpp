#include "fantasy_dragon.hpp"

// Define FantasyDragon's methods here
    void FantasyDragon::Eat(std::list<Food>& food)
    {
            for(auto it = food.begin(); it != food.end(); it++)
    {
        if (it->type == FoodType::People || it->type == FoodType::PeopleFood)
        {
            this->size_++;
            std::cout << "Magic dragon ate: " << it->name << std::endl;
            food.erase(it);
        }
    }
    }
    void FantasyDragon::Hoard(std::list<Treasure>& treasure)
    {
            for(auto it = treasure.begin(); it != treasure.end(); it++)
    {
        if (it->type == TreasureType::Jewellery)
        {
            this->treasures_.push_back(*it);
            std::cout << "Magic dragon received: " << it->name << std::endl;
            treasure.erase(it);
        }
    }
    }