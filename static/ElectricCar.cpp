#include <../include/ElectricCar.hpp>

ElectricCar::ElectricCar():Car()
{
    battery_ = 0;
}

ElectricCar::ElectricCar(int horsePower, int nrSeats, std::string bodyStyle,
                         std::string traction, int battery):Car(horsePower, nrSeats, bodyStyle, traction)
{
    battery_ = battery;
    if(battery_ > 100)
    {
        battery_ = 100;
    }
}
/*
ElectricCar::ElectricCar(const ElectricCar& electricCar):Car(electricCar)
{
    battery_ = electricCar.battery_;
}
*/
ElectricCar::~ElectricCar()
{
    //std::cout << "\nDestructor ElectricCar\n";
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
    horsePower_ = electricCar.horsePower_;
    nrSeats_ = electricCar.nrSeats_;
    bodyStyle_ = electricCar.bodyStyle_;
    traction_ = electricCar.traction_;
    battery_ = electricCar.battery_;
    return *this;
}

std::ostream& ElectricCar::print(std::ostream& os)
{
     return Car::print(os) << "[Battery] : [" << battery_ << "]\n";
}
