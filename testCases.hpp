#pragma once

#include "includes.hpp"
#include "product.hpp"
#include "inventory.hpp"
#include "CSVRead.hpp"

class testCases
{
public:

    // constructor
    testCases();

    // run all test cases
    void runTests();

private:

    // tets for inserting to inventory
    void testInsert();

    // test for finding by ID number
    void testFind();

    // test for priting out the inventory
    void testPrint();

};