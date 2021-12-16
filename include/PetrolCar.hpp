#ifndef PETROLCAR_HPP
#define PETROLCAR_HPP

#include <../include/Car.hpp>
#include <../include/Petrol.hpp>

class PetrolCar : public Car, public Petrol
{
public:
    PetrolCar();
    PetrolCar(std::shared_ptr<std::string> location, int horsePower, int nrSeats, std::string bodyStyle, std::string traction, std::string vin, int tankSize, int tank);
    PetrolCar(PetrolCar& petrolCar);
    ~PetrolCar();
    void refuelTankByLiters(int liters);
    PetrolCar& operator=( PetrolCar& petrolCar);
    std::ostream& print(std::ostream& os);
};

#endif