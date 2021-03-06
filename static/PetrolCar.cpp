#include <../include/PetrolCar.hpp>

PetrolCar::PetrolCar():Car()
{
    tank_ = 0;
    tankSize_ = 45;
}

PetrolCar::PetrolCar(std::shared_ptr<std::string> location, int horsePower, int nrSeats, std::string bodyStyle,
                         std::string traction, std::string vin, int tankSize, int tank):Car(location, horsePower, nrSeats, bodyStyle, traction, vin)
{
    tank_ = tank;
    tankSize_ = tankSize;
    if(tank_ > tankSize_)
    {
        tank_ = tankSize_;
    }
}

PetrolCar::PetrolCar(PetrolCar& petrolCar):Car(petrolCar)
{
    tank_ = petrolCar.tank_;
    tankSize_ = petrolCar.tankSize_;
}

PetrolCar::~PetrolCar()
{
    //std::cout << "\nDestructor PetrolCar\n";
}

void PetrolCar::refuelTankByLiters(int liters)
{
    tank_ = tank_ + liters;
    if(tank_ > tankSize_)
    {
        tank_ = tankSize_;
    }
}

PetrolCar& PetrolCar::operator=( PetrolCar& petrolCar)
{
    Car::operator=(petrolCar);
    tank_ = petrolCar.tank_;
    tankSize_ = petrolCar.tankSize_;
    return *this;
}

std::ostream& PetrolCar::print(std::ostream& os)
{
     return Car::print(os) << "[Tank] : [" << tank_ << "]\n"
                        << "[Tank_Size] : [" << tankSize_ << "]\n";
}
