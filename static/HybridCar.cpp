#include <../include/HybridCar.hpp>

HybridCar::HybridCar():Car()
{
    tank_ = 0;
    tankSize_ = 45;
    battery_ = 0;
}

HybridCar::HybridCar(int horsePower, int nrSeats, std::string bodyStyle, 
                    std::string traction, int battery, int tankSize, int tank)
                    :Car(horsePower, nrSeats, bodyStyle, traction)
{
    tank_ = tank;
    tankSize_ = tankSize_;
    if(tank_ > tankSize_)
    {
        tank_ = tankSize_;
    }

    battery_ = battery;
    if(battery_ > 100)
    {
        battery_ = 100;
    }
}
/*
HybridCar::HybridCar(const HybridCar& hybridCar):Car(hybridCar)
{
    tank_ = hybridCar.tank_;
    tankSize_ = hybridCar.tankSize_;
    battery_ = hybridCar.battery_;
}
*/
HybridCar::~HybridCar()
{
    //std::cout << "\nDestructor HybridCar\n";
}

void HybridCar::refuelTankByLiters(int liters)
{
    tank_ = tank_ + liters;
    if(tank_ > tankSize_)
    {
        tank_ = tankSize_;
    }
}

void HybridCar::chargeBatteryByPercent(int percent)
{
    battery_ = battery_ + percent;
    if(percent > 100)
    {
        battery_ = 100;
    }
}
/*
HybridCar& HybridCar::operator=(const HybridCar& hybridCar)
{
    horsePower_ = hybridCar.horsePower_;
    nrSeats_ = hybridCar.nrSeats_;
    bodyStyle_ = hybridCar.bodyStyle_;
    traction_ = hybridCar.traction_;
    tank_ = hybridCar.tank_;
    tankSize_ = hybridCar.tankSize_;
    battery_ = hybridCar.battery_;
    return *this;
}
*/
std::ostream& HybridCar::print(std::ostream& os)
{
     return Car::print(os) << "[Tank] : [" << tank_ << "]\n"
                        << "[Tank_Size] : [" << tankSize_ << "]\n"
                        << "[Battery] : [" << battery_ << "]\n";
}
