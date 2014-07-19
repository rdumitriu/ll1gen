#include "test2simple.hpp"

using namespace std;
using namespace test;

int main(int argc, char* argv[]) {
    Test2Simple t2s;
    try {
        t2s.isBool() = true;
        t2s.isReallyBool() = std::make_shared<bool>();
        *(t2s.isReallyBool()) = false;
        t2s.number() = 3;
        t2s.optionalName() = std::make_shared<std::string>();
        *t2s.optionalName() = "goo";

        cout << "Round 1 : " << t2s << endl;
        ostringstream out;
        out << t2s;
        istringstream in(out.str());
        Test2Simple copy;
        in >> copy;

        cout << "Round 1 - isB : " << copy.isBool() << endl;
        cout << "Round 1 - isRB: " << *(copy.isReallyBool()) << endl;
        cout << "Round 1 - name: " << *(copy.optionalName()) << endl;
        cout << "Round 1 - nmb : " << copy.number() << endl;

        t2s.optionalName().reset();
        cout << "Round 2 : " << t2s << endl;
        ostringstream out2;
        out2 << t2s;
        istringstream in2(out2.str());
        in2 >> copy;
        cout << "Round 2 - name: " << (copy.optionalName().get() ? "FAILED" + *(copy.optionalName()) : " NULL") << endl;


    } catch(std::runtime_error & e) {
        cerr << "FAILED to parse:" << e.what() << endl;
    }
    return 0;
}
