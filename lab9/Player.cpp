//Player.cpp, George Paul Robert, 117928226
#include "Player.h"

//constructor, sets the names of players nad initialises class members
Player::Player(std::string _name){
    name = _name;
    cash = 1000;
    numCards = 0;
    cards = nullptr;
}

//getter function for name
std::string Player::GetName() const{
    return name;
}

void Player::DrawCards(int _numCards){
    //if player has cards in hand, delete cards
    if(cards != nullptr){
        delete[] cards;
        cards = nullptr;
    }

    numCards = _numCards;
    cards = new int[numCards]; //dynamically allocated integer array
    for (int i = 0; i < numCards; i++){
        cards[i] = (rand() % 10) + 1; //randomly assigned number from 1-10 since there is a + 1, otherwise wouldve been 0-9
    }
}

int Player::SumCards() const{
    int runningTotal = 0;
    for (int i = 0; i < numCards; i++){
        runningTotal += cards[i];
    }
    return runningTotal;
}


void Player::StealCards(Player &player){
    //if not stealing from yourself
    if(this != &player){
        delete[] this->cards; //clear cards in hand
        numCards = player.numCards; //copies number of cards of the player whos cards are stolen
        cards = new int[numCards]; //new allocation for the stolen cards
        for (int i = 0; i < numCards; i++){
            cards[i] = player.cards[i]; //copies cards
        }
        delete[] player.cards; //delete the cards of the players whose cards were stolen
        player.cards = nullptr;
    }
}

bool Player::AddCash(int amount){
    bool retval = false;

        cash = cash + amount;
        if(cash > 0){
        retval = true;
        }
    return retval;
}

void Player::Report() const{

    std::cout << this->name << " has " << this->cash << " left over." << std::endl;
}

//destructor
Player::~Player(){
    delete[] cards;
    // cards = nullptr;
}