#ifndef ELECTRICCAR_HPP
#define ELECTRICCAR_HPP

#include <../include/Car.hpp>
#include <../include/Electric.hpp>

class ElectricCar : public Car, public Electric
{
public:
    ElectricCar();
    ElectricCar(int horsePower, int nrSeats, std::string bodyStyle, std::string traction, int battery);
    ElectricCar(const ElectricCar& electricCar);
    ~ElectricCar();
    void chargeBatteryByPercent(int percent);
    ElectricCar& operator=(const ElectricCar& electricCar);
    std::ostream& print(std::ostream& os);
};

#endif