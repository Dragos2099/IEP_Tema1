#ifndef PETROLCAR_HPP
#define PETROLCAR_HPP

#include <../include/Car.hpp>
#include <../include/Petrol.hpp>

class PetrolCar : public Car, public Petrol
{
public:
    PetrolCar();
    PetrolCar(int horsePower, int nrSeats, std::string bodyStyle, std::string traction, int *vin, int tankSize, int tank);
    PetrolCar(const PetrolCar& petrolCar);
    ~PetrolCar();
    void refuelTankByLiters(int liters);
    PetrolCar& operator=(const PetrolCar& petrolCar);
    std::ostream& print(std::ostream& os);
};

#endif