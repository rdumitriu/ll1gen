#include "_template.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    BeanTest b("abc", 1.0, 2);
    cout << "Round 1" << b << endl;

    try {
        std::string content = " {\"s\":\"dc\\u000F\\nba\",\"d\":2.0\n ,\"ui\":1}";
        std::istringstream ss(content);
        ss >> b;

        cout << "N: b.s() == >>" << b.s() << "<<" << endl;
        cout << "Round 2" << b << endl;
    } catch(std::runtime_error & e) {
        cerr << "FAILED to parse:" << e.what() << endl;
    }
    return 0;
}
