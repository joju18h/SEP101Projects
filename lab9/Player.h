//Player.h, George Paul Robert, 117928226
#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>

class Player{
    private:
        std::string name;
        int numCards;
        int cash;
        int *cards; //Points to the dynamically allocated array containg n number of cards, where n is based on user input
    public:
        Player(std::string);
        std::string GetName() const;
        void DrawCards(int);
        int SumCards() const;
        void StealCards(Player &player);
        bool AddCash(int);
        void Report() const;
        ~Player();
};

#endif //PLAYER_H_