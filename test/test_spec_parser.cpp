#include <iostream>
#include <fstream>

#include "spec_parser.hpp"

using namespace std;
using namespace ll1gen;

int main(int argc, char* argv[]) {
    if(argc == 1) {
        cout << "FAILED : path needed." << endl;
        return -1;
    }
    Specification spec;

    ifstream is(argv[1]);
    if(!is.is_open()) {
        cout << "FAILED : good path needed." << endl;
        return -1;
    }

    SpecificationParser parser(spec);
    if(!parser.parse(is)) {
        parser.printErrors();
    }

    cout << "PARSED:" << endl;
    for(auto & s : spec.getNamespaces()) {
        cout << "namespace : " << s << "  ";
    }
    cout << endl;
    for(auto & c : spec.getBeans()) {
        cout << "Bean:" << c.getName() << endl;
        for(auto & f : c.getFields()) {
            cout << "Field:" << f.name << "| type>>" << f.type << "<< | Flags:" << f.flags << endl;
        }
        cout << endl;
    }


    return 0;
}
