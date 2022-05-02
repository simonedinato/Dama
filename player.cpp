#include "player.hpp"

enum piece {x,o, X, O, e};


Player::Player(int player_nr){
    if(player_nr != 0 && player_nr != 1){
        throw player_exception{player_exception::index_out_of_bounds, "player_nr must be 0 or 1"};
    }
    this->player_nr = player_nr;
    pimpl = new Impl;
    pimpl->next = nullptr;
    pimpl->prev = nullptr;

    pimpl->board[0][0] = e;
    pimpl->board[0][1] = x;
    pimpl->board[0][2] = e;
    pimpl->board[0][3] = x;
    pimpl->board[0][4] = e;
    pimpl->board[0][5] = x;
    pimpl->board[0][6] = e;
    pimpl->board[0][7] = x;

    pimpl->board[1][0] = x;
    pimpl->board[1][1] = e;
    pimpl->board[1][2] = x;
    pimpl->board[1][3] = e;
    pimpl->board[1][4] = x;
    pimpl->board[1][5] = e;
    pimpl->board[1][6] = x;
    pimpl->board[1][7] = e;

    pimpl->board[2][0] = e;
    pimpl->board[2][1] = x;
    pimpl->board[2][2] = e;
    pimpl->board[2][3] = x;
    pimpl->board[2][4] = e;
    pimpl->board[2][5] = x;
    pimpl->board[2][6] = e;
    pimpl->board[2][7] = x;

    pimpl->board[3][0] = e;
    pimpl->board[3][1] = e;
    pimpl->board[3][2] = e;
    pimpl->board[3][3] = e;
    pimpl->board[3][4] = e;
    pimpl->board[3][5] = e;
    pimpl->board[3][6] = e;
    pimpl->board[3][7] = e;

    pimpl->board[4][0] = e;
    pimpl->board[4][1] = e;
    pimpl->board[4][2] = e;
    pimpl->board[4][3] = e;
    pimpl->board[4][4] = e;
    pimpl->board[4][5] = e;
    pimpl->board[4][6] = e;
    pimpl->board[4][7] = e;

    pimpl->board[5][0] = o;
    pimpl->board[5][1] = e;
    pimpl->board[5][2] = o;
    pimpl->board[5][3] = e;
    pimpl->board[5][4] = o;
    pimpl->board[5][5] = e;
    pimpl->board[5][6] = o;
    pimpl->board[5][7] = e;

    pimpl->board[6][0] = e;
    pimpl->board[6][1] = o;
    pimpl->board[6][2] = e;
    pimpl->board[6][3] = o;
    pimpl->board[6][4] = e;
    pimpl->board[6][5] = o;
    pimpl->board[6][6] = e;
    pimpl->board[6][7] = o;

    pimpl->board[7][0] = o;
    pimpl->board[7][1] = e;
    pimpl->board[7][2] = o;
    pimpl->board[7][3] = e;
    pimpl->board[7][4] = o;
    pimpl->board[7][5] = e;
    pimpl->board[7][6] = o;
    pimpl->board[7][7] = e;

}

Player::~Player(){
    delete pimpl;
}

Player::Player(const Player& copy){
    delete this->pimpl;
    this->pimpl = new Impl;
    this->player_nr = copy.player_nr;
    Impl* copy_pimpl = copy.pimpl;
    while(copy_pimpl != nullptr){
        this->pimpl->next = new Impl;
        this->pimpl->next->prev = copy_pimpl;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                this->pimpl->board[i][j] = copy_pimpl->board[i][j];
            }
        }
        this->pimpl = this->pimpl->next;
        copy_pimpl = copy_pimpl->next;
    }
}

Player& Player::operator=(const Player& copy){
    if(this != &copy){
        delete this->pimpl;
        this->pimpl = new Impl;
        this->player_nr = copy.player_nr;
        Impl* copy_pimpl = copy.pimpl;
        while(copy_pimpl != nullptr){
            this->pimpl->next = new Impl;
            this->pimpl->next->prev = copy_pimpl;
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    this->pimpl->board[i][j] = copy_pimpl->board[i][j];
                }
            }
            this->pimpl = this->pimpl->next;
            copy_pimpl = copy_pimpl->next;
        }
    }
    return *this;
}



int main(){
    Player p1{0};
    Player p2{p1};

    // ciao mamma
    
    return 0;
}


