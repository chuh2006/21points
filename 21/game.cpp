#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <map>
#include "player.cpp"

class Game {
    public:
        Game() {
            std::cout << "WELCOME TO NENGJINSHOU 21 POINTS" << std::endl;
        }
        ~Game() {
            std::cout << "Game destructor" << std::endl;
        }
        void menu0() {
            std::cout << "1. single play" << std::endl;
            std::cout << "2. mutple play" << std::endl;
            std::cout << "3. Exit" << std::endl;
        }
        bool isStop=false;
        void play1(Player &player, Computer &computer){
            menu1(player, computer);
            for (int i=0; i<2; i++){
                player.getCard();
                computer.getCard();
            }
            while(!computer.isStop){
                computer.action();
            }
            std::cout << "the first card of computer is " << computer.cards[0] << std::endl;
            while(!player.isStop){
                std::cout << "\nplayer:" << std::endl;
                menu2(player);
            }
            std::string win = winner(player, computer);
            justDoIt(win, player, computer);
            gameover(player, computer);
        }
        void play2(Player &player1, Player &player2){
            menu1(player1, player2);
            for (int i=0; i<2; i++){
                player1.getCard();
                player2.getCard();
            }
            while(!player1.isStop){
                std::cout << "\nplayer1:" << std::endl;
                menu2(player1);
            }
            while(!player2.isStop){
                std::cout << "\nplayer2:" << std::endl;
                menu2(player2);
            }
            std::string win = winner(player1, player2);
            justDoIt(win, player1, player2);
            gameover(player1, player2);
        }
    private:
        std::string winner(Player &player1, Player &player2){
            std::cout << "_______________________________" << std::endl;
            std::cout << player1.name << " points=" << player1.points << std::endl;
            std::cout << player2.name << " points=" << player2.points << std::endl;
            if (player1.points > 21 && player2.points > 21) return "draw";
            if (player1.points > 21) return (player2.name + " win");
            if (player2.points > 21) return (player1.name + " win");
            if (player1.points > player2.points) return (player1.name + " win");
            if (player1.points < player2.points) return (player2.name + " win");
            if (player1.cardsCount > player2.cardsCount) return (player2.name + " win");
            if (player1.cardsCount < player2.cardsCount) return (player1.name + " win");
            return "draw";
        }
        void justDoIt(std::string win, Player &player1, Player &player2){
            player1.showCards();
            player2.showCards();
            std::cout << win << " in this turn" << std::endl;
            if (win == (player1.name + " win")) {
                player1.money += player1.moneyout;
                player1.money += player2.moneyout;
                player1.winCount++;
            }
            if (win == (player2.name + " win")) {
                player2.money += player1.moneyout;
                player2.money += player2.moneyout;
                player2.winCount++;
            }
            if (win == "draw") {
                player1.money += player1.moneyout;
                player2.money += player2.moneyout;
            }
            player1.moneyout = 0;
            player2.moneyout = 0;
            player1.points = 0;
            player2.points = 0;
            player1.cardsCount = 0;
            player2.cardsCount = 0;
            player1.isStop = false;
            player2.isStop = false;
            player1.cards.clear();
            player2.cards.clear();
        }
        void gameover(Player &player1, Player &player2){
            std::cout << player1.name << "money=" << player1.money << std::endl;
            std::cout << player2.name << "money=" << player2.money << std::endl;
            if (player1.money <= 0 || player2.money <= 0) {
                std::cout << "------one or more players are bankrupt------" << std::endl;
                isStop = true;
            }
        }
        void menu1(Player &player1, Player &player2) {
            std::cout << "put money=";
            int moneyout;
            std::cin >> moneyout;
            player1.moneyout = moneyout;
            player2.moneyout = moneyout;
            player1.money -= moneyout;
            player2.money -= moneyout;
        }
        void menu2(Player &player){
            std::cout << "\npoints is " << player.points << std::endl;
            std::cout << "you have " << player.cardsCount << " cards" << std::endl;
            std::cout << "1. get card" << std::endl;
            std::cout << "2. double" << std::endl;
            std::cout << "3. stop" << std::endl;
            int choice;
            std::cin >> choice;
            player.action(choice);
        }
    public:
        void menu3(Player &player1, Player &player2){
            std::cout << player1.name << " money=" << player1.money << "\t" + player1.name + " win " << player1.winCount << " times" << std::endl;
            std::cout << player2.name << " money=" << player2.money << "\t" + player2.name + " win " << player2.winCount << " times" << std::endl;
            std::cin.get();
            if(player1.money > player2.money) std::cout << player1.name << " win" << std::endl;
            if(player1.money < player2.money) std::cout << player2.name << " win" << std::endl;
        }
};