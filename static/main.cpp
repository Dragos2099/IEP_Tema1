#include <../include/Car.hpp>
#include <../include/ElectricCar.hpp>
#include <../include/PetrolCar.hpp>
#include <../include/HybridCar.hpp>
#include <memory>

int main()
{
    
    HybridCar hybridCar1(100, 5, "Berlina", "FWD", 100, 60, 45);
    //HybridCar hybridCar2(hybridCar1);
    HybridCar hybridCar3;
    //hybridCar3 = hybridCar2;
    

    
    PetrolCar petrolCar1(100, 5, "Berlina", "FWD", 60, 45);
    PetrolCar petrolCar2(petrolCar1);
    PetrolCar petrolCar3;
    //petrolCar3 = petrolCar2;
    

    
    ElectricCar electricCar1(100, 5, "Berlina", "FWD", 100);
    //ElectricCar electricCar2(electricCar1);
    ElectricCar electricCar3;
    electricCar3 = electricCar1;
    
}
