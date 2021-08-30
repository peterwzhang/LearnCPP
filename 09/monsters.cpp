#include <iostream>

enum class MonsterType{
    ogre,
    dragon,
    orc,
    giantSpider,
    slime
};

struct Monster{
    MonsterType type {};
    std::string name {};
    int health {};
};

std::string getType(MonsterType m){
    switch (m) {
    case MonsterType::ogre:
        return "ogre";
    case MonsterType::dragon:
        return "dragon";
    case MonsterType::orc:
        return "orc";
    case MonsterType::giantSpider:
        return "giant spider";
    case MonsterType::slime:
        return "slime";
    default:
        return "unknown";
    }
}

void printMonster(Monster m){
    std::cout << "This " << getType(m.type) <<" is named " << m.name << " and has "<< m.health <<" health.\n";
}

int main(){
    Monster ogre {MonsterType::ogre, "Torg", 145};
    printMonster(ogre);
    Monster slime {MonsterType::slime, "Blurp", 23};
    printMonster(slime);
}