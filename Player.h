//
// Created by XPS 8700 on 5/8/2022.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>



class Player{

    std::string name;
public:
    Player(std::string name){
        this->name = name;
    }

    void setname(std::string name){

        this->name = name;
    }
    std::string getname(){
        return name;
    }
};

#endif
