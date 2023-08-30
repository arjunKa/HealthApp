
#include <string>


using namespace std;
using namespace rapidjson;
class HealthApp {

public:
	void setWeight(int data);
	void setHeight(int data);
	void setAge(int data);
	void setGender(const char* data);
	void setName(const char* data);
	double calculateBMI(double weight, double height);
	double calculateWeightGain(double weightToGain, double days);
	void setData();
	void getData();
	void weightPlan();
	void options();
};