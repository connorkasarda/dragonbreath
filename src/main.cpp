#include <iostream>
#include "entitymgr.h"

int main(int argc, char** argv)
{
    DragonBreath::EntityManager* e_mgr = new DragonBreath::EntityManager();
    std::cout << "Num alive: " << e_mgr->getNumEntityAlive() << std::endl;
    std::cout << "Max entities: " << MAX_ENTITIES << std::endl;
    std::cout << "Creating 5 entities..." << std::endl;
    for (Entity id = 0; id < 5; ++id)
    {
        e_mgr->createEntity();
    }
    std::cout << "Num entities: " << e_mgr->getNumEntityAlive() << std::endl;
    std::cout << "Deleting 5 entities..." << std::endl;
    for (Entity id = 0; id < 5; ++id)
    {
        e_mgr->destroyEntity(id);
    }
    std::cout << "Num entities: " << e_mgr->getNumEntityAlive() << std::endl;
    delete e_mgr;
    return 0;
}