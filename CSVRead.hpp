#pragma once

#include "includes.hpp"
#include "product.hpp"
#include "inventory.hpp"

class CSVRead
{
public:

    // constructor
    CSVRead();

    // read from csv file and populate the inventory
    void readCSV(const string &filename, Inventory<Product> &inventory);

};