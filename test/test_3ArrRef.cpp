#include "testnevecs.hpp"

using namespace std;
using namespace test;

int main(int argc, char* argv[]) {
    TestNEVecs tnv;
    try {
        tnv.boolVec().push_back(std::make_shared<bool>(true));
        std::shared_ptr<bool> p_nb;
        tnv.boolVec().push_back(p_nb);
        tnv.boolVec().push_back(std::make_shared<bool>(false));

        tnv.intVec().push_back(std::make_shared<int>(1));
        std::shared_ptr<int> p_ni;
        tnv.intVec().push_back(p_ni);
        tnv.intVec().push_back(std::make_shared<int>(3));

        tnv.stringVec().push_back(std::make_shared<std::string>("whatever"));
        std::shared_ptr<std::string> p_ns;
        tnv.stringVec().push_back(p_ns);
        tnv.stringVec().push_back(std::make_shared<std::string>("anyhow"));


        std::shared_ptr<TestPerson> p_p = std::make_shared<TestPerson>();
        p_p->name() = "N";
        p_p->age() = 10;
        tnv.objVec().push_back(p_p);
        std::shared_ptr<TestPerson> p_np;
        tnv.objVec().push_back(p_np);

        cout << "Round 1 serialize: " << tnv << endl;
        ostringstream out;
        out << tnv;
        istringstream in(out.str());
        TestNEVecs copy;
        in >> copy;
        cout << "Round 1 deserialize: " << copy << endl;
        istringstream in1(out.str());
        in1 >> copy;
        cout << "Round 1.1 deserialize: " << copy << endl;


    } catch(std::runtime_error & e) {
        cerr << "FAILED to parse:" << e.what() << endl;
    }
    return 0;
}
