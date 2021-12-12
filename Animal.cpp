#include "Animal.h"

Animal::Animal(string owner, string typeOfAnimal, string alias, int age)
{
	setOwner(owner);
	settypeOfAnimal(typeOfAnimal);
	setAlias(alias);
	setAge(age);
}

void Animal::setOwner(string owner)
{
	if (owner.empty()) throw exception("error:info not correct");
	this->owner = owner;
}

void Animal::settypeOfAnimal(string typeOfAnimal)
{
	if (typeOfAnimal.empty()) throw exception("error:info not correct");
	this->typeOfAnimal = typeOfAnimal;
}

void Animal::setAlias(string alias)
{
	this->alias = alias;
}

void Animal::setAge(int age)
{
	if (age < 0 || age == NULL) throw exception("error:info not correct");
	this->age = age;
}

void Animal::printInfo()
{
	cout << "Владелец - " << owner << "; Вид животного -  " << typeOfAnimal << "; Кличка - " << alias << "; Возраст - " << age << '.' << endl;
}

int Animal::getAge() const
{
	return age;
}

string Animal::getAlias() const
{
	return alias;
}

string Animal::getTypeOfAnimal() const
{
	return typeOfAnimal;
}

ostream& operator<<(ostream& s, const Animal& p)
{
	s << p.typeOfAnimal << ',' << p.alias << ',' << p.age << ',' << p.owner;
	return s;
}
