#include "testCases.hpp"

// ================================================================================= constructor
testCases::testCases()
{

}

// ================================================================================= runTests
void testCases::runTests()
{
    cout << "=================================================================================" << endl;
    cout << "All Tests" << endl;
    cout << "=================================================================================" << endl;

    testInsert();
    testFind();
    testPrint();

}

void testCases::testInsert()
{
    // test 1, inventroy insertion
    cout << "=================================================================================" << endl;
    cout << "Test 1: Inventory Insertion" << endl;
    cout << "=================================================================================" << endl;

    // create an inventory
    Inventory<Product> testInventory;

    // normal case
    // insert fixed values of products into the inventory
    Product one("1", "Toy Frog", "LEGO", "Toys", "8.00");
    Product two("2", "Phone", "Apple", "Electronics|Accessories", "1000.00");
    Product three("3", "Water Bottle", "YETI", "Outdoors|Hydration", "40.00");
    Product four("4", "Car", "Subaru", "Automotive", "47000.00");

    testInventory.insertItem(one);
    testInventory.insertItem(two);
    testInventory.insertItem(three);
    testInventory.insertItem(four);

    // make sure that the size had increased to 4
    assert(testInventory.getSize() == 4);

    // edge case
    // insert enough times to surpass the deaful 100 array size so it has to resize
    for (int i = 0; i < 101; i++)
    {
        // mak sure the products dont get duped from the normal case
        int idNum = i + 4;
        stringstream ss;
        ss << idNum;
        string idString = ss.str();

        Product pTemp(idString, "Testitem", "Testmaker", "Testcategory", "1.00");
        testInventory.insertItem(pTemp);
    }

    // check that the capacity had resized and increased
    assert(testInventory.getCapacity () >= 101);

    cout << "Test 1 has been passed" << endl;
}

void testCases::testFind()
{
    // test 2, find
    cout << "=================================================================================" << endl;
    cout << "Test 2: Finding Item(s) by ID Number" << endl;
    cout << "=================================================================================" << endl;

    // create a new inventory
    Inventory<Product> testInventory;

    // add in teh same products
    Product one("1", "Toy Frog", "LEGO", "NA", "8.00");
    Product two("2", "Phone", "Apple", "Electronics|Accessories", "1000.00");
    Product three("3", "Water Bottle", "YETI", "Outdoors|Hydration", "40.00");
    Product four("4", "Car", "Subaru", "Automotive", "47000.00");

    testInventory.insertItem(one);
    testInventory.insertItem(two);
    testInventory.insertItem(three);
    testInventory.insertItem(four);

    // normal case
    // make sure that the find function works by making a found that checks by the id number
    Product *foundOne = testInventory.find("1");
    assert(foundOne != nullptr);
    assert(foundOne->getProductName() == "Toy Frog");

    Product *foundTwo = testInventory.find("2");
    assert(foundTwo != nullptr);
    assert(foundTwo->getProductName() == "Phone");

    Product *foundThree = testInventory.find("3");
    assert(foundThree != nullptr);
    assert(foundThree->getProductName() == "Water Bottle");

    Product *foundFour = testInventory.find("4");
    assert(foundFour != nullptr);
    assert(foundFour->getProductName() == "Car");
    
    // edge case
    // use find with an invalid id
    Product *invalidOne = testInventory.find("123");
    assert(invalidOne == nullptr);

    Product *invalidTwo = testInventory.find("");
    assert(invalidTwo == nullptr);

    cout << "Test 2 has been past" << endl;
}

void testCases::testPrint()
{
    // test 3, print
    cout << "=================================================================================" << endl;
    cout << "Test 2: Print Item(s) by Category" << endl;
    cout << "=================================================================================" << endl;

    // create another inventory
    Inventory<Product> testInventory;

    // insert the same items
    Product one("1", "Toy Frog", "LEGO", "NA", "8.00");
    Product two("2", "Phone", "Apple", "Electronics|Accessories", "1000.00");
    Product three("3", "Water Bottle", "YETI", "Outdoors|Hydration", "40.00");
    Product four("4", "Car", "Subaru", "Automotive", "47000.00");

    testInventory.insertItem(one);
    testInventory.insertItem(two);
    testInventory.insertItem(three);
    testInventory.insertItem(four);

    // normal case
    // print out the categories, even with the |
    assert(testInventory.countInventoryByCategory("Toys") == 1); // should print out Toy Frog
    assert(testInventory.countInventoryByCategory("Electronics") == 1); // should print out Phone
    assert(testInventory.countInventoryByCategory("Outdoors") == 1); // should print out Water Bottle
    assert(testInventory.countInventoryByCategory("Automotive") == 1); // should print out Car

    // edge case
    // print out the invalid when typing in an invalid category (shoudl print !!!There are no items in this category!!!)
    assert(testInventory.countInventoryByCategory("YETI") == 0);
    assert(testInventory.countInventoryByCategory("") == 0);

    cout << "Test 3 has been passed" << endl;
}