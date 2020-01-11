#pragma once

#include "ISE.h"
#include "fstream"

int winWidth = 1280;
int winHeight = 768;
bool gameEnd = false;
bool enableMenu = false;

void updateInput(ISE &engine, bool &run);