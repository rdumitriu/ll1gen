#include "hellobean.hpp"

using namespace std;
using namespace helloworld;

int main(int argc, char* argv[]) {
    HelloBean hb;
    try {
        hb.age() = 4;
        hb.fname() = "Victor";
        hb.lname() = "Adam";
        cout << "Round 1 : " << hb << endl;
        ostringstream out;
        out << hb;
        istringstream in(out.str());
        hb.age() = 0;
        hb.fname() = "";
        hb.lname() = "";
        in >> hb;

        cout << "Round 1 - fname: " << hb.fname() << endl;
        cout << "Round 1 - lname: " << hb.lname() << endl;
        cout << "Round 1 - age: " << hb.age() << endl;


        std::string content = " {\"fname\":\"Victor-Adam\",\"lname\":\"Dumitriu\",\"age\":5}";
        std::istringstream ss(content);
        ss >> hb;

        cout << "Round 2 - fname: " << hb.fname() << endl;
        cout << "Round 2 - lname: " << hb.lname() << endl;
        cout << "Round 2 - age: " << hb.age() << endl;

    } catch(std::runtime_error & e) {
        cerr << "FAILED to parse:" << e.what() << endl;
    }
    try {
        std::string content = " {\"fname\":\"\",\"lname\":\"RD\",\"age\": null}";
        std::istringstream ssn(content);
        ssn >> hb;
        cout << "FAILED Round 3 - fname: " << hb.fname() << endl;
        cout << "FAILED Round 3 - lname: " << hb.lname() << endl;
        cout << "FAILED Round 3 - age: " << hb.age() << endl;
    } catch(std::runtime_error & e) {
        cerr << "Correctly refused to parse:" << e.what() << endl;
    }
    return 0;
}
