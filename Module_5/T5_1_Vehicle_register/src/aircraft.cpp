
#include "aircraft.hpp"
//TODO: implement Aircraft's members
#pragma once

void Aircraft::Write(std::ostream& stream)
{
    stream<<"A;"<<this->GetRegisterNumber()<<";"<<this->GetOwner()<<";"<<this->model_<<";"<<this->wingspan_<<";"<<this->cruise_speed_<<std::endl;
}
void Aircraft::Print()
{
    this->Write(std::cout);
}
Aircraft* Aircraft::Read(std::istream& stream)
{
    std::string prefix, register_number, owner, model;
    double wingspan, cruise_speed;
    if (std::getline(stream, prefix, ';') && std::getline(stream, register_number, ';') && std::getline(stream, owner, ';') &&std::getline(stream, model, ';') && stream >> wingspan >> std::ws && stream.get() == ';' && stream >> cruise_speed && prefix == "A")
    {
        return new Aircraft(register_number, owner, model, wingspan, cruise_speed);
    }
    return NULL;
}