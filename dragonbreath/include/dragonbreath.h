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
#include "debug.h"
#include "entity.h"
#include "entity_manager.h"
#include "signature.h"
#include "component.h"
#include "component_array.h"
#include "component_manager.h"
#include "system.h"
#include "system_manager.h"
#include "commander.h"

// Math
#include "vector3.h"

// Components
#include "transform.h"
#include "rigidbody.h"

// Systems
#include "physics.h"

#endif // DRAGONBREATH_H
