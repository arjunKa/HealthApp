#include <fstream>
#include <iostream>
#include <string>
#include "rapidjson/filewritestream.h"
#include "rapidjson/writer.h"
#include "App.h"
#include <rapidjson/document.h>

using namespace std;
using namespace rapidjson;

class Json {
	HealthApp h;

public:
	Document getDoc();
	int getJsonInt(const char* field);
	string getJsonString(const char* field);
	void write(string field, Value value);

	void writeString(const char* field, const char* value);

	void getCalories(const char* field);


	void setCalories(const char* date, int calories);

};

Document Json::getDoc()
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
	return doc;
}

void Json::setCalories(const char* date, int calories)
{
	Document document = getDoc();

	// Check if the "trackCalories" field is an array
	if (document.HasMember("trackCalories") && document["trackCalories"].IsArray()) {
		Value newElement(kObjectType);  // Create a new object

		Value dateValue;
		dateValue.SetString(date, document.GetAllocator());
		newElement.AddMember("date", dateValue, document.GetAllocator());

		Value caloriesValue;
		caloriesValue.SetInt(250);
		newElement.AddMember("calories", caloriesValue, document.GetAllocator());

		document["trackCalories"].PushBack(newElement, document.GetAllocator());

		// Write the modified JSON back to a string
		StringBuffer buffer;
		Writer<StringBuffer> writer(buffer);
		document.Accept(writer);

		// Save the modified JSON back to the file
		std::ofstream output("data.json");
		output << buffer.GetString() << std::endl;

		std::cout << "Element added to the array." << std::endl;
	}
	else {
		std::cerr << "Field 'trackCalories' not found or not an array." << std::endl;
	}


}

void Json::getCalories(const char* field)
{
	Document document = getDoc();

	// Check if the field is an array
	if (document.HasMember(field) && document[field].IsArray()) {
		const Value& jsonArray = document[field];

		// Iterate through the array elements
		for (SizeType i = 0; i < jsonArray.Size(); ++i) {
			const Value& element = jsonArray[i];
			if (element.IsObject()) {
				if (element.HasMember("date") && element.HasMember("calories")) {
					const char* dateValue = element["date"].GetString();
					int caloriesValue = element["calories"].GetInt();
					std::cout << "Element " << i << ": Date: " << dateValue << ", Calories: " << caloriesValue << std::endl;
				}
			}
		}
	}
	else {
		std::cerr << "Field " << field << " not found or not an array." << std::endl;
	}



}

int Json::getJsonInt(const char* field)
{
	// Create a Document object 
	  // to hold the JSON data
	Document doc = getDoc();


	if (doc.HasMember(field) /* && doc[field].IsString()*/) {
		if (strcmp(field, "weight") == 0)
			return doc[field].GetInt();
		if (strcmp(field, "height") == 0)
			return doc[field].GetInt();
		if (strcmp(field, "age") == 0)
			return doc[field].GetInt();


	}
	else {
		std::cerr << "Field " << field << " not found or not a string." << std::endl;
	}

}

string Json::getJsonString(const char* field)
{
	// Create a Document object 
	  // to hold the JSON data
	Document doc = getDoc();


	if (doc.HasMember(field) && doc[field].IsString()) {

		if (strcmp(field, "gender") == 0)
			return doc[field].GetString();
		if (strcmp(field, "name") == 0)
			return doc[field].GetString();

	}
	else
	{
		std::cerr << "Field " << field << " not found or not a string." << std::endl;
	}

}

void Json::writeString(const char* field, const char* value)
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
	if (document.HasMember(field) && document[field].IsString())
	{
		document[field].SetString(value, document.GetAllocator());
	}

	// Write the modified JSON back to a string
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	document.Accept(writer);

	// Save the modified JSON back to the file
	std::ofstream output("data.json");
	output << buffer.GetString() << std::endl;
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
