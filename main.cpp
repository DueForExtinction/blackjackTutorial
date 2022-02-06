#include <iostream>
using namespace std;

void BuildTutorialMenu() { // Add options if needed.
    cout << "Play (p)" << endl;
    cout << "Quite (q)" << endl;
    cout << "Tutorial (?)" << endl;
}

void aboutTheGame(){
    char userOption = ' ';
    system("CLS");
    while (userOption == ' '){
        cout << "BlackJack is a card game where the objective is to land on 21 (or close enough) without going over ('busting')." << endl;
        cout << "In the first round you are delt two cards." << endl;
        cout << "It is possible in the first round to hit 21 and immediatly win the round." << endl;
        cout << "The value of cards is as follows:" << endl;
        cout << "All number cards (pips) are worth their respective number. A 9 is worth 9 'points', a 10 is worth 10." << endl;
        cout << "All face cards (Royalties) are worth 10 'points', king, queens, jacks." << endl;
        cout << "Aces have two values depending on context. They are either worth eleven, or one point. Whichever is more benifical." << endl;
        cout << endl << "press anything to continue." << endl;
        cin >> userOption;
    }
}

int main() {
    char userOption =' ';
    // Variables that I think will be useful.
    bool gameOver = true;
    int cardTally = 50;
    int runningTotal = 0;

    while ((userOption != 'p') && (userOption != 'q')){
        system("CLS");
        cout << "Welcome to the BlackJack Tutorial. Please select an option from the menu: "<< endl;
        BuildTutorialMenu();
        cin >> userOption;
        if (userOption == '?') {
            aboutTheGame();
        }
        else if(userOption == 'p'){
            gameOver = false;
        }
    }

    while(gameOver == false){

    }


    return 0;
}
