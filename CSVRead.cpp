#include "CSVRead.hpp"

// ================================================================================= constructor
CSVRead::CSVRead()
{

}

// ================================================================================= readCSV
void CSVRead::readCSV(const string &filename, Inventory<Product> &inventory)
{
    // open the file
    ifstream infile(filename);

    // check if the file opened successfully
    if (!infile.is_open())
    {
        cout << "!!!file not open!!!" << filename << endl;
        return;
    }

    string line;

    // consume the header line 
    getline(infile, line);

    // now read each line of the csv
    while (getline(infile, line))
    {
        // use stringstream to parse the line
        stringstream ss(line);
        string id, name, creator, category_string, cost;

        // read each one of the lines and make sure to to handle the commas
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, creator, ',');
        getline(ss, category_string, ',');
        getline(ss, cost, ',');

        // make sure to handle multiple category entries which is separated by | in the csv
        // look for the | character
        int pos = category_string.find('|');

        // -1 meaning that the | character was not found
        if (pos != -1)
        {
            // if found then only take the first category
            category_string = category_string.substr(0, pos);
        }

        // when the data is empty, replace is with "NA" like in the instructions
        if (id == "")
        {
            id = "NA";
        }

        if (name == "")
        {
            name = "NA";
        }

        if (creator == "")
        {
            creator = "NA";
        }

        if (category_string == "")
        {
            category_string = "NA";
        }

        if (cost == "")
        {
            cost = "NA";
        }

        // make a product object for inserting into the inventory
        Product newProduct(id, name, creator, category_string, cost);
        inventory.insertItem(newProduct);
    }

    // close the file
    infile.close();
}