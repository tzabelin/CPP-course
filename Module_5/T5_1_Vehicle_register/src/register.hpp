#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
//#ifndef AALTO_ELEC_CPP_REGISTER_CLASS
//#define AALTO_ELEC_CPP_REGISTER_CLASS

class Vehicle {
public:
    /**
     * @brief Construct a new Vehicle object
     * 
     * @param register_number registration of the vehicle as a std::string
     * @param owner name of the owner as a std::string
     */
    explicit Vehicle(std::string register_number,
                     std::string owner);

    /**
     * @brief Destroy the Vehicle object.
     */
    virtual ~Vehicle() {};

    /**
     * @brief Get the register number of the vehicle
     * 
     * @return registration of the vehicle as a std::string 
     */
    std::string GetRegisterNumber() const;

    /**
     * @brief Get the owner of the vehicle
     * 
     * @return name of the owner as a std::string 
     */
    std::string GetOwner() const;

    /**
     * @brief Writes the vehicle to the stream given as a parameter in the
     * serialized format for that vehicle. Note: this is a pure virtual method.
     * 
     * @param stream reference to the desired ostream 
     */
    virtual void Write(std::ostream& stream) = 0;

    /**
     * @brief Writes the vehicle to the standard output in the serialized format
     * for that vehicle. Note: this is a pure virtual method.
     */
    virtual void Print() = 0;
private:
    std::string register_number_;
    std::string owner_;
};
std::string Vehicle::GetRegisterNumber() const
{
    return this->register_number_;
}
std::string Vehicle::GetOwner() const
{
    return this->owner_;
}
Vehicle::Vehicle(std::string register_number, std::string owner) : register_number_(register_number), owner_(owner) {}

/**
 * @brief Inherits class Vehicle and implements functionalities required for
 * handling aircraft.
 */
class Aircraft : public Vehicle {
public:
    /**
     * @brief Construct a new Aircraft object
     * 
     * @param register_number registration of the vehicle as a std::string
     * @param owner name of the owner as a std::string
     * @param model name of the vehicle model as a std::string
     * @param wingspan wingspan of the aircraft as a double
     * @param cruise_speed cruise speed of the aircraft as an unsigned integer
     */
    Aircraft(std::string register_number,
             std::string owner,
             std::string model,
             double wingspan,
             unsigned int cruise_speed): Vehicle(register_number, owner), model_(model), wingspan_(wingspan), cruise_speed_(cruise_speed) {}
    ~Aircraft() override {}
    /**
     * @brief Writes the vehicle to the stream given as a parameter in a
     * predefined serialized format.
     * 
     * Format for an aircraft:
     * A;<register number>;<owner>;<model>;<wingspan>;<cruise_speed>\n
     * 
     * @param stream reference to the desired ostream 
     */
    void Write(std::ostream& stream) override
{
    stream<<"A;"<<this->GetRegisterNumber()<<";"<<this->GetOwner()<<";"<<this->model_<<";"<<this->wingspan_<<";"<<this->cruise_speed_<<std::endl;
}
    
    /**
     * @brief Writes the vehicle to the standard output in the given serialized
     * format (see method Write for details).
     */
    void Print() override
{
    this->Write(std::cout);
}

    /**
     * @brief Reads an Aircraft object from a given istream.
     * 
     * Assumes that the vehicle is stored in a predefined serialized format (see
     * method Write for details). Reading is started immediately from the
     * current position of the stream.
     * 
     * @param stream reference to the desired istream 
     * @return a Aircraft* pointer refering to the newly created object if the
     * input can be read successfully
     * @return a NULL pointer otherwise
     */
    static Aircraft* Read(std::istream& stream)
{
    std::string prefix, register_number, owner, model;
    double wingspan, cruise_speed;
    if (std::getline(stream, prefix, ';') && std::getline(stream, register_number, ';') && std::getline(stream, owner, ';') &&std::getline(stream, model, ';') && stream >> wingspan >> std::ws && stream.get() == ';' && stream >> cruise_speed && prefix == "A")
    {
        return new Aircraft(register_number, owner, model, wingspan, cruise_speed);
    }
    return NULL;
}

private:
    std::string model_;
    double wingspan_;
    unsigned int cruise_speed_;
};
/**
 * @brief Inherits class Vehicle and implements functionalities required for
 * handling boats.
 */
