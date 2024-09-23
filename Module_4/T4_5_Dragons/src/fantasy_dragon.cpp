#include "fantasy_dragon.hpp"

// Define FantasyDragon's methods here
    void FantasyDragon::Eat(std::list<Food>& food)
    {
            for(auto it = food.begin(); it != food.end(); )
    {
        if (it->type == FoodType::People || it->type == FoodType::PeopleFood)
        {
            this->size_++;
            std::cout << "Fantasy dragon ate: " << it->name << std::endl;
            it=food.erase(it);
        }
        else  it++;
    }
    }
    void FantasyDragon::Hoard(std::list<Treasure>& treasure)
    {
            for(auto it = treasure.begin(); it != treasure.end();)
    {
        if (it->type == TreasureType::Jewellery)
        {
            this->treasures_.push_back(*it);
            std::cout << "Fantasy dragon received: " << it->name << std::endl;
            it=treasure.erase(it);
        }
        else  it++;
    }
    }