
#include "boat.hpp"
#pragma once

void Boat::Write(std::ostream& stream)
{
    stream<<"B;"<<this->GetRegisterNumber()<<";"<<this->GetOwner()<<";"<<this->name_<<";"<<this->draft_<<";"<<this->power_<<std::endl;
}
void Boat::Print()
{
    this->Write(std::cout);
}
Boat* Boat::Read(std::istream& stream)
{
    std::string prefix, register_number, owner, name;
    double draft, power;
    if (std::getline(stream, prefix, ';') && std::getline(stream, register_number, ';') && std::getline(stream, owner, ';') &&std::getline(stream, name, ';') && stream >> draft >> std::ws && stream.get() == ';' && stream >> power && prefix == "B")
    {
        return new Boat(register_number, owner, name, draft, power);
    }
    return NULL;
}