#include <iostream>
#include <string>

#include "includes.hpp"
#include "product.hpp"
#include "inventory.hpp"
#include "CSVRead.hpp"
#include "testCases.hpp"

using namespace std;

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}
// add inventory stuff
void evalCommand(string line, Inventory<Product> &inventory)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        string id = line.substr(5); // everything after "find "
        
        if (id == "") // the space is empty
        {
            cout << "!!!Please provide an inventory id!!!" << endl;
            return;
        }

        Product *found = inventory.find(id);

        if (found != nullptr)
        {
            found->printDetails();
        }
        else
        {
            cout << "!!!Inventory/Product not found!!!" << endl;
        }
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        string category = line.substr(14); // everything after "listInventory "

        if (category == "")
        {
            cout << "Please provide a category." << endl;
            return;
        }

        inventory.listInventory(category);

    }
}
// add the inventory stuff
Inventory<Product> bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices

    // run th etest cases
    testCases tests;
    tests.runTests();

    // create the inventory
    Inventory<Product> inventory;

    // read csv and load all of the data
    CSVRead reader;
    reader.readCSV("marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv", inventory);

    cout << "\nInventory system initialized with " << inventory.getSize() << " items." << endl;

    return inventory;
}

int main(int argc, char const *argv[])
{
    // Inventory<Product> object and returns it to us here
    Inventory<Product> inventory = bootStrap();

    string line;

    // run until the user types ":quit"
    // start the user input loop
    cout << "\n> ";
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line, inventory);
        }
        else
        {
            cout << "!!!Command not supported. Enter :help for list of supported commands!!!" << endl;
        }

        cout << "\n> "; // print new prompt after each command
    }

    return 0;
}
