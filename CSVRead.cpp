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
    // read each line in the file
    while (getline(infile, line))
    {
        vector<string> fields; // stores individual fields
        string current;        // current field being read
        bool insideQuotes = false; // tracks quoted fields

        // parse the line character by character
        for (size_t i = 0; i < line.size(); i++)
        {
            char c = line[i];

            if (c == '"')
            {
                // handle double quotes inside quoted string
                if (insideQuotes && i + 1 < line.size() && line[i + 1] == '"')
                {
                    current += '"';
                    i++; // skip next quote
                }
                else
                {
                    insideQuotes = !insideQuotes; // go into quote mode
                }
            }
            else if (c == ',' && !insideQuotes)
            {
                fields.push_back(current); // end of a field
                current.clear();
            }
            else
            {
                current += c;
            }
        }

        fields.push_back(current); // add the last field

        // skip incomplete lines
        if (fields.size() < 8) 
        {
            continue;
        }
        // extract needed fields from CSV
        string id = fields[0];
        string name = fields[1];
        string creator = fields[2];
        string category_string = fields[4];
        string cost = fields[7];

        // helper lambda to trim leading spaces found on stack overflow
        auto trim = [](string &s)
        {
            while (!s.empty() && isspace(s.front())) s.erase(s.begin());
            while (!s.empty() && isspace(s.back())) s.pop_back();
        };

        // trim all fields
        trim(id);
        trim(name);
        trim(creator);
        trim(category_string);
        trim(cost);

        // replace empty fields with "NA"
        if (id.empty()) id = "NA";
        if (name.empty()) name = "NA";
        if (creator.empty()) creator = "NA";
        if (category_string.empty()) category_string = "NA";
        if (cost.empty()) cost = "NA";

        // keep only the first category if multiple exist
        int pos = category_string.find('|');

        if (pos != -1)
        {
            category_string = category_string.substr(0, pos);
            trim(category_string);
        }

        // create Product object with all 5 fields
        Product newProduct(id, name, creator, category_string, cost);

        // add product to inventory
        inventory.insertItem(newProduct);
    }

    // close file when done
    infile.close();
}