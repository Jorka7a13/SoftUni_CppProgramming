#include "results_calculations.h"
#include <iostream>
#include <set>
using namespace std;

namespace results_calculations
{
	double remainResultsInPercent(vector<Voter> &voters)
	{
		int remainVotes = 0;

		for (auto const& voter : voters) {
			if (voter.getVote() == REMAIN)
			{
				remainVotes++;
			} 
		}

		if (remainVotes != 0)
		{
			return (double)(remainVotes * 100) / voters.size();
		}
		else
		{
			return 0;
		}
	}

	double leaveResultsInPercent(vector<Voter> &voters)
	{
		int leaveVotes = 0;

		for (auto const& voter : voters) {
			if (voter.getVote() == LEAVE)
			{
				leaveVotes++;
			}
		}

		if (leaveVotes != 0)
		{
			return (double)(leaveVotes * 100) / voters.size();
		}
		else
		{
			return 0;
		}
	}

	int remainResultsInNumbers(vector<Voter> &voters)
	{
		int remainVotes = 0;

		for (auto const& voter : voters) {
			if (voter.getVote() == REMAIN)
			{
				remainVotes++;
			}
		}

		return remainVotes;
	}

	int leaveResultsInNumbers(vector<Voter> &voters)
	{
		int leaveVotes = 0;

		for (auto const& voter : voters) {
			if (voter.getVote() == LEAVE)
			{
				leaveVotes++;
			}
		}

		return leaveVotes;
	}

	map<Vote, int> resultsBasedOnAge(unsigned short age, vector<Voter> &voters)
	{
		map<Vote, int> result;
		int remainVotes = 0;
		int leaveVotes = 0;

		for (auto const& voter : voters) {
			if (voter.getAge() == age)
			{
				if (voter.getVote() == REMAIN)
				{
					remainVotes++;
				}
				else
				{ 
					leaveVotes++;
				}
			}
		}

		result.insert(std::pair<Vote, int>(REMAIN, remainVotes));
		result.insert(std::pair<Vote, int>(LEAVE, leaveVotes));

		return result;
	}

	map<Vote, int> resultsBasedOnName(string name, vector<Voter> &voters)
	{
		map<Vote, int> result;
		int remainVotes = 0;
		int leaveVotes = 0;

		for (auto const& voter : voters) {
			if (voter.getName() == name)
			{
				if (voter.getVote() == REMAIN)
				{
					remainVotes++;
				}
				else
				{
					leaveVotes++;
				}
			}
		}

		result.insert(std::pair<Vote, int>(REMAIN, remainVotes));
		result.insert(std::pair<Vote, int>(LEAVE, leaveVotes));

		return result;
	}

	map<Vote, int> resultsBasedOnEthnos(string ethnos, vector<Voter> &voters)
	{
		map<Vote, int> result;
		int remainVotes = 0;
		int leaveVotes = 0;

		for (auto const& voter : voters) {
			if (voter.getEthnos() == ethnos)
			{
				if (voter.getVote() == REMAIN)
				{
					remainVotes++;
				}
				else
				{
					leaveVotes++;
				}
			}
		}

		result.insert(std::pair<Vote, int>(REMAIN, remainVotes));
		result.insert(std::pair<Vote, int>(LEAVE, leaveVotes));

		return result;
	}

	map<Vote, int> resultsBasedOnCity(string city, vector<Voter> &voters)
	{
		map<Vote, int> result;
		int remainVotes = 0;
		int leaveVotes = 0;

		for (auto const& voter : voters) {
			if (voter.getCity() == city)
			{
				if (voter.getVote() == REMAIN)
				{
					remainVotes++;
				}
				else
				{
					leaveVotes++;
				}
			}
		}

		result.insert(std::pair<Vote, int>(REMAIN, remainVotes));
		result.insert(std::pair<Vote, int>(LEAVE, leaveVotes));

		return result;
	}
}