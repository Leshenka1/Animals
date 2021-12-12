#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Animal
{
private:
	string owner;
	string typeOfAnimal;
	string alias;
	int age;
public:
	Animal(string owner, string typeOfAnimal, string alias, int age);
	void setOwner(string owner);
	void settypeOfAnimal(string typeOfAnimal);
	void setAlias(string alias);
	void setAge(int age);
	void printInfo();
	int getAge() const;
	string getAlias() const;
	string getTypeOfAnimal() const;
	friend ostream& operator<<(ostream& s, const Animal& p);
};

