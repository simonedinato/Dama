#include "player.hpp"
#define SIZE 8


struct Player::Impl{
    Player::piece** board;
    Impl* next;
    int player_nr;
    int board_count;
};

Player::piece** newboard(){
    Player::piece** board = new Player::piece*[SIZE];
    for(int i = 0; i < SIZE; i++)
        board[i] = new Player::piece[SIZE];

    return board;
}

Player::Player(int player_nr){
    std::cout<< "constructor called"<<std::endl;
    if(player_nr != 1 && player_nr != 0){
        throw player_exception{player_exception::index_out_of_bounds, "player_nr must be either 0 or 1"};
    }
    pimpl = new Impl{ nullptr, nullptr, player_nr, 0};
    pimpl->board = new Player::piece*[SIZE];
    for(int i = 0; i < SIZE; i++){
        pimpl->board[i] = new Player::piece[SIZE];
    }
    std::cout<< "constructor over"<<std::endl;
}

Player::~Player(){
    std::cout<< "destructor called"<<std::endl;
    while(pimpl != nullptr){
        Impl* temp = pimpl;
        pimpl = pimpl->next;
        delete temp;
    }
    delete pimpl;
    std::cout<< "destructor over"<<std::endl;
}

Player::Player(const Player& copy){
    std::cout<< "copy called"<<std::endl;
    pimpl = new Impl;
    Impl* temp = pimpl;
    Impl* copytemp = copy.pimpl;

    while(copytemp != nullptr){
        temp->player_nr = copytemp->player_nr;;
        temp->board_count = copytemp->board_count;
        temp->board = newboard();
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                temp->board[i][j] = copytemp->board[i][j];
            }
        }
        temp = temp->next;
        if(copytemp->next != nullptr){
            temp = new Impl;
        }
        copytemp = copytemp->next;
    }
    std::cout<< "copy over"<<std::endl;
}

int main(){
    Player p1(0);
    Player p2(p1);
    
    return 0;
}


