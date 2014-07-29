#include "ex0/gamerrel.hpp"

#include <cmath>
#include <fstream>

using namespace std;
using namespace test::gamer;

int main(int argc, char* argv[]) {
    std::string path;
    if(argc > 1) {
        path = argv[1];
    } else {
        cout << "FAILED: no path !!!" << endl;
        return 1;
    }
    fstream fin(path + "ex0.json");
    if(!fin) {
        cout << "FAILED: bad file path:" << (path + "ex1.json") << endl;
        return 1;
    }
    try {
        GamerRel root;
        fin >> root;
        cout << "Deserialized root object: " << root << endl;

        ostringstream out;
        out << root;
        istringstream in(out.str());

        GamerRel r;
        in >> r;
        //we know that we serialized and reparsed the object. Let's see how we are
        if(r.description() != "This \"is\" a \n string") {
            cout << "FAILED: description" << endl;
        }
        if(r.enemyIds().size() != 3) {
            cout << "FAILED: enemyids : size" << endl;
        } else {
            if(r.enemyIds().at(0) != 7 || r.enemyIds().at(1) != 8 || r.enemyIds().at(2) != 9) {
                cout << "FAILED: enemyids : values" << endl;
            }
        }
        if(r.enemyCoords().size() != 9) {
            cout << "FAILED: enemycoords : size" << endl;
        } else {
            //values
            for(int i = 0; i < 9; ++i) {
                double d = r.enemyCoords()[i];
                if(abs(d - i * 1.1) > 0.000001) {
                    cout << "FAILED: enemycoords : element " << i << endl;
                }
            }
        }
        if(r.gamer().age() != 28) {
            cout << "FAILED: gamer.age" << endl;
        }
        if(r.gamer().name() != "FloM") {
            cout << "FAILED: gamer.name" << endl;
        }
        if(r.gamer().score().coins() != 12345) {
            cout << "FAILED: gamer.score.coins" << endl;
        }
        if(r.gamer().score().mana() != 123) {
            cout << "FAILED: gamer.score.mana" << endl;
        }
        if(r.gamer().weapon().get()) {
            cout << "FAILED: gamer.weapon not null ?!?" << endl;
        }
        cout << "End test" << endl;

    } catch(std::runtime_error & e) {
        cerr << "FAILED to parse:" << e.what() << endl;
    }
    return 0;
}
