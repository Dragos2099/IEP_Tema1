#include <../include/Car.hpp>
#include <../include/ElectricCar.hpp>
#include <../include/PetrolCar.hpp>
#include <../include/HybridCar.hpp>
#include <memory>

int main()
{
    /*
    Car car1(100, 5, "Berlina", "FWD");
    Car car2(car1);
    Car car3;
    std::cout << car1 << car2 << car3;
    car3 = car2;
    */
    //std::unique_ptr<Car> car1 = (std::unique_ptr<Car>) new Car();
    //car1->refuelTankByLiters(100);
    //std::cout << car1->getBodyStyle() << "\nda\n";
    
    //ElectricCar car1 = ElectricCar(100, 5, "Berlina", "FWD", 100);
    //ElectricCar car2(car1);
    //ElectricCar car3;
    //car3 = car2;
    //std::cout << car1 << car2 << car3;
    auto *ceva = new HybridCar();
    ceva->refuelTankByLiters(20);
    ceva->chargeBatteryByPercent(65);
    std::cout << (*ceva);
    //free(ceva);
    
}
