/**
 * @file dragonbreath.cpp
 * @brief The dragonbreath main program
 *
 * Runs dragonbreath ECS engine code.
 *
 * @author Connor Kasarda
 * @date 2024-01-25
 */

#include <iostream>
#include "DragonBreath.h"

dragonbreath::Commander cmdr;

int main(int argc, char** argv)
{
    if (argc != 1)
    {
        std::cerr << "usage: " << argv[0] << std::endl;
        return 1;
    }

    // Wake up the entity, component, and system managers
    cmdr.init();

    // Make sure to register applicable components and systems
    cmdr.registerComponent<dragonbreath::Transform>();
    cmdr.registerComponent<dragonbreath::RigidBody>();
    cmdr.registerSystem<dragonbreath::Physics>();

    // Set system signature bits for applicable components
    dragonbreath::Signature physicsSignature {};
    physicsSignature.set(
        cmdr.getComponentType<dragonbreath::Transform>());
    physicsSignature.set(
        cmdr.getComponentType<dragonbreath::RigidBody>());
    cmdr.setSystemSignature<dragonbreath::Physics>(physicsSignature);

    // TODO

    return 0;
}
