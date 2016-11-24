#include "voter.h"
#include "results_calculations.h"
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

string VoteEnumNames[] = {"Remain", "Leave"};

void printResultsBasedOnName(vector<Voter> &voters, set<string> &names)
{
	string userSelectedName;

	cout << "Results based on name" << endl;
	cout << "Choose a name: ";
	for (auto name : names) {
		cout << name << " ";
	}
	cout << endl;

	cin.ignore(256, '\n');
	getline(cin, userSelectedName);
	map<Vote, int> nameResults = results_calculations::resultsBasedOnName(userSelectedName, voters);

	cout << endl;
	cout << "For name: " << userSelectedName << endl;
	for (auto const& result : nameResults) {
		cout << VoteEnumNames[result.first] << ": " << result.second << endl;
	}
	cout << endl;
}

void printResultsBasedOnAge(vector<Voter> &voters, set<int> &ages)
{
	unsigned short userSelectedAge;

	cout << "Results based on age" << endl;
	cout << "Choose an age: ";
	for (auto age : ages) {
		cout << age << " ";
	}
	cout << endl;

	cin >> userSelectedAge;
	map<Vote, int> ageResults = results_calculations::resultsBasedOnAge(userSelectedAge, voters);

	cout << endl;
	cout << "For age: " << userSelectedAge << endl;
	for (auto const& result : ageResults) {
		cout << VoteEnumNames[result.first] << ": " << result.second << endl;
	}
	cout << endl;
}

void printResultsBasedOnEthnos(vector<Voter> &voters, set<string> &ethnoses)
{
	string userSelectedEthnos;

	cout << "Results based on ethnos" << endl;
	cout << "Choose an ethnos: ";
	for (auto ehtnos : ethnoses) {
		cout << ehtnos << " ";
	}
	cout << endl;

	cin.ignore(256, '\n');
	getline(cin, userSelectedEthnos);
	map<Vote, int> ethnosResults = results_calculations::resultsBasedOnEthnos(userSelectedEthnos, voters);

	cout << endl;
	cout << "For ethnos: " << userSelectedEthnos << endl;
	for (auto const& result : ethnosResults) {
		cout << VoteEnumNames[result.first] << ": " << result.second << endl;
	}
	cout << endl;
}

void printResultsBasedOnCity(vector<Voter> &voters, set<string> &cities)
{
	string userSelectedCity;

	cout << "Results based on city" << endl;
	cout << "Choose a city: ";
	for (auto city : cities) {
		cout << city << " ";
	}
	cout << endl;

	getline(cin, userSelectedCity);
	map<Vote, int> cityResults = results_calculations::resultsBasedOnCity(userSelectedCity, voters);

	cout << endl;
	cout << "For city: " << userSelectedCity << endl;
	for (auto const& result : cityResults) {
		cout << VoteEnumNames[result.first] << ": " << result.second << endl;
	}
	cout << endl;
}

void runVoteCollectorMenu(vector<Voter> &voters, set<string> &names, set<int> &ages, set<string> &ethnoses, set<string> &cities)
{
	for (auto const& voter : voters) {
		names.insert(voter.getName());
		ages.insert(voter.getAge());
		ethnoses.insert(voter.getEthnos());
		cities.insert(voter.getCity());
	}

	cout << endl << endl;
	cout << "Vote collector menu:" << endl;
	cout << endl;

	cout << "Remain results in percent: " << results_calculations::remainResultsInPercent(voters) << "%" << endl;
	cout << "Leave results in percent: " << results_calculations::leaveResultsInPercent(voters) << "%" << endl;

	cout << "Remain results in numbers: " << results_calculations::remainResultsInNumbers(voters) << endl;
	cout << "Leave results in numbers: " << results_calculations::leaveResultsInNumbers(voters) << endl;

	cout << endl;

	printResultsBasedOnName(voters, names);
	printResultsBasedOnAge(voters, ages);
	printResultsBasedOnEthnos(voters, ethnoses);
	printResultsBasedOnCity(voters, cities);
}

void runVoteRegisterMenu(vector<Voter> &voters)
{
	unsigned short age;
	std::string name;
	Gender gender;
	std::string city;
	std::string ethnos;
	Vote vote;

	std::string input;

	cin.ignore(256, '\n');
	cout << "Name: ";
	getline(cin, name);

	cout << "Age: ";
	cin >> age;
	cin.ignore(256, '\n');

	cout << "Gender: ";
	getline(cin, input);
	transform(input.begin(), input.end(), input.begin(), ::tolower);

	if (input == "male")
	{
		gender = MALE;
	}
	else if (input == "female")
	{
		gender = FEMALE;
	}
	else
	{
		cerr << "Gender must be \"Male\" or \"Female\"!" << endl;
	}

	cout << "City/Town/Village: ";
	getline(cin, city);

	cout << "Ethnos: ";
	getline(cin, ethnos);

	cout << "Vote: ";
	getline(cin, input);
	transform(input.begin(), input.end(), input.begin(), ::tolower);

	if (input == "remain")
	{
		vote = REMAIN;
	}
	else if (input == "leave")
	{
		vote = LEAVE;
	}
	else
	{
		cerr << "Vote must be \"Remain\" or \"Leave\"!" << endl;
	}

	Voter voter = Voter(age, name, gender, city, ethnos, vote);
	if (voter.isValid())
	{
		voters.push_back(voter);
	}
}

int main()
{
	vector<Voter> voters;
	set<string> names;
	set<int> ages;
	set<string> ethnoses;
	set<string> cities;

	int menuSelection;
	bool isRunning = true;

	cout << "Brexit" << endl;

	while (isRunning)
	{
		cout << endl;
		cout << "Please choose an option: " << endl;
		cout << "1. Register a vote" << endl;
		cout << "0. Exit" << endl;

		cout << endl;
		cout << "Option: ";
		cin >> menuSelection;

		if (menuSelection != 0 && menuSelection != 1 && menuSelection != 12344321)
		{
			cerr << menuSelection << " is an invalid option!" << endl;
		}
		else if (menuSelection == 0)
		{
			isRunning = false;
		}
		else if (menuSelection == 12344321)
		{
			runVoteCollectorMenu(voters, names, ages, ethnoses, cities);
		}
		else
		{
			runVoteRegisterMenu(voters);
		}
	}
}