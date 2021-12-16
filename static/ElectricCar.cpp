#include <../include/ElectricCar.hpp>

ElectricCar::ElectricCar():Car()
{
    battery_ = 0;
}

ElectricCar::ElectricCar(std::shared_ptr<std::string> location, int horsePower, int nrSeats, std::string bodyStyle,
                         std::string traction, std::string vin, int battery):Car(location, horsePower, nrSeats, bodyStyle, traction, vin)
{
    battery_ = battery;
    if(battery_ > 100)
    {
        battery_ = 100;
    }
}

ElectricCar::ElectricCar(ElectricCar& electricCar):Car(electricCar)
{
    battery_ = electricCar.battery_;
}

ElectricCar::~ElectricCar()
{
}

void ElectricCar::chargeBatteryByPercent(int percent)
{
    battery_ = battery_ + percent;
    if(percent > 100)
    {
        battery_ = 100;
    }
}

ElectricCar& ElectricCar::operator=( ElectricCar& electricCar)
{
    Car::operator=(electricCar);
    battery_ = electricCar.battery_;
    return *this;
}

std::ostream& ElectricCar::print(std::ostream& os)
{
     return Car::print(os) << "[Battery] : [" << battery_ << "]\n";
}
