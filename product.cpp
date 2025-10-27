#include "product.hpp"

// ================================================================================= constructor
Product::Product(string id, string name, string creator, string group, string cost)
{
    if (id != "")
    {
        uniq_id = id;
    }
    else 
    {
        uniq_id = "NA";
    }

    if (name != "")
    {
        product_name = name;
    }
    else 
    {
        product_name = "NA";
    }

    if (creator != "")
    {
        manufacturer = creator;
    }
    else
    {
        manufacturer = "NA";
    }

    if (group != "")
    {
        category = group;
    }
    else
    {
        category = "NA";
    }

    if (cost != "")
    {
        price = cost;
    }
    else
    {
        price = "NA";
    }
}

// ================================================================================= getters
string Product::getUniqId() const
{
    return uniq_id;
}

string Product::getProductName() const
{
    return product_name;
}

string Product::getManufacturer() const
{
    return manufacturer;
}

string Product::getCategory() const
{
    return category;
}

string Product::getPrice() const
{
    return price;
}

// ================================================================================= setters
void Product::setUniqId(string id)
{
    if (id != "") 
    {
        uniq_id = id;
    } 
    else 
    {
        uniq_id = "NA";
    }
}

void Product::setProductName(string name)
{
    if (name != "") 
    {
        product_name = name;
    } 
    else 
    {
        product_name = "NA";
    }
}

void Product::setManufacturer(string creator)
{
    if (creator != "") 
    {
        manufacturer = creator;
    } 
    else 
    {
        manufacturer = "NA";
    }
}

void Product::setCategory(string group)
{
    if (group != "") 
    {
        category = group;
    } 
    else 
    {
        category = "NA";
    }
}

void Product::setPrice(string cost)
{
    if (cost != "") 
    {
        price = cost;
    } 
    else 
    {
        price = "NA";
    }
}

// ================================================================================= printing
void Product::printDetails() const
{
    cout << "Unique ID: " << uniq_id << endl;
    cout << "Product Name: " << product_name << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Category: " << category << endl;
    cout << "Price: " << price << endl;
}