#include "utility.h"

#define CONVERTION_COEFFICIENT 0.227 // Because we need the results in m/s, not in km/h.

namespace utility
{
	double calculateMaxJumpHeight(const Character &character, const Environment &environment)
	{
		return (character.getJumpSpeed() * character.getJumpSpeed()) / (2 * environment.getGravity()) * CONVERTION_COEFFICIENT;
	}

	double calculateJumpTime(const Character &character, const Environment &environment)
	{
		return ((character.getJumpSpeed() / environment.getGravity()) * 2) * CONVERTION_COEFFICIENT; // Multiplied by 2 because we assume the character falls down at the same speed.
	}

	bool canCharacterJump(const Character &character, const Environment &environment, double height)
	{
		if (calculateMaxJumpHeight(character, environment) >= height)
		{
			return true;
		} 
		else 
		{ 
			return false;
		}
	}
}