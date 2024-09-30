#include "vehicle.hpp"
//TODO: implement Vehicle's members
std::string Vehicle::GetRegisterNumber() const
{
    return this->register_number_;
}
std::string Vehicle::GetOwner() const
{
    return this->owner_;
}
Vehicle::Vehicle(std::string register_number, std::string owner) : register_number_(register_number), owner_(owner) {}