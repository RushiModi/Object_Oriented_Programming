//
// Created by Rushi Modi on 3/2/21.
//
#include <iostream>
#include "Address.h"
#include "Person.h"
#include "Employee.h"

void Employee::greet() {
    Person::greet();
    std::cout<< "By the way I work in "<<department<<std::endl;
}