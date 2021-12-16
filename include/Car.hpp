#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include <memory>
#include <../include/Vin.hpp>
#include <../include/Lock.hpp>

const int FIRST = 0;

class Lock;

class Car
{   
public:
    Car();
    Car(std::shared_ptr<std::string> location, int horsePower, int nrSeats, std::string bodyStyle, std::string traction, std::string vin);
    Car(Car& car);
    ~Car();
    int getHorsePower();
    int getNrSeats();
    std::string getBodyStyle();
    std::string getTraction();
    std::string getVin();
    int getNrOfCarsAvailableInlocation();
    Car& operator=(Car& car);
    virtual std::ostream& print(std::ostream& os);
    friend std::ostream& operator<<(std::ostream& os, Car& car);
    void driveTo(std::string location);
    std::string getCarLocation();
    bool isDriven = false;
    
protected:
    int horsePower_;
    int nrSeats_;
    std::string bodyStyle_;
    std::string traction_;
    std::unique_ptr<Vin> vin_;
    std::shared_ptr<std::string> location_;
    std::unique_ptr<Lock> lock = std::make_unique<Lock>(this);
};

#endif