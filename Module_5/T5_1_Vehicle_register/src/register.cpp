#include "register.hpp"
#include <fstream>
#include <sstream>
#include "aircraft.hpp"
#include "boat.hpp"

//TODO: implement Register's members
void Register::Add(Vehicle* v)
{
    this->vehicles_.push_back(v);
}
void Register::Save(const std::string& filename) const
{
    std::ofstream stream(filename);
    for(auto vehicle : this->vehicles_)
    {
        vehicle->Write(stream);
    }
}

Register::~Register() 
{
    for (auto vehicle : vehicles_) 
    {
        delete vehicle;
    }
}

bool Register::ReadLine(std::istream& stream)
{
    std::string line;
    std::istringstream str(line);
    char type;
    if (!(str >> type))
        return false;
    if (str.get() != ';')
        return false;
    Vehicle* vehicle = nullptr;
    if (type == 'A')
    {
        vehicle = Aircraft::Read(str);
    }
    else if (type == 'B')
    {
        vehicle = Boat::Read(str);
    }
    else
    {
        return false;
    }
    if (vehicle != nullptr)
    {
        Add(vehicle);
        return true;
    }
    else
    {
        return false;
    }
}

int Register::Load(const std::string& filename)
{
    std::ifstream stream(filename);
    int vehicles_added = 0;
    while (stream)
    {
        bool result = ReadLine(stream);
        if (stream.eof())
            break;
        if (result)
            vehicles_added++;
    }
    return vehicles_added;
}

void Register::Print()
{
    for(auto vehicle : this->vehicles_)
    {
        vehicle->Print();
    }
}

size_t Register::Size() const
{
    return this->vehicles_.size();
}