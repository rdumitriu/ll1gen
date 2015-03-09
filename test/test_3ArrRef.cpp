#include "testnevecs.hpp"

using namespace std;
using namespace test;

int main(int argc, char* argv[]) {
    TestNEVecs tnv;
    try {
        std::vector<std::shared_ptr<bool> > bools;
        bools.push_back(std::make_shared<bool>(true));
        std::shared_ptr<bool> p_nb;
        bools.push_back(p_nb);
        bools.push_back(std::make_shared<bool>(false));
        tnv.setBoolVec(bools);

        std::vector<std::shared_ptr<int> > ints;
        ints.push_back(std::make_shared<int>(1));
        std::shared_ptr<int> p_ni;
        ints.push_back(p_ni);
        ints.push_back(std::make_shared<int>(3));
        tnv.setIntVec(ints);

        std::vector<std::shared_ptr<std::string> > strings;
        strings.push_back(std::make_shared<std::string>("whatever"));
        std::shared_ptr<std::string> p_ns;
        strings.push_back(p_ns);
        strings.push_back(std::make_shared<std::string>("anyhow"));
        tnv.setStringVec(strings);


        std::vector<std::shared_ptr<TestPerson> > persons;
        std::shared_ptr<TestPerson> p_p = std::make_shared<TestPerson>();
        p_p->setName("N");
        p_p->setAge(10);
        persons.push_back(p_p);
        std::shared_ptr<TestPerson> p_np;
        persons.push_back(p_np);
        tnv.setObjVec(persons);

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
