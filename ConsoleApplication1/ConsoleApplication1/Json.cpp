
#include "rapidjson/document.h"
#include <fstream>
#include <iostream>
#include <string>
#include "rapidjson/filewritestream.h"
#include "rapidjson/writer.h"


using namespace std;
using namespace rapidjson;

class Json {

public: void readJson(string field);
      void write(string field, Value value);

};

void Json::readJson(string field)
{
    // Open the file
    ifstream file("data.json");

    // Read the entire file into a string
    string json((istreambuf_iterator<char>(file)),
        istreambuf_iterator<char>());

    // Create a Document object 
      // to hold the JSON data
    Document doc;

    // Parse the JSON data
    doc.Parse(json.c_str());

    // Check for parse errors
    if (doc.HasParseError()) {
        cerr << "Error parsing JSON: "
            << doc.GetParseError() << endl;
        std::cout << "test";
    }

    // Now you can use the Document object to access the
    // JSON data
    std::cout << "1test";
}

void Json::write(string field, Value value)
{
    // Read the JSON file
    std::ifstream jsonFile("data.json");
    std::string jsonStr((std::istreambuf_iterator<char>(jsonFile)),
        std::istreambuf_iterator<char>());

    // Parse the JSON string
    Document document;
    document.Parse(jsonStr.c_str());

    // Check if parsing was successful
    if (document.HasParseError()) {
        std::cerr << "JSON parsing error: " << document.GetParseError() << std::endl;
        
    }

    // Modify the field you want to overwrite
    if (field.compare("name") == 0)
    {
        document["name"] = value;
    }
    else if (field.compare("weight") == 0)
    {
        

        document["weight"] = value;
    }
    else if (field.compare("age") == 0)
    {
        

        document["age"] = value;
    }
    else if (field.compare("height") == 0)
    {
        //double val = std::stod(value);

        document["height"] = value;
    }
    else if (field.compare("gender") == 0)
    {
        
        document["gender"] = value;
    }


  /*  if (document.HasMember("weight")) {
        
        try {
            double val = std::stod(value);
            std::cout << "Converted value: " << val << std::endl;
            document["weight"] = val;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument: " << e.what() << std::endl;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Out of range: " << e.what() << std::endl;
        }
    }*/


    // Write the modified JSON back to a string

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    document.Accept(writer);

    // Save the modified JSON back to the file
    std::ofstream output("data.json");
    output << buffer.GetString() << std::endl;

}