class Boat : public Vehicle
{
public:
    /**
     * @brief Construct a new Boat object
     * 
     * @param register_number registration of the vehicle as a std::string
     * @param owner name of the owner as a std::string
     * @param name  name of the vehicle as a std::string
     * @param draft draft of the boat as a double
     * @param power power of the boat as a double
     */
    Boat(std::string register_number, std::string owner,
         std::string name,
         double draft,
         double power) : Vehicle(register_number, owner), name_(name), draft_(draft), power_(power) {}
    ~Boat() override{}
    /**
     * @brief Writes the vehicle to the stream given as a parameter in a
     * predefined serialized format.
     * 
     * Format for a boat:
     * B;<register number>;<owner>;<name>;<draft>;<power>\n
     * 
     * @param stream reference to the desired ostream 
     */
    void Write(std::ostream &stream) override
{
    stream<<"B;"<<this->GetRegisterNumber()<<";"<<this->GetOwner()<<";"<<this->name_<<";"<<this->draft_<<";"<<this->power_<<std::endl;
}

    /**
     * @brief Writes the vehicle to the standard output in the given serialized
     * format (see method Write for details).
     */
    void Print() override {
    this->Write(std::cout);
}

    /**
     * @brief Reads a Boat object from a given istream.
     * 
     * Assumes that the vehicle is stored in a predefined serialized format (see
     * method Write for details). Reading is started immediately from the
     * current position of the stream.
     * 
     * @param stream reference to the desired istream 
     * @return a Boat* pointer refering to the newly created object if the input
     * can be read successfully. Otherwise, a NULL pointer.
     */
    static Boat *Read(std::istream& stream)
{
    std::string prefix, register_number, owner, name;
    double draft, power;
    if (std::getline(stream, prefix, ';') && std::getline(stream, register_number, ';') && std::getline(stream, owner, ';') &&std::getline(stream, name, ';') && stream >> draft >> std::ws && stream.get() == ';' && stream >> power && prefix == "B")
    {
        return new Boat(register_number, owner, name, draft, power);
    }
    return NULL;
}

private:
    std::string name_;
    double draft_;
    double power_;
};
class Register {
public:
    /**
     * @brief Destroy the Register object
     */
    ~Register();
    
    /**
     * @brief Adds a new vehicle to the Vehicle* vector vehicles_
     * 
     * @param v Vehicle pointer to be added
     */
    void Add(Vehicle* v);

    /**
     * @brief Saves the vehicles to the file named by the parameter with each
     * vehicle on its own line in the serialized format.
     * 
     * @param filename Reference to the desired filename as std::string 
     */
    void Save(const std::string& filename) const;

    /**
     * @brief Reads a vehicle from the stream given as a parameter assuming a
     * serialized format, and adds it to the register.
     * 
     * Reads a whole line from the stream whether or not constructing the
     * vehicle was succesful.
     * 
     * @param stream 
     * @return true if a vehicle was added
     * @return false otherwise
     */
    bool ReadLine(std::istream& stream);
   
    /**
     * @brief Reads all vehicles from a file and adds them to the register.
     * 
     * Each vehicle is on a different line. On an error the line is discarded
     * and reading is continued from the next line.
     * 
     * @param filename 
     * @return the number of vehicles added as an integer
     * @return -1 if opening the file fails
     */
    int Load(const std::string& filename);

    /**
     * @brief Prints all the vehicles in the register to the standard output
     * each on a different line in the serialized format.
     */
    void Print();

    /**
     * @brief Get the number of vehicles in the register.
     * 
     * @return the number of vehicles in the register as a size_t integer. 
     */
    size_t Size() const;

private:
    std::vector<Vehicle*> vehicles_;
};
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
    if (!std::getline(stream, line))
        return false;
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
//#endif