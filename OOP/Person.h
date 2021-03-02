//
// Created by Rushi Modi on 3/1/21.
//

#ifndef OOP_PERSON_H
#define OOP_PERSON_H


class Person {
    static int lifeExpectancy;
protected:
    int ssn =0;
public:
    Person(int age, std::string name, int sex);
    Person(int age, std::string name, int sex, int house_number, std::string street_name, std::string city);
    Person(const Person& p);
    Person& operator=(const Person& other);
    static const int female = 0;
    static const int male = 1;
    int age;
    std::string name;
    int sex;
    Address *address;

    ~Person();

    virtual void greet();
    static int getLifeExpectancy();
};



#endif //OOP_PERSON_H
