//
// Created by Rushi Modi on 3/1/21.
//

#ifndef OOP_ADDRESS_H
#define OOP_ADDRESS_H


class Address {
public:
    int house_number;
    std::string street_name;
    std::string city;

    Address(int house_number, std::string const& street_name, std::string const& city):
        house_number(house_number), street_name(street_name), city(city){}


};


#endif //OOP_ADDRESS_H
