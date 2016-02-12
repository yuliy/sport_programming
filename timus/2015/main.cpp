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
using namespace std;

struct TFriend {
    int MaxRent = 0;
    int Adv = 0;
};

struct TFlat {
    int RoomCount = 0;
    int Rent = 0;
    int Adv = 0;
};

class TApplication {
public:
    void Run() {
        Init();

        int bestFlat = -1;
        int bestFriend = -1;
        int bestAdv = -1;

        for (int i = 1; i <= M; ++i) {
            const TFlat& flat = Flats[i-1];

            const int adv = ((flat.RoomCount == 1 ) ? AdvAlone1Room : AdvAlone2Room) + flat.Adv;
            if ((adv > bestAdv) && (JMaxRent >= flat.Rent)) {
                bestFlat = i;
                bestFriend = -1;
                bestAdv = adv;
                /*
                cout
                    << "bestFlat=" << i << endl
                    << "bestFriend=" << bestFriend << endl
                    << "bestAdv=" << bestAdv << endl
                    << "flat.Rent=" << flat.Rent << endl
                    << endl;
                */
            }

            if (flat.RoomCount == 2) {
                for (int j = 1; j <= N; ++j) {
                    const TFriend& fr = Friends[j-1];
                    const int adv = flat.Adv + fr.Adv;
                    if (
                        (adv > bestAdv)
                        && (JMaxRent >= (flat.Rent / 2.0))
                        && (fr.MaxRent >= (flat.Rent / 2.0))
                    ) {
                        bestFlat = i;
                        bestFriend = j;
                        bestAdv = adv;
                        /*
                        cout
                            << "bestFlat=" << i << endl
                            << "bestFriend=" << bestFriend << endl
                            << "bestAdv=" << bestAdv << endl
                            << "flat.Rent=" << flat.Rent << endl
                            << endl;
                        */
                    }
                }
            }
        }

        if (bestFlat == -1) {
            printf("Forget about apartments. Live in the dormitory.\n");
            return;
        }

        if (bestFriend == -1) {
            printf("You should rent the apartment #%d alone.\n", bestFlat);
            return;
        }

        printf("You should rent the apartment #%d with the friend #%d.\n", bestFlat, bestFriend);
    }
private:
    int JMaxRent = 0;
    int AdvAlone1Room = 0;
    int AdvAlone2Room = 0;
    int N = 0;
    int M = 0;
    vector<TFriend> Friends;
    vector<TFlat> Flats;
private:
    void Init() {
        scanf("%d %d %d", &JMaxRent, &AdvAlone1Room, &AdvAlone2Room);

        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            TFriend f;
            scanf("%d %d", &f.MaxRent, &f.Adv);
            Friends.push_back(f);
        }

        scanf("%d", &M);
        for (int i = 0; i < M; ++i) {
            TFlat f;
            scanf("%d %d %d", &f.RoomCount, &f.Rent, &f.Adv);
            Flats.push_back(f);
        }
    }
};

int main() {
    TApplication app;
    app.Run();
    return 0;
}
