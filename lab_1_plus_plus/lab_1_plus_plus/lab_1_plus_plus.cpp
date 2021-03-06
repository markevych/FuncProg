#include "pch.h"
#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std; 

class Person {
	string name;
	int age;
	int score;
public:
	Person(string _name, int _age, int _score)
	{
		name = _name;
		age = _age;
		score = _score;
	}

	friend ostream & operator<<(ostream & str, Person const & person)
	{
		str << "Name : " << person.name << endl
			<< "Age : " << person.age << endl
			<< "Score : " << person.score << endl;
		return str;
	}

	string getName() const {
		return name;
	}

	int getAge() const {
		return age;
	}

	int getScore() const {
		return score;
	}
};

bool operator < (const Person & left, const Person & right)
{
	if (left.getName() < right.getName())
	{
		return true;
	}
	else if (left.getName() > right.getName())
	{
		return false;
	}
	else {
		if (left.getAge() < right.getAge())
		{
			return true;
		}
		else if (left.getAge() > right.getAge())
		{
			return false;
		}
		else {
			if (left.getAge() < right.getAge())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

Person* CreatePerson()
{
	cout << "Enter the name of person : ";
	string name;
	cin >> name;

	cout << "Enter the age of person : ";
	int age;
	cin >> age;

	cout << "Enter the score of person : ";
	int score;
	cin >> score;

	return new Person(name, age, score);
}

void CreateGroup(list<Person> & people)
{
	people.push_back(*CreatePerson());
	cout << "Do you want to add one more? Type \"Yes\" or any : ";
	string input;
	cin >> input;
	if (input == "Yes")
	{
		CreateGroup(people);
	}
}

int main()
{
	list<Person> people;
	CreateGroup(people);
	people.sort();
	copy(begin(people), end(people), ostream_iterator<Person>(cout, "\n"));
}


