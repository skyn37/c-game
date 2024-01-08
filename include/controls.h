// controls.h
#ifndef CONTROLS_H
#define CONTROLS_H

#include "raylib.h"
#include "game.h"
#include <stddef.h>


void ControlsUpdatePositions(Player* Player, GridData* mapData, Enemy enemyArr[], size_t len );
#endif // CONTROLS_H
