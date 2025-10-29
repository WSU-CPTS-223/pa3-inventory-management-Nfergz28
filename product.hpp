#pragma once

#include "includes.hpp"

class Product
{
public:

    // default construcotr
    Product() ;

    // constructor
    Product(string id, string name, string creator, string group, string cost);

    // getters
    string getUniqId() const;
    string getProductName() const;
    string getManufacturer() const;
    string getCategory() const;
    string getPrice() const;

    // setters
    void setUniqId(string id);
    void setProductName(string name);
    void setManufacturer(string creator);
    void setCategory(string group);
    void setPrice(string cost);

    // print out all of the info
    void printDetails() const;

private:

    // names from the csv titles that is needed
    string uniq_id;
    string product_name;
    string manufacturer;
    string category;
    string price;

};