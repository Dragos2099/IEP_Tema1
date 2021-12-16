#include <../include/HybridCar.hpp>

HybridCar::HybridCar():Car()
{
    tank_ = 0;
    tankSize_ = 45;
    battery_ = 0;
}

HybridCar::HybridCar(std::shared_ptr<std::string> location, int horsePower, int nrSeats, std::string bodyStyle, 
                    std::string traction, std::string vin, int battery, int tankSize, int tank)
                    :Car(location, horsePower, nrSeats, bodyStyle, traction, vin)
{
    tank_ = tank;
    tankSize_ = tankSize;
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

HybridCar::HybridCar(HybridCar& hybridCar):Car(hybridCar)
{
    tank_ = hybridCar.tank_;
    tankSize_ = hybridCar.tankSize_;
    battery_ = hybridCar.battery_;
}

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

HybridCar& HybridCar::operator=( HybridCar& hybridCar)
{
    Car::operator=(hybridCar);
    tank_ = hybridCar.tank_;
    tankSize_ = hybridCar.tankSize_;
    battery_ = hybridCar.battery_;
    return *this;
}

std::ostream& HybridCar::print(std::ostream& os)
{
     return Car::print(os) << "[Tank] : [" << tank_ << "]\n"
                        << "[Tank_Size] : [" << tankSize_ << "]\n"
                        << "[Battery] : [" << battery_ << "]\n";
}
