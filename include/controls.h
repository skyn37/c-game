// controls.h
#ifndef CONTROLS_H
#define CONTROLS_H

#include "raylib.h"
#include "game.h"
#include <stddef.h>


void ControlsUpdatePositions(Vector2* Player, GridData* mapData, Enemy enemyArr[], size_t len );
void EnemySearchTarget(Enemy enemy);
void UpdateEnemyPosition(Enemy *enemy, Vector2 position, GridData* mapData);
#endif // CONTROLS_H
