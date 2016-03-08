#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
#include <exception>
using namespace std;

static bool Has(const vector<string>& cont, const string& value) {
    return find(cont.begin(), cont.end(), value) != cont.end();
}

class TApplication {
public:
    void Run() {
        Init();

        int N;
        cin >> N;

        int max = 0;
        int res = 0;

        for (int i = 0; i < N; ++i) {
            int K;
            cin >> K;

            int wins = 0;
            for (int j = 0; j < K; ++j) {
                string team, skip, value;
                cin >> team >> skip >> value;
                if (Correct(team, value))
                    ++wins;
            }

            if (wins > max) {
                res = 1;
                max = wins;
            } else if (wins == max) {
                ++res;
            }
        }

        cout << (5 * res) << endl;
    }
private:
    vector<string> Golden;
    vector<string> Silver;
    vector<string> Bronze;
private:
    void Init() {
        Init(Golden);
        Init(Silver);
        Init(Bronze);
    }

    void Init(vector<string>& cont) {
        cont.resize(4);
        for (int i = 0; i < 4; ++i)
            cin >> cont[i];
    }

    bool Correct(const string& team, const string& value) {
        if (value == "gold")
            return Has(Golden, team);
        if (value == "silver")
            return Has(Silver, team);
        if (value == "bronze")
            return Has(Bronze, team);
        throw "Logical error! :(";
    }
};

int main() {
    TApplication app;
    app.Run();
    return 0;
}
