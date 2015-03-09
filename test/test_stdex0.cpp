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
        cout << "FAILED: bad file path:" << (path + "ex0.json") << endl;
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
        if(r.getDescription() != "This \"is\" a \n string") {
            cout << "FAILED: description" << endl;
        }
        if(r.getEnemyIds().size() != 3) {
            cout << "FAILED: enemyids : size" << endl;
        } else {
            if(r.getEnemyIds().at(0) != 7 || r.getEnemyIds().at(1) != 8 || r.getEnemyIds().at(2) != 9) {
                cout << "FAILED: enemyids : values" << endl;
            }
        }
        if(r.getEnemyCoords().size() != 9) {
            cout << "FAILED: enemycoords : size" << endl;
        } else {
            //values
            for(int i = 0; i < 9; ++i) {
                double d = r.getEnemyCoords()[i];
                if(abs(d - i * 1.1) > 0.000001) {
                    cout << "FAILED: enemycoords : element " << i << endl;
                }
            }
        }
        if(r.getGamer().getAge() != 28) {
            cout << "FAILED: gamer.age" << endl;
        }
        if(r.getGamer().getName() != "FloM") {
            cout << "FAILED: gamer.name" << endl;
        }
        if(r.getGamer().getScore().getCoins() != 12345) {
            cout << "FAILED: gamer.score.coins" << endl;
        }
        if(r.getGamer().getScore().getMana() != 123) {
            cout << "FAILED: gamer.score.mana" << endl;
        }
        if(r.getGamer().getWeapon().get()) {
            cout << "FAILED: gamer.weapon not null ?!?" << endl;
        }
        cout << "End test" << endl;

    } catch(std::runtime_error & e) {
        cerr << "FAILED to parse:" << e.what() << endl;
    }
    return 0;
}
