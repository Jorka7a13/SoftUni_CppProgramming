#ifndef UTILITY_H
#define UTILITY_H
#pragma once

#include "character.h"
#include "environment.h"

namespace utility
{
	double calculateMaxJumpHeight(const Character &character, const Environment &environment);
	double calculateJumpTime(const Character &character, const Environment &environment);
	bool canCharacterJump(const Character &character, const Environment &environment, double height);
}

#endif