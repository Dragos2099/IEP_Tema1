#include <../include/Car.hpp>
#include <../include/ElectricCar.hpp>
#include <../include/PetrolCar.hpp>
#include <../include/HybridCar.hpp>
#include <memory>

int main()
{

    int *p =new int[20];
    for(int i = 0; i < 12; i++)
    {
        p[i]= (i % 10);
    }


    HybridCar hybridCar1(100, 5, "Berlina", "FWD", p, 100, 60, 45);
    HybridCar hybridCar2;
    HybridCar hybridCar3;
    hybridCar3 = hybridCar2 = hybridCar1;
    hybridCar3 = hybridCar3;
    std::cout << " -----CAR1----- \n" << hybridCar1;
    std::cout << " -----CAR2----- \n" << hybridCar2;
    std::cout << " -----CAR3----- \n" << hybridCar3;
    

    
    // PetrolCar petrolCar1(100, 5, "Berlina", "FWD", 60, 45);
    // PetrolCar petrolCar2(petrolCar1);
    // PetrolCar petrolCar3;
    // petrolCar3 = petrolCar2;
    // std::cout << petrolCar1;
    

    
    //  ElectricCar electricCar1(100, 5, "Berlina", "FWD", 100);
    //  ElectricCar electricCar2(electricCar1);
    //  ElectricCar electricCar3;
    //  electricCar3 = electricCar1;
    //  std::cout << electricCar3;
}
