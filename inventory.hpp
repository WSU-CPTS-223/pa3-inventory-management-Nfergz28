#pragma once

#include "includes.hpp"
#include "product.hpp"

template <typename T>
class Inventory
{
public:

    // constructor
    Inventory() 
    {
        size = 0;
        capacity = 100; // make capacity 100 by deafult then in the reading csv class, resize as needed for the full csv
        item = new T[capacity]; // create a dynamic array of type T
    }

    // destructor
    ~Inventory()
    {
        delete[] item; // found out that the brackets are needed for deleting dynamic arrays
    }

    // getters
    int getSize() const
    {
        return size;
    }

    int getCapacity() const
    {
        return capacity;
    }

    T *getItem() const
    {
        return item;
    }

    // setters
    void setSize(int newSize)
    {
        if (newSize >= 0)
        {
            size = newSize;
        }
        else
        {
            size = 0;
        }
    }

    void setCapacity(int newCapacity)
    {
        if (newCapacity >= 0)
        {
            capacity = newCapacity;
        }
        else
        {
            capacity = 0;
        }
    }

    void setItem(T *newItem)
    {
        if (newItem != nullptr)
        {
            item = newItem;
        }
        else
        {
            item = nullptr;
        }
    }

    // insert an item into the list 
    void insertItem(T item)
    {
        // check if we need to resize
        if (size == capacity) 
        {
            // resize if needed, as much as needed for the csv file
            int newCapacity = capacity * 2;

            // create a new dynamic array with the new capacity
            T *newItemArray = new T[newCapacity];

            // check if the new array was made without error
            if (newItemArray == nullptr)
            {
                cout << "!!!Failure!!!" << endl;
                return;
            }

            // copy over the old items to the new array
            for (int i = 0; i < size; i++)
            {
                newItemArray[i] = this->item[i]; // copies over the items
            }

            // delete the old array
            delete[] this->item;
            this->item = newItemArray; // point to the new array
            capacity = newCapacity; // update the capacity
        }
        // if no resize needed, just insert the item
        this->item[size] = item;        
        size++;
    }

    // find item by using the ID
    T* find(string inventoryid)
    {
        // go through the items
        for (int i = 0; i < size; i++)
        {
            // check if the id matches
            // if yes then return the item
            if (item[i].getUniqId() == inventoryid)
            {
                return &item[i];
            }
        }

        // if no id is found then
        return nullptr;
    }

    // print out all of the items that is held in the inventory by category
    // this still works with "NA" becasue those empty ones get filled in with "NA"
    void listInventory(string category_string) const
    {
        // for if any item is found
        bool found = false;

        // go through all of the items
        for (int i = 0; i < size; i++)
        {
            // check if the category matches
            // if yes then print out the id and the name
            if (item[i].getCategory() == category_string)
            {
                cout << "Unique ID: " << item[i].getUniqId() << ", Product Name: " << item[i].getProductName() << endl;
                found = true;
            }
        }

        // if no item is found for the category
        if (found == false)
        {
            cout << "!!!There are no items in this category!!!" << endl;
        }
    }

    // helper used only for testing
    // use similar logic fromt eh listInventory but make it change the count for true or false
    int countInventoryByCategory(string category_string) const
    {
        int count = 0;

        for (int i = 0; i < size; i++)
        {
            string category = item[i].getCategory();
            int pos = category.find('|');

            if (pos != -1)
            {
                category = category.substr(0, pos); // only use first category found substr on stack overflow
            }

            if (category == category_string)
            {
                count++;
            }
        }

        return count;
    }

private:

    int size;
    int capacity;
    T *item;
};