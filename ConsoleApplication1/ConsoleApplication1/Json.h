#include <string>
#include <rapidjson/document.h>

using namespace std;
using namespace rapidjson;
class Json {
public:
    void readJson(string field);
    void write(string field, Value value);
};