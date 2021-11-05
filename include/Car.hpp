#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>

class Car
{   
public:
    Car();
    Car(int horsePower, int nrSeats, std::string bodyStyle, std::string traction);
    Car(const Car& car);
    ~Car();
    int getHorsePower();
    int getNrSeats();
    std::string getBodyStyle();
    std::string getTraction();
    Car& operator=(const Car& car) = delete;
    virtual std::ostream& print(std::ostream& os);
    friend std::ostream& operator<<(std::ostream& os, Car& car);
    
protected:
    int horsePower_;
    int nrSeats_;
    std::string bodyStyle_;
    std::string traction_;
};

#endif