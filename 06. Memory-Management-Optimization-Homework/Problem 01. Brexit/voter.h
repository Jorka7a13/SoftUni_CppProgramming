#ifndef VOTER_H
#define VOTER_H
#pragma once

#include <string>

enum Gender { MALE, FEMALE };
enum Vote { REMAIN, LEAVE };

class Voter
{
private:
	unsigned short age_;
	std::string name_;
	Gender gender_;
	std::string city_;
	std::string ethnos_;
	Vote vote_;

public:
	Voter();
	Voter(unsigned short age, std::string name, Gender gender, std::string city, std::string ethnos, Vote vote);

	bool operator<(const Voter& voter) const;

	void setAge(unsigned short age);
	unsigned short getAge() const;

	void setName(std::string name);
	std::string getName() const;

	void setGender(Gender gender);
	Gender getGender() const;

	void setCity(std::string city);
	std::string getCity() const;

	void setEthnos(std::string ethnos);
	std::string getEthnos() const;

	void setVote(Vote vote);
	Vote getVote() const;

	bool isValid() const; 
};

#endif