#include <iostream>
#include "Address.h"
#include "Person.h"
#include "Employee.h"
#include "EmpFactory.h"

int main()
{
   Person p(30, "Jane", Person::female);
   p.name = "Jane Doe";
   p.age = 30;

   Person *p2 = new Person(25, "John", Person::male);
   p2->name = "John doe";
   p2->age = 25;

   p2->greet();

   p.sex = Person::female;

   int le = Person::getLifeExpectancy();
   std::cout<<"Life Expectancy: "<<le<<std::endl;

   Person *p3 = new Person(20, "Rushi", Person::male );
   auto* address = new Address(123, "Oxford street", "London" );
   p3->address = address;
   // Copying ---------
   Person p4(*p3);
   p3->address->city = "Exeter";
   std::cout<<p4.address->city<<std::endl;
   p3->greet();
   Person p5 = *p3;
   p5.address->city = "my house";
   std::cout<<p5.address->city<<std::endl;
   std::cout<<p3->address->city<<std::endl;

   //Inheritance ---------
   Employee e(33, "Chris", Person::male, "Engineer");
   auto u = [](const Person& p)
   {
       std::cout<<p.name<<std::endl;
   };
   u(e);
   Person &pr = e; //valid

   Employee& er = static_cast<Employee&>(pr); //static_cast is used to make it valid otherwise invalid
   //and above statement is valid because we know that pr is an employee object.
   std::cout<<er.department<<std::endl;

    pr.greet();

   /* INVALID because static_cast doesn't perform any checking regarding end result reference if it's valid or not
   Person &pr2 = p;
   Employee& er2 = static_cast<Employee&> (pr2); */

   Person &pr2 = p;

   try{
       Employee& er2 = dynamic_cast<Employee&> (pr2);
       std::cout<<er2.department<<std::endl;
   }
   catch( const std::bad_cast& e)
   {
       std::cout<<"Cannot cast this!"<<std::endl;
   }

   Person* pp = &p;
   Employee* ep = dynamic_cast<Employee*> (pp);
   if(ep)
       std::cout<<ep->department<<std::endl;
   else
       std::cout<<"Failed to cast pointer"<<std::endl;


    delete p2;
    delete p3;
}
