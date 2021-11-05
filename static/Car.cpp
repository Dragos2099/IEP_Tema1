#include <../include/Car.hpp>

Car::Car()
{
    horsePower_ = 0;
    nrSeats_ = 0;
    bodyStyle_ = "N/A";
    traction_ = "N/A";
}

Car::Car(int horsePower, int nrSeats, std::string bodyStyle, std::string traction)
{
    horsePower_ = horsePower;
    nrSeats_ = nrSeats;
    bodyStyle_ = bodyStyle;
    traction_ = traction;
}

Car::Car(const Car& car)
{
    horsePower_ = car.horsePower_;
    nrSeats_ = car.nrSeats_;
    bodyStyle_ = car.bodyStyle_;
    traction_ = car.traction_;
}

Car::~Car()
{
    //std::cout << "\nDestructor Car\n";
}

int Car::getHorsePower()
{
    return horsePower_;
}

int Car::getNrSeats()
{
    return nrSeats_;
}

std::string Car::getBodyStyle()
{
    return bodyStyle_;
}

std::string Car::getTraction()
{
    return traction_;
}

std::ostream& Car::print(std::ostream& os)
{
    return os << "\n[HP] : [" << horsePower_ << "]\n"
            << "[Nr_Of_Seats] : [" << nrSeats_ << "]\n"
            << "[Body_Style] : [" << bodyStyle_ << "]\n"
            << "[Traction] : [" << traction_ << "]\n";
}

std::ostream& operator<<(std::ostream& os, Car& car)
{
    return car.print(os);
}