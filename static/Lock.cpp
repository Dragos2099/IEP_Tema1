#include <../include/Lock.hpp>

Lock::Lock(Car *car)
{
    car_ = car;
    mutexPtr_ = std::make_unique<std::mutex>();
    mutexPtr_->unlock();
}

Lock::~Lock()
{
    unlock();
}

void Lock::lock()
{
    if(!car_->isDriven)
    {
        mutexPtr_->lock();
        std::cout << "\nLocked\n";
        car_->isDriven = true;
    }
}

void Lock::unlock()
{
    if(car_->isDriven)
    {
        mutexPtr_->unlock();
        std::cout << "\nUnlocked\n";
        car_->isDriven = false;
    }
}