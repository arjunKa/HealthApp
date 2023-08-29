// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Json.h"

#include "rapidjson/document.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/writer.h"
using namespace rapidjson;

class HealthApp {
    int weight=0;
    int height=0;
    int age=0;
    char gender='X';
    Json j;


    public: double calculateBMI(double weight, double height)
    {
        try
        {
            return 703 * (weight / pow(height, 2));
        }
        catch (const std::exception& ex)
        {
            std::cout << "error";
        }
        

    }

    public: double calculateWeightGain(double weightToGain, double days)
    {
        int calories = int( weightToGain * 3500 / (days) );
        return calories;


    }



    public: 

        void setData() 
        {
            std::cout << "What is your age?\n";
            std::cin >> age;
            j.write("age", Value(age));
            std::cout << "What is your gender (M or F)?\n";
            std::cin >> gender;
            std::cout << "What is your current weight?\n";
            std::cin >> weight;
            j.write("weight", Value(weight));
            std::cout << "What is your current height in inches?\n";
            std::cin >> height;
            j.write("height", Value(height));
            options();

        }
        void getData()
        {
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

        void weightPlan()
        {
            if (weight == 0) {
                std::cout << "Weight data is missing.\n";
                std::cout << "What is your current weight?\n";
                std::cin >> weight;
                j.write("weight", Value(weight));
                

            }
            if (height == 0) {
                std::cout << "Height data is missing.\n";
                std::cout << "What is your current height?\n";
                std::cin >> height;
                j.write("height", Value(height));

            }
            if (age == 0) {
                std::cout << "Age data is missing.\n";
                std::cout << "What is your current age?\n";
                std::cin >> age;
                j.write("weight", Value(age));

            }
            if (gender == 'X') {
                std::cout << "Gender data is missing.\n";
                std::cout << "What is your gender (M or F)?\n";
                std::cin >> gender;
                Value charVal;
                std::string charString(1, gender);
                charVal.SetString(charString.c_str(), charString.length());
                //j.write("weight", charVal);

            }



        }

        void options()
        {
            int option = 1;
            std::cout << "Choose option:\n" <<
                "1. Calculate BMI\n" <<
                "2. Weight gain/loss plan\n" <<
                "3. Exercise plan\n" <<
                "4. set data" << endl <<
                "5. get data" << endl;
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
                break;

            case 4:
                setData();
                break;
            case 5:
                getData();
                break;

            default:
                break;
            }


        }

};


int main()
{
    HealthApp h;
    h.options();
    
    
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
