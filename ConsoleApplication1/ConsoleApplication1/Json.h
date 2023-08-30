
#include <string>
#include <rapidjson/document.h>

using namespace std;
using namespace rapidjson;
class Json {
public:
	Document getDoc();
	int getJsonInt(const char* field);
	string getJsonString(const char* field);
	void write(string field, Value value);

	void writeString(const char* field, const char* value);
	void getCalories(const char* field);
	void setCalories(const char* date, int calories);
};
