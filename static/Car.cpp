#include <../include/Car.hpp>

Car::Car()
{
    horsePower_ = 0;
    nrSeats_ = 0;
    bodyStyle_ = "N/A";
    traction_ = "N/A";
    vin_ = new int[VIN_SIZE];
}

Car::Car(int horsePower, int nrSeats, std::string bodyStyle, std::string traction, int *vin)
{
    horsePower_ = horsePower;
    nrSeats_ = nrSeats;
    bodyStyle_ = bodyStyle;
    traction_ = traction;
    vin_ = new int[VIN_SIZE];
    for(int i=FIRST; i < VIN_SIZE; i++)
    {
        vin_[i] = vin[i];
    }
}

Car::Car(const Car& car)
{
    horsePower_ = car.horsePower_;
    nrSeats_ = car.nrSeats_;
    bodyStyle_ = car.bodyStyle_;
    traction_ = car.traction_;
    vin_ = new int[VIN_SIZE];
    for(int i=FIRST; i < VIN_SIZE; i++)
    {
        vin_[i] = car.vin_[i];
    }
}

Car::~Car()
{
    delete [] vin_;
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

std::string Car::getVin()
{
    std::string tempVin = "";
    for(int i=FIRST; i < VIN_SIZE; i++)
    {
        tempVin.append(std::to_string(vin_[i]));
    }
    return tempVin;
}

Car& Car::operator=(const Car& car)
{
    if(this != &car)
    {
        horsePower_ = car.horsePower_;
        nrSeats_ = car.nrSeats_;
        bodyStyle_ = car.bodyStyle_;
        traction_ = car.traction_;
        int *vinOrig = vin_;
        vin_ = new int[VIN_SIZE];
        for(int i=FIRST; i < VIN_SIZE; i++)
        {
            vin_[i] = car.vin_[i];
        }
        delete vinOrig;
    }
    return *this;
}

std::ostream& Car::print(std::ostream& os)
{
    return os << "\n[HP] : [" << horsePower_ << "]\n"
            << "[Nr_Of_Seats] : [" << nrSeats_ << "]\n"
            << "[Body_Style] : [" << bodyStyle_ << "]\n"
            << "[Traction] : [" << traction_ << "]\n"
            << "[Vehicle Identification Number] : [" << getVin() << "]\n";
}

std::ostream& operator<<(std::ostream& os, Car& car)
{
    return car.print(os);
}