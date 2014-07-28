#include "ex1/glossaryroot.hpp"

#include <fstream>

using namespace std;
using namespace test::glossary;

int main(int argc, char* argv[]) {
    std::string path;
    if(argc > 1) {
        path = argv[1];
    } else {
        cout << "FAILED: no path !!!" << endl;
        return 1;
    }
    fstream fin(path + "ex1.json");
    if(!fin) {
        cout << "FAILED: bad file path:" << (path + "ex1.json") << endl;
        return 1;
    }
    try {
        GlossaryRoot root;
        fin >> root;
        cout << "Deserialized root object: " << root << endl;

        ostringstream out;
        out << root;
        istringstream in(out.str());

        GlossaryRoot r;
        in >> r;
        //we know that we serialized and reparsed the object. Let's see how we are
        if(r.glossary().title() != "example glossary") {
            cout << "FAILED: glossary.title" << endl;
        }
        if(r.glossary().GlossDiv().title() != "S") {
            cout << "FAILED: glossary.title.GlossDiv.title" << endl;
        }
        if(r.glossary().GlossDiv().GlossList().GlossEntry().ID() != "SGML") {
            cout << "FAILED: glossary.title.GlossDiv.GlossList.GlossEntry.ID" << endl;
        }
        if(r.glossary().GlossDiv().GlossList().GlossEntry().SortAs() != "SGML") {
            cout << "FAILED: glossary.title.GlossDiv.GlossList.GlossEntry.SortAs" << endl;
        }
        if(r.glossary().GlossDiv().GlossList().GlossEntry().Acronym() != "SGML") {
            cout << "FAILED: glossary.title.GlossDiv.GlossList.GlossEntry.Acronym" << endl;
        }
        if(r.glossary().GlossDiv().GlossList().GlossEntry().Abbrev() != "ISO 8879:1986") {
            cout << "FAILED: glossary.title.GlossDiv.GlossList.GlossEntry.Abbrev" << endl;
        }
        if(r.glossary().GlossDiv().GlossList().GlossEntry().GlossTerm() != "Standard Generalized Markup Language") {
            cout << "FAILED: glossary.title.GlossDiv.GlossList.GlossEntry.GlossTerm" << endl;
        }
        if(r.glossary().GlossDiv().GlossList().GlossEntry().GlossSee() != "markup") {
            cout << "FAILED: glossary.title.GlossDiv.GlossList.GlossEntry.GlossTerm" << endl;
        }
        if(r.glossary().GlossDiv().GlossList().GlossEntry().GlossDef().para() != "A meta-markup language, used to create markup languages such as DocBook.") {
            cout << "FAILED: glossary.title.GlossDiv.GlossList.GlossEntry.GlossDef.para" << endl;
        }
        if(r.glossary().GlossDiv().GlossList().GlossEntry().GlossDef().GlossSeeAlso().at(0) != "GML") {
            cout << "FAILED: glossary.title.GlossDiv.GlossList.GlossEntry.GlossDef.seealso(0)" << endl;
        }
        if(r.glossary().GlossDiv().GlossList().GlossEntry().GlossDef().GlossSeeAlso().at(1) != "XML") {
            cout << "FAILED: glossary.title.GlossDiv.GlossList.GlossEntry.GlossDef.seealso(1)" << endl;
        }
        cout << "End test" << endl;

    } catch(std::runtime_error & e) {
        cerr << "FAILED to parse:" << e.what() << endl;
    }
    return 0;
}
