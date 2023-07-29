#include <iostream>
#include "entitymgr.h"

int main(int argc, char** argv)
{
    DragonBreath::EntityManager* e_mgr = new DragonBreath::EntityManager();
    std::cout << e_mgr->getNumEntityAlive() << std::endl;
    std::cout << DragonBreath::MAX_ENTITIES << std::endl;
    delete e_mgr;
    return 0;
}