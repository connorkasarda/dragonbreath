/**
 * @file dragonbreath.h
 * @brief The dragonbreath code in one package
 *
 * This is the file that should be imported into your project. Provides an ECS
 * engine for your project.
 *
 * @author Connor Kasarda
 * @date 2024-01-25
 */

#ifndef DRAGONBREATH_H
#define DRAGONBREATH_H

// Engine
#include "Debug.h"
#include "Entity.h"
#include "EntityManager.h"
#include "Signature.h"
#include "Component.h"
#include "ComponentArray.h"
#include "ComponentManager.h"
#include "System.h"
#include "SystemManager.h"
#include "Commander.h"

// Math
#include "Vector3.h"
#include "Quaternion.h"

// Components
#include "Transform.h"
#include "RigidBody.h"

// Systems
#include "Physics.h"

#endif // DRAGONBREATH_H
