#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <array>
#include <bits/stdc++.h>
using namespace std;

// The next two functions are just so I had something to work with and will be replaced with whatever you come up with.
void BuildTutorialMenu() { // Add options if needed.
    cout << "Play (p)" << endl;
    cout << "Quite (q)" << endl;
    cout << "Tutorial (?)" << endl;
}
// This one too.
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

// This function adds all the cards to the game. I'm working with only the standard deck size of 52. I don't think that we will need more. Currently there are no aces.
void fillVectorOfCards(vector<string>& newCards){
    stringstream stream;
    string text;
    int pipDiamonds = 2;
    int pipClubs = 2;
    int pipHearts = 2;
    int pipSpades = 2;
    string faceCards[] {"King of diamonds", "Queen of diamonds", "Jack of diamonds", "King of hearts", "Queen of hearts", "Jack of hearts", "King of spades", "Queen of spades", "Jack of spades", "King of clubs", "Queen of clubs", "Jack of clubs"};
    int N = sizeof(faceCards) / sizeof (faceCards[0]);
    string AceCards [] {"Ace of diamonds", "Ace of hearts", "Ace of spades", "Ace of clubes"};
    int J = sizeof (AceCards)/sizeof (AceCards[0]);

    for(int i = 0; i < 39; ++i){
        if((i > -1) && (i <=8)){
           stream.str(" ");
           stream.clear();
           stream << pipDiamonds;
           stream >> text;
           newCards.push_back(text + " of diamonds");
           pipDiamonds += 1;
        }
        else if ((i >= 9) && (i <= 17)){
            stream.str(" ");
            stream.clear();
            stream << pipClubs;
            stream >> text;
            newCards.push_back(text + " of clubs");
            pipClubs += 1;
        }
        else if ((i >= 19) && (i <= 27)){
            stream.str(" ");
            stream.clear();
            stream << pipHearts;
            stream >> text;
            newCards.push_back(text + " of hearts");
            pipHearts += 1;
        }
        else if ((i >=29) && (i <=37)){
            stream.str(" ");
            stream.clear();
            stream << pipSpades;
            stream >> text;
            newCards.push_back(text + " of spades");
            pipSpades += 1;
        }
    }
    newCards.insert(newCards.end(), faceCards, faceCards + N);
    newCards.insert(newCards.end(), AceCards, AceCards + J);

}

int findCardValues(vector<string>& Cards, vector<int>& playerHand, vector<int>& dealerHand, int newPlayerTotal){
    int value;
    int handValue = 0;
    for(unsigned int i = 0; i < playerHand.size(); ++i){
        value = 0;
        value = Cards.at(playerHand.at(i)).find("2", 0);
        if(value != -1){
            handValue += 2;
            value = 0;
        }
        value = Cards.at(playerHand.at(i)).find("3", 0);
        if(value != -1){
            handValue += 3;
            value = 0;
        }
        value = Cards.at(playerHand.at(i)).find("4", 0);
        if(value != -1){
            handValue += 4;
            value = 0;
        }
        value = Cards.at(playerHand.at(i)).find("5", 0);
        if(value != -1){
            handValue += 5;
            value = 0;
        }
        value = Cards.at(playerHand.at(i)).find("6", 0);
        if(value != -1){
            handValue += 6;
            value = 0;
        }
        value = Cards.at(playerHand.at(i)).find("7", 0);
        if(value != -1){
            handValue += 7;
            value = 0;
        }
        value = Cards.at(playerHand.at(i)).find("8", 0);
        if(value != -1){
            handValue += 8;
            value = 0;
        }
        value = Cards.at(playerHand.at(i)).find("9", 0);
        if(value != -1){
            handValue += 9;
            value = 0;
        }
        value = Cards.at(playerHand.at(i)).find("10", 0);
        if(value != -1){
            handValue += 10;
            value = 0;
        }
        value = Cards.at(playerHand.at(i)).find("King", 0);
        if(value != -1){
            handValue += 10;
            value = 0;
        }
        value = Cards.at(playerHand.at(i)).find("Queen", 0);
        if(value != -1){
            handValue += 10;
            value = 0;
        }
        value = Cards.at(playerHand.at(i)).find("Jack", 0);
        if(value != -1){
            handValue += 10;
            value = 0;
        }
        value = Cards.at(playerHand.at(i)).find("Ace", 0);
        if(value != -1){
            handValue += 11;
            value = 0;
        }

    }
    return handValue;
}

int main() {
    char userOption =' ';
    // Variables that I think will be useful. It's not complete and theres currently no way to actually play the game as this currently is.
    bool gameOver = true;
    int playerTotal = 0;
    int dealerTotal = 0;
    vector <int> playerHand;
    vector <int> dealerHand;
    int randomCardNumber;
    stringstream stream;
    string text;
    vector <string> Cards;
    fillVectorOfCards(Cards);

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

    playerHand.clear();
    dealerHand.clear();
    srand(time(0));
    for (int i = 0; i < 2; ++i){
        randomCardNumber = rand()%52;
        playerHand.push_back(randomCardNumber);
    }
    randomCardNumber = 0;
    for (int i = 0; i < 2; ++i){
        randomCardNumber = rand()%52;
        dealerHand.push_back(randomCardNumber);
    }

    findCardValues(Cards, playerHand, dealerHand, playerTotal);

    // Some more structure is needed here but for the working model I don't think it will be that big of a deal.
    while(gameOver == false){
        cout << "Your hand is: ";
        for (unsigned int i = 0; i < playerHand.size(); ++i){
            cout << Cards.at(playerHand.at(i)) << " ";
        }
        cout << endl << "The face up dealer card is: ";
        for (unsigned int i = 0; i < 1; ++i){
            cout << Cards.at(dealerHand.at(i)) << endl;
        }
        // Hitting, staying, and splitting still need to be added.
        cout << endl << "What would you like to do?" << endl;
        cin >> userOption;
        if (userOption == 'q'){
            gameOver = true;
        }
    }


    return 0;
}
