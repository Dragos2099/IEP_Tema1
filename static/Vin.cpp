#include <../include/Vin.hpp>

Vin::Vin()
{
    vin_ = new std::string("XX00XXX");
}

Vin::Vin(std::string vin)
{
    vin_ = new std::string(vin);
}

Vin::~Vin()
{
    delete vin_;
}

std::string Vin::getVin()
{
    return *vin_;
}

bool Vin::operator==(const Vin vin)
{
    return vin.vin_ == this->vin_;
}

std::ostream& operator<<(std::ostream& os, Vin& vin)
{
    os << vin.getVin();
}