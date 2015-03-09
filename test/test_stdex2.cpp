#include "ex2/menuroot.hpp"

#include <fstream>

using namespace std;
using namespace test::menu;

int main(int argc, char* argv[]) {
    std::string path;
    if(argc > 1) {
        path = argv[1];
    } else {
        cout << "FAILED: no path !!!" << endl;
        return 1;
    }
    fstream fin(path + "ex2.json");
    if(!fin) {
        cout << "FAILED: bad file path:" << (path + "ex2.json") << endl;
        return 1;
    }
    try {
        MenuRoot root;
        fin >> root;
        cout << "Deserialized root object: " << root << endl;

        ostringstream out;
        out << root;
        istringstream in(out.str());

        MenuRoot r;
        in >> r;
        //we know that we serialized and reparsed the object. Let's see how we are
        if(r.getMenu().getHeader() != "SVG Viewer") {
            cout << "FAILED: header" << endl;
        }
        if(r.getMenu().getItems().size() != 22) {
            cout << "FAILED: items size" << endl;
        }
        if(r.getMenu().getItems()[0]->getId() != "Open") {
            cout << "FAILED: item zero id" << endl;
        }
        if(r.getMenu().getItems()[0]->getLabel() != "") {
            cout << "FAILED: item zero label" << endl;
        }
        if(r.getMenu().getItems()[1]->getId() != "OpenNew") {
            cout << "FAILED: item 1 id" << endl;
        }
        if(r.getMenu().getItems()[1]->getLabel() != "Open New") {
            cout << "FAILED: item 1 label" << endl;
        }
        if(r.getMenu().getItems()[2].get()) {
            cout << "FAILED: item 2 not null" << endl;
        }

        cout << "End test" << endl;

    } catch(std::runtime_error & e) {
        cerr << "FAILED to parse:" << e.what() << endl;
    }
    return 0;
}
