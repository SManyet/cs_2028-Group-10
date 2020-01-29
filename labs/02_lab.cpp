#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player {
    private:
        string name;
        int shotsTaken;
        int shotsMade;
        int passesAttempted;
        int passesMade;

    public:
        Player() {
            name = "name";
            shotsTaken = 0;
            shotsMade = 0;
            passesAttempted = 0;
            passesMade = 0;

        }

        Player(string n, int sT, int sM, int pA, int pM) {
            // name, shotsTaken, shotsMade, passesAttempted, passesMade = 
            //     n, sT, sM, pA, pM;
            name = n;
            shotsTaken = sT;
            shotsMade = sM;
            passesAttempted = pA;
            passesMade = pM;
        }
        bool passBall();
        int takeShot(int score);
        string getStats();
};


int main() {
    Player team[5];
    // for(int i = 0; i < 5; i++) {
    //     cout << "enter player name: ";
    //     string name;
    //     // cin >> name;
    //     cout << "enter player name: ";
    //     int 
    //     // cin >> name;
    srand((unsigned)time(0));

    bool logic = true;
    int possessionIndex = rand() % 5;
    int possessionsLeft;
    int userScore;
    int oppScore;
    while(logic) {
        if (possessionIndex != -1) {
            string play;
            cout << "do you want shoot, pass, see player stats, or see score?: ";
            cin >> play;
            if (play.compare("shoot") == 0) {
                cout << "shot value?: ";
                int val;
                cin >> val;
                int shot = team[possessionIndex].takeShot(val);
                if (shot > 0) {
                    userScore += shot;
                    possessionIndex = -1;
                    cout << "you made " << shot << " points"
                    break;
                } else if (0 == rand() % 2) {
                    cout << "rebound saved!";
                    break;
                } else {
                    possessionIndex = -1;
                    break;
                }
            } else if (play.compare("pass") == 0) {
                cout << "to whom? Enter # 0-4 except " << possessionIndex << ":";
                int player;
                cin >> player;
                if (player >= 0 && player <= 4 && player != possessionIndex && team[possessionIndex].passBall()) {
                    possessionIndex = player;
                    cout << "passed to player " << player;
                    break;
                } else {
                    cout << "missed pass, changing possession";
                    possessionIndex = -1;
                    break;
                }
            } else if (play.compare("see player stats") == 0) {
                cout << team[possessionIndex].getStats();
                break;
            } else if (play.compare("see score")) {
                cout << userScore << " - " << oppScore;
                break;
            } else {
                cout << "invalid input, try again";
                break
            }
        } else {

        }     
    }
}
