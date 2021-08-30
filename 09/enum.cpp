#include <iostream>

enum MonsterType{
    monster_orc,
    monster_goblin,
    monster_troll,
    monster_ogre,
    monster_skeleton
};

int main(){
    auto race {MonsterType::monster_troll};
    return 0;
}