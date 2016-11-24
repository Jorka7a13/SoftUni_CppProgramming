#ifndef RESULTS_CALCULATIONS_H
#define RESULTS_CALCULATIONS_H
#pragma once

#include "voter.h"
#include <vector>
#include <map>

namespace results_calculations
{
	double remainResultsInPercent(std::vector<Voter> &voters);
	double leaveResultsInPercent(std::vector<Voter> &voters);

	int remainResultsInNumbers(std::vector<Voter> &voters);
	int leaveResultsInNumbers(std::vector<Voter> &voters);

	std::map<Vote, int> resultsBasedOnAge(unsigned short age, std::vector<Voter> &voters);
	std::map<Vote, int> resultsBasedOnName(std::string name, std::vector<Voter> &voters);
	std::map<Vote, int> resultsBasedOnEthnos(std::string ethnos, std::vector<Voter> &voters);
	std::map<Vote, int> resultsBasedOnCity(std::string city, std::vector<Voter> &voters);
}

#endif