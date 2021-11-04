#ifndef PETROL_HPP
#define PETROL_HPP

class Petrol
{
public:
    virtual void refuelTankByLiters(int liters) = 0;

protected:
    int tank_;
    int tankSize_;
};

#endif