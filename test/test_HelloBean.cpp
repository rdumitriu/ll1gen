#include "hellobean.hpp"

using namespace std;
using namespace helloworld;

int main(int argc, char* argv[]) {
    HelloBean hb;
    try {
        hb.setAge(4);
        hb.setFname("Victor");
        hb.setLname("Adam");
        cout << "Round 1 : " << hb << endl;
        ostringstream out;
        out << hb;
        istringstream in(out.str());
        hb.setAge(0);
        hb.setFname("");
        hb.setLname("");
        in >> hb;

        cout << "Round 1 - fname: " << hb.getFname() << endl;
        cout << "Round 1 - lname: " << hb.getLname() << endl;
        cout << "Round 1 - age: " << hb.getAge() << endl;


        std::string content = " {\"fname\":\"Victor-Adam\",\"lname\":\"Dumitriu\",\"age\":5}";
        std::istringstream ss(content);
        ss >> hb;

        cout << "Round 2 - fname: " << hb.getFname() << endl;
        cout << "Round 2 - lname: " << hb.getLname() << endl;
        cout << "Round 2 - age: " << hb.getAge() << endl;

    } catch(std::runtime_error & e) {
        cerr << "FAILED to parse:" << e.what() << endl;
    }
    try {
        std::string content = " {\"fname\":\"\",\"lname\":\"RD\",\"age\": null}";
        std::istringstream ssn(content);
        ssn >> hb;
        cout << "FAILED Round 3 - fname: " << hb.getFname() << endl;
        cout << "FAILED Round 3 - lname: " << hb.getLname() << endl;
        cout << "FAILED Round 3 - age: " << hb.getAge() << endl;
    } catch(std::runtime_error & e) {
        cerr << "Correctly refused to parse:" << e.what() << endl;
    }
    return 0;
}
