#include <../include/ElectricCar.hpp>

ElectricCar::ElectricCar():Car()
{
    battery_ = 0;
}

ElectricCar::ElectricCar(int horsePower, int nrSeats, std::string bodyStyle,
                         std::string traction, int *vin, int battery):Car(horsePower, nrSeats, bodyStyle, traction, vin)
{
    battery_ = battery;
    if(battery_ > 100)
    {
        battery_ = 100;
    }
}

ElectricCar::ElectricCar(const ElectricCar& electricCar):Car(electricCar)
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

ElectricCar& ElectricCar::operator=(const ElectricCar& electricCar)
{
    Car::operator=(electricCar);
    battery_ = electricCar.battery_;
    return *this;
}

std::ostream& ElectricCar::print(std::ostream& os)
{
     return Car::print(os) << "[Battery] : [" << battery_ << "]\n";
}
