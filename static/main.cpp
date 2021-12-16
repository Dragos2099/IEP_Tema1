#include <../include/Car.hpp>
#include <../include/ElectricCar.hpp>
#include <../include/PetrolCar.hpp>
#include <../include/HybridCar.hpp>
#include <../include/Vin.hpp>
#include <../include/Lock.hpp>
#include <memory>
#include <thread>

const std::shared_ptr<std::string> location1 = std::make_shared<std::string>("Bucuresti");
const std::shared_ptr<std::string> location2 = std::make_shared<std::string>("Cluj");

Car *createCar(int choice)
{   
    switch(choice)
    {
        case 1: return new PetrolCar(location1, 75, 5, "Berlina", "FWD", "TM10ABC", 60, 45);
        case 2: return new ElectricCar(location1, 100, 7, "Combi", "AWD", "TM20DEF", 100);
        case 3: return new HybridCar(location1, 175, 5, "Combi", "FWD", "TM30GHI", 100, 60, 45);
    }
}

int main()
{   
    std::unique_ptr<Car> owner(createCar(1));
    std::cout << "\n-----OWNER----- " << *owner.get();
    //std::unique_ptr<Car> car2(owner);  --> error, it's unique
    std::unique_ptr<Car> newOwner = move(owner);
    std::cout << "\n-----newOwner----- " << *newOwner.get();
    //std::cout << " -----CAR1----- \n" << *owner.get(); --> segmentation fault
    
    std::shared_ptr<Car> firmCar(createCar(3));
    std::shared_ptr<Car> employee1(firmCar);
    std::shared_ptr<Car> employee2(firmCar);
    std::cout << "\n-----FirmCar----- " << *firmCar.get();
    std::cout << "\n-----Employee1----- " << *employee1.get();
    std::cout << "\n-----Employee2----- " << *employee2.get();
    std::cout << "\nThere are " << firmCar.use_count() << " pointers to the same car\n";
    
    employee1->driveTo("Resita");
    employee2->driveTo("Timisoara");

    return 0;
}
