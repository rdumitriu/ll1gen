#include "test2simple.hpp"

using namespace std;
using namespace test;

int main(int argc, char* argv[]) {
    Test2Simple t2s;
    try {
        t2s.setIsBool(true);
        t2s.setIsReallyBool(std::make_shared<bool>(false));
        t2s.setNumber(3);
        t2s.setOptionalName(std::make_shared<std::string>("goo"));

        cout << "Round 1 : " << t2s << endl;
        ostringstream out;
        out << t2s;
        istringstream in(out.str());
        Test2Simple copy;
        in >> copy;

        cout << "Round 1 - isB : " << copy.getIsBool() << endl;
        cout << "Round 1 - isRB: " << *(copy.getIsReallyBool()) << endl;
        cout << "Round 1 - name: " << *(copy.getOptionalName()) << endl;
        cout << "Round 1 - nmb : " << copy.getNumber() << endl;

        const_cast<std::shared_ptr<std::string> &>(t2s.getOptionalName()).reset();
        cout << "Round 2 : " << t2s << endl;
        ostringstream out2;
        out2 << t2s;
        istringstream in2(out2.str());
        in2 >> copy;
        cout << "Round 2 - name: " << (copy.getOptionalName().get() ? "FAILED" + *(copy.getOptionalName()) : " NULL") << endl;


    } catch(std::runtime_error & e) {
        cerr << "FAILED to parse:" << e.what() << endl;
    }
    return 0;
}
