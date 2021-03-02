//
// Created by Rushi Modi on 3/1/21.
//
#include <iostream>
#include "Address.h"
#include "Person.h"


void Person::greet()
{
    std::cout<< "My name is: " <<
    name <<" "<< "my age is: "<< age << std::endl;
    if(address)
    {
        std::cout<< "I live at "<< address->house_number <<" "<<address->street_name
        <<address->city<<std::endl;
    }
}

int Person::getLifeExpectancy() {
    return lifeExpectancy;
}
int Person::lifeExpectancy = 65;


Person::Person(int age, std::string name, int sex, int house_number, std::string street_name, std::string city)
: Person(age, name, sex){
    if(address != nullptr)
        delete address;
    address = new Address(house_number, street_name, city);
}

Person::Person(int age, std::string name, int sex): age(age), name(name), sex(sex) {
    address = nullptr;

}

Person::~Person() {
    if(address != nullptr)
    {
        delete address;
        address = nullptr;
    }
}
//to avoid shallow copy we are making deep copy
Person::Person(const Person &p) :age (p.age), name(p.name), sex(p.sex){
    auto* a = p.address;
    address = new Address(
            a->house_number,
            a->street_name,
            a->city);
}

Person &Person::operator=(const Person &other) {
    auto *a = other.address;
    address = new Address(a->house_number, a->city, a->street_name);
    return *this;
}
