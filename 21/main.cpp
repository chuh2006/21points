#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <map>
#include "game.cpp"

void play1(Game &game) {
    Player player;
    Computer computer;
    computer.money = player.money;
    player.name = "player";
    computer.name = "computer";
    while(!game.isStop){
        game.play1(player, computer);
    }
    game.menu3(player, computer);
}

void play2(Game &game) {
    std::cout << "player1:" << std::endl;
    Player player1;
    std::cout << "player2:" << std::endl;
    Player player2;
    player1.name = "player1";
    player2.name = "player2";
    while(!game.isStop){
        game.play2(player1, player2);
    }
    game.menu3(player1, player2);
}

int main() {
    Game game;
    while (true){
        game.menu0();
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                play1(game);
                break;
            case 2:
                play2(game);
                break;
            case 3:
                std::cin.get();
                return 0;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }
    std::cin.get();
    return 0;
}