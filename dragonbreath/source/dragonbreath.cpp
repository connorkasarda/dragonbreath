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
#include "dragonbreath.h"

dragonbreath::engine::Commander cmdr;

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
    cmdr.registerComponent<dragonbreath::components::Transform>();
    cmdr.registerComponent<dragonbreath::components::RigidBody>();
    cmdr.registerSystem<dragonbreath::systems::Physics>();

    // Set system signature bits for applicable components
    dragonbreath::engine::Signature physicsSignature {};
    physicsSignature.set(
        cmdr.getComponentType<dragonbreath::components::Transform>());
    physicsSignature.set(
        cmdr.getComponentType<dragonbreath::components::RigidBody>());
    cmdr.setSystemSignature<dragonbreath::systems::Physics>(physicsSignature);

    return 0;
}
