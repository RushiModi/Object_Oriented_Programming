//
// Created by Rushi Modi on 3/2/21.
//
#include "Address.h"
#include "Person.h"
#ifndef OOP_EMPLOYEE_H
#define OOP_EMPLOYEE_H


class Employee: public Person {
    friend class EmpFactory;
    int taxId;
public:
    Employee();
    Employee(int age, std::string const& name, int sex, std::string department = std::string())
        : Person(age, name, sex), department(department){
    };

    std::string department;

    void greet() override;

};


#endif //OOP_EMPLOYEE_H
