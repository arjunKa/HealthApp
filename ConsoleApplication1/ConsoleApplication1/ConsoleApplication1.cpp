// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>



class HealthApp {



    public: double calculateBMI(double weight, double height)
    {
        return 703 * (weight / pow(height,2));

    }



    public: void weightPlan()
    {
        int weight;
        int height;
        int age;
        char gender;
        std::cout << "What is your age?\n";
        std::cin >> age;
        std::cout << "What is your gender (M or F)?\n";
        std::cin >> gender;
        std::cout << "What is your current weight?\n";
        std::cin >> weight;
        std::cout << "What is your current height in inches?\n";
        std::cin >> height;

    }

};


int main()
{
    int option = 1;
    std::cout << "Choose option:\n" << "1. Calculate BMI \n2. New Weight gain/loss plan\n";
    std::cin >> option;
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
