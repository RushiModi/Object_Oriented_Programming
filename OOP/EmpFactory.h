//
// Created by Rushi Modi on 3/2/21.
//

#ifndef OOP_EMPFACTORY_H
#define OOP_EMPFACTORY_H



class EmpFactory
{
public:
    Employee makeEmp(int id)
    {
        Employee emp;
        emp.taxId = id;
        return emp;
    }

};



#endif //OOP_EMPFACTORY_H
