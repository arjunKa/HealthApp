#include <iostream>
#include <ctime>
#include "Json.h"
#include <rapidjson/document.h>
#include "rapidjson/filewritestream.h"
#include "rapidjson/writer.h"
using namespace rapidjson;

class HealthApp {

	int weight = 0;
	int height = 0;
	int age = 0;
	string gender = "X";
public: Json j;
	  string name = "user";

public:
	void setWeight(int data);
	void setHeight(int data);
	void setAge(int data);
	void setGender(const char* data);
	void setName(const char* data);
	void calculateBMI(double weight, double height);
	double calculateWeightGain(double weightToGain, double days);
	void setData();
	void getData();
	void weightPlan();
	void calorieTracker();
	void options();
	void logo();

};




void HealthApp::setWeight(int data)
{
	weight = data;
}
void HealthApp::setHeight(int data)
{
	height = data;
}
void HealthApp::setAge(int data)
{
	age = data;
}
void HealthApp::setName(const char* data)
{
	name = data;
}

void HealthApp::setGender(const char* data)
{
	gender = data;
}

void HealthApp::calculateBMI(double weight, double height)
{
	double bmi = 0;
	try
	{
		bmi = 703 * (weight / pow(height, 2));
	}
	catch (const std::exception& ex)
	{
		std::cout << "error";
	}

	cout << "Your BMI is " << round(bmi*100.0)/100.0 <<endl;
	options();


}

double HealthApp::calculateWeightGain(double weightToGain, double days)
{
	int calories = int(weightToGain * 3500 / (days));
	return calories;


}


void HealthApp::setData()
{
	std::cout << "What is your name?\n";
	std::cout << "> ";
	std::cin >> name;
	j.writeString("name", name.c_str());

	std::cout << "What is your age?\n";
	std::cout << "> ";
	std::cin >> age;
	j.write("age", Value(age));

	std::cout << "What is your gender (M or F)?\n";
	std::cout << "> ";
	std::cin >> gender;
	j.writeString("gender", gender.c_str());

	std::cout << "What is your current weight?\n";
	std::cout << "> ";
	std::cin >> weight;
	j.write("weight", Value(weight));

	std::cout << "What is your current height in inches?\n";
	std::cout << "> ";
	std::cin >> height;
	j.write("height", Value(height));
	std::cout << endl;

	std::cout << "All data set.\n";

	options();

}
void HealthApp::getData()
{
	std::cout << "What is your name?\n";
	std::cout << name << endl;
	std::cout << "What is your age?\n";
	std::cout << age << endl;
	std::cout << "What is your gender (M or F)?\n";
	std::cout << gender << endl;
	std::cout << "What is your current weight?\n";
	std::cout << weight << endl;
	std::cout << "What is your current height in inches?\n";
	std::cout << height << endl;
	options();

}

void HealthApp::weightPlan()
{
	if (weight == 0) {
		std::cout << "Weight data is missing.\n";
		std::cout << "What is your current weight?\n";
		std::cout << "> ";
		std::cin >> weight;
		j.write("weight", Value(weight));

	}
	if (height == 0) {
		std::cout << "Height data is missing.\n";
		std::cout << "What is your current height?\n";
		std::cout << "> ";
		std::cin >> height;
		j.write("height", Value(height));

	}
	if (age == 0) {
		std::cout << "Age data is missing.\n";
		std::cout << "What is your current age?\n";
		std::cout << "> ";
		std::cin >> age;
		j.write("weight", Value(age));

	}
	if (strcmp(gender.c_str(), "X") == 0) {
		std::cout << "Gender data is missing.\n";
		std::cout << "What is your gender (M or F)?\n";
		std::cout << "> ";
		std::cin >> gender;
		j.writeString("gender", gender.c_str());

	}

}

void HealthApp::calorieTracker()

{
	int option;
	std::cout << "\nChoose option:\n";
	std::cout << "1. Enter new calorie data\n";
	std::cout << "2. View calories\n";
	std::cout << "3. Go Back\n";
	std::cout << "> ";
	std::cin >> option;


	//std::time_t currentTime = std::time(nullptr);
	//std::tm* localTime = std::localtime(&currentTime);

	//char buffer[80];  // Buffer to store the formatted date
	//std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", localTime);
	string date;

	switch (option)
	{
	case 1:
		std::cout << "Enter the date (format: MM/DD/YYYY):\n";
		std::cout << "> ";
		std::cin >> date;
		std::cout << "Enter how many calories you burned today:\n";
		std::cout << "> ";
		std::cin >> option;

		j.setCalories(date.c_str(), option);
		option = 1;
		break;

	case 2:
		j.getCalories("trackCalories");

		break;

	default:
		break;
	}

	if (option > 2)
		options();
	else
		calorieTracker();
}

void HealthApp::options()
{
	int option = 1;
	std::cout << "\nChoose option:\n" <<
		"1. Calculate BMI\n" <<
		"2. Weight gain/loss plan\n" <<
		"3. Calorie Tracker\n" <<
		"4. set data\n" <<
		"5. get data\n"
		"6. exit" << endl;
	std::cout << "> ";
	std::cin >> option;

	switch (option)
	{
	case 1:
		calculateBMI(weight, height);
		break;

	case 2:
		weightPlan();
		break;

	case 3:
		calorieTracker();
		break;

	case 4:
		setData();
		break;
	case 5:
		getData();
		break;

	default:
		exit(0);
		break;
	}


}

void HealthApp::logo()
{
	std::cout << "  *****     *****" << std::endl;
	std::cout << "********   ********" << std::endl;
	std::cout << "*******************" << std::endl;
	std::cout << " *****************" << std::endl;
	std::cout << "  ***************" << std::endl;
	std::cout << "    ***********" << std::endl;
	std::cout << "      *******" << std::endl;
	std::cout << "        ***" << std::endl;
}


int main()
{
	std::cout << "Welcome to the Health App." << std::endl;
	HealthApp h;
	h.setWeight(h.j.getJsonInt("weight"));
	h.setHeight(h.j.getJsonInt("height"));
	h.setAge(h.j.getJsonInt("age"));
	h.setName(h.j.getJsonString("name").c_str());
	h.setGender(h.j.getJsonString("gender").c_str());



	h.options();

}
