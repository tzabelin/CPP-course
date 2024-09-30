#include "register.hpp"
#include <fstream>
//TODO: implement Register's members
void Register::Add(Vehicle* v)
{
    this->vehicles_.push_back(v);
}
void Register::Save(const std::string& filename) const
{
    for(auto vehicle : this->vehicles_)
    {
        vehicle->Write(std::fstream(filename));
    }
}
bool Register::ReadLine(std::istream& stream)
{
    std::string prefix;
    if(std