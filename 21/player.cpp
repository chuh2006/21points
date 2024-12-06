#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <map>

class Player {
    public:
        Player() {
            std::cout << "Player constructor" << std::endl;
            std::cout << "Enter your money(unless it is computer): ";
            std::cin >> money;
        }
        ~Player() {
            std::cout << name + " destructor" << std::endl;
        }
        std::string name;
        int winCount=0;
        int money;
        std::vector<std::string> cards;
        int moneyout;
        int points=0;
        int cardsCount=0;
        bool isStop=false;
        void action(int choice){
            switch (choice){
                case 1:
                    getCard();
                    break;
                case 2:
                    double1();
                    break;
                case 3:
                    stop();
                    break;
                default:
                    std::cout << "Invalid choice" << std::endl;
            }
        }
        void getCard(){
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, 13);
            int cardIndex = dis(gen);
            std::string card = cardValue.at(cardIndex);
            cards.push_back(card);
            if (cardsCount <= 4) points += cardValue1.at(card);
            else points += cardValue2.at(card);
            cardsCount++;
            isBust();
        }
        void showCards(){
            std::cout << name << "'s " << "cards: ";
            for (std::string card : cards) {
                std::cout << card << " ";
            }
            std::cout << std::endl;
        }
    protected:
        std::map<int, std::string> cardValue = {
            {1, "A"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"}, {7, "7"}, {8, "8"}, {9, "9"}, {10, "10"}, {11, "J"}, {12, "Q"}, {13, "K"}
        };
        std::map<std::string, int> cardValue1 = {
            {"A", 11}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 10}, {"Q", 10}, {"K", 10}
        };
        std::map<std::string, int> cardValue2 = {
            {"A", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 10}, {"Q", 10}, {"K", 10}
        };
        void double1(){
            moneyout *= 2;
            getCard();
            stop();
        }
        void stop(){
            isStop = true;
        }
        void isBust(){
            if (points > 21) {
                std::cout << "Bust" << std::endl;
                isStop = true;
            } else {
                isStop = false;
            }
        }
};

class Computer : public Player {
    public:
        Computer() {
            std::cout << "Computer constructor" << std::endl;
        }
        void action(){
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, 21);
            int choice = dis(gen);
            if (choice > points) getCard();
            else stop();
        }
    protected:
        void isBust(){
            if (points > 21) {
                isStop = true;
            } else {
                isStop = false;
            }
        }
};