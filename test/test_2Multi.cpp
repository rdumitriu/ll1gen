#include "test2multi.hpp"

using namespace std;
using namespace test;

int main(int argc, char* argv[]) {
    Test2Multi tm;
    try {
        std::vector<bool> bools;
        bools.push_back(true);
        bools.push_back(false);
        bools.push_back(true);
        tm.setMultiBool(bools);

        std::vector<int> ints;
        ints.push_back(1);
        ints.push_back(2);
        ints.push_back(3);
        ints.push_back(4);
        tm.setMultiInt(ints);

        std::vector<std::string> strings;
        strings.push_back("aa");
        strings.push_back("bb");
        tm.setMultiString(strings);

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
        t2s1.setIsBool(true);
        t2s1.setIsReallyBool(std::make_shared<bool>(false));
        t2s1.setNumber(3);
        t2s1.setOptionalName(std::make_shared<std::string>("goo"));

        Test2Simple t2s2;
        t2s2.setIsBool(false);
        t2s2.setIsReallyBool(std::make_shared<bool>(true));
        t2s2.setNumber(4);
        t2s2.setOptionalName(std::make_shared<std::string>("foo"));

        Test2Simple t2s3;
        t2s3.setIsBool(false);
        t2s3.setNumber(5);

        Test2Multi tm2;
        std::vector<Test2Simple> objs;
        objs.push_back(t2s1);
        objs.push_back(t2s2);
        objs.push_back(t2s3);
        tm2.setMultiObj(objs);

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
