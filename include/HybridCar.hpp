#ifndef HYBRIDCAR_HPP
#define HYBRIDCAR_HPP

#include <../include/Petrol.hpp>
#include <../include/Electric.hpp>
#include <../include/Car.hpp>

class HybridCar : public Car, public Petrol, public Electric
{
public:
    HybridCar();
    HybridCar(int horsePower, int nrSeats, std::string bodyStyle, std::string traction, int battery, int tankSize, int tank);
    HybridCar(const HybridCar& hybridCar);
    ~HybridCar();
    void refuelTankByLiters(int liters);
    void chargeBatteryByPercent(int percent);
    HybridCar& operator=(const HybridCar& hybridCar);
    std::ostream& print(std::ostream& os);
};

#endif
