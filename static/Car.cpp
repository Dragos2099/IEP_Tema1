#include <../include/Car.hpp>

Car::Car()
{
    horsePower_ = 0;
    nrSeats_ = 0;
    bodyStyle_ = "N/A";
    traction_ = "N/A";
    vin_.reset(new Vin("000000000000"));
}

Car::Car(std::shared_ptr<std::string> location, int horsePower, int nrSeats, std::string bodyStyle, std::string traction, std::string vin)
{
    horsePower_ = horsePower;
    nrSeats_ = nrSeats;
    bodyStyle_ = bodyStyle;
    traction_ = traction;
    vin_.reset(new Vin(vin));
    location_ = location;
}

Car::Car(Car& car)
{
    horsePower_ = car.horsePower_;
    nrSeats_ = car.nrSeats_;
    bodyStyle_ = car.bodyStyle_;
    traction_ = car.traction_;
    //this->vin_ = car.vin_; -->this will not work because it's unique for each vehicle
}

Car::~Car()
{

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
    return this->vin_->getVin();
}

int Car::getNrOfCarsAvailableInlocation()
{
    return location_.use_count() - 1;
}

Car& Car::operator=(Car& car)
{
    if(this != &car)
    {
        horsePower_ = car.horsePower_;
        nrSeats_ = car.nrSeats_;
        bodyStyle_ = car.bodyStyle_;
        traction_ = car.traction_;
        //this->vin_ = car.vin_; -->this will not work because it's unique for each vehicle
    }
    return *this;
}

std::ostream& Car::print(std::ostream& os)
{
    return os << "\n[Location] : [" << *location_.get() <<"]\n"
            << "[Nr_Of_Available_Cars_In_location] : [" << getNrOfCarsAvailableInlocation() << "]\n"
            << "[HP] : [" << horsePower_ << "]\n"
            << "[Nr_Of_Seats] : [" << nrSeats_ << "]\n"
            << "[Body_Style] : [" << bodyStyle_ << "]\n"
            << "[Traction] : [" << traction_ << "]\n"
            << "[Vehicle Identification Number] : [" << this->getVin() << "]\n";
}

std::ostream& operator<<(std::ostream& os, Car& car)
{
    return car.print(os);
}

void Car::driveTo(std::string location)
{
    if(!isDriven)
    {
        lock->lock();
        std::cout << "\nThe car with VIN: " << getVin() << " is being driven to " << location << std::endl;
        location_ = std::make_shared<std::string>(location);
        lock->unlock();
    }
}

std::string Car::getCarLocation()
{
    return *location_.get();
}