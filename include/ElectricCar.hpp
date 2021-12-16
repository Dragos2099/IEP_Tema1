#ifndef ELECTRICCAR_HPP
#define ELECTRICCAR_HPP

#include <../include/Car.hpp>
#include <../include/Electric.hpp>

class ElectricCar : public Car, public Electric
{
public:
    ElectricCar();
    ElectricCar(std::shared_ptr<std::string> location, int horsePower, int nrSeats, std::string bodyStyle, std::string traction, std::string vin, int battery);
    ElectricCar(ElectricCar& electricCar);
    ~ElectricCar();
    void chargeBatteryByPercent(int percent);
    ElectricCar& operator=( ElectricCar& electricCar);
    std::ostream& print(std::ostream& os);
};

#endif