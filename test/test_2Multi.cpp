#include "test2multi.hpp"

using namespace std;
using namespace test;

int main(int argc, char* argv[]) {
    Test2Multi tm;
    try {
        tm.multiBool().push_back(true);
        tm.multiBool().push_back(false);
        tm.multiBool().push_back(true);

        tm.multiInt().push_back(1);
        tm.multiInt().push_back(2);
        tm.multiInt().push_back(3);
        tm.multiInt().push_back(4);

        tm.multiString().push_back("aa");
        tm.multiString().push_back("bb");

        cout << "Round 1 serialize: " << tm << endl;
        ostringstream out;
        out << tm;
        istringstream in(out.str());
        Test2Multi copy;
        in >> copy;
        cout << "Round 1 deserialize: " << copy << endl;
        istringstream in1(out.str());
        in1 >> copy;
        cout << "Round 1.1 deserialize: " << copy << endl;


        std::string content = "{\"multiBool\":[],\"multiString\":[ ],\"multiInt\":[\n],\"multiObj\":[]}";
        istringstream in2(content);
        in2 >> copy;
        cout << "Round 1.2 deserialize: " << copy << endl;


        Test2Simple t2s1;
        t2s1.isBool() = true;
        t2s1.isReallyBool() = std::make_shared<bool>();
        *(t2s1.isReallyBool()) = false;
        t2s1.number() = 3;
        t2s1.optionalName() = std::make_shared<std::string>();
        *t2s1.optionalName() = "goo";

        Test2Simple t2s2;
        t2s2.isBool() = false;
        t2s2.isReallyBool() = std::make_shared<bool>();
        *(t2s2.isReallyBool()) = true;
        t2s2.number() = 4;
        t2s2.optionalName() = std::make_shared<std::string>();
        *t2s2.optionalName() = "foo";

        Test2Multi tm2;
        tm2.multiObj().push_back(t2s1);
        tm2.multiObj().push_back(t2s2);

        ostringstream out2;
        out2 << tm2;
        cout << "Round 2 serialize: " << tm2 << endl;
        istringstream intm2(out2.str());
        intm2 >> copy;
        cout << "Round 2 deserialize: " << copy << endl;


    } catch(std::runtime_error & e) {
        cerr << "FAILED to parse:" << e.what() << endl;
    }
    return 0;
}
