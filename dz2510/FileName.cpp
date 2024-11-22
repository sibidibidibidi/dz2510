#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Building
{
public:
	Building() = default;
	Building(string location, vector<Apartment> apartments)
	{
		this->location = location;
		this->apartments = apartments;
	}
	Building(const Building& building) : location(building.location), apartments(building.apartments) {};
	void printbuild()
	{
		cout << endl << "Location: " << location << endl;
		cout << "Apartments: " << endl << endl;
		for (size_t i = 0; i < apartments.size(); i++)
		{
			apartments[i].printapartment();
			cout << endl;
		}
	}
	void enterbuild()
	{
		Apartment temp;
		int count;
		cout << "Enter location: "; cin >> location;
		cout << "Enter number of apartments: "; cin >> count;
		for (size_t i = 0; i < count; i++)
		{
			apartments.push_back(temp);
		}
		for (size_t i = 0; i < count; i++)
		{
			apartments[i].enterapartment();
		}
	}

private:
	string location;
	vector<Apartment> apartments;
};

class Person
{
public:
	Person() = default;
	Person(string fullName, int yearsOld, string bio)
	{
		this->fullName = fullName;
		this->yearsOld = yearsOld;
		this->bio = bio;
	}
	Person(const Person& person) : fullName(person.fullName), yearsOld(person.yearsOld), bio(person.bio) {};
	void printperson()
	{
		cout << "Full name: " << fullName << endl;
		cout << "Age: " << yearsOld << endl;
		cout << "Biography: " << bio << endl;
	}
	void enterperson()
	{
		cout << "Enter full name: "; cin >> fullName;
		cout << "Enter age: "; cin >> yearsOld;
		cout << "Enter biography: "; cin >> bio;
	}
	~Person() = default;

private:
	string fullName;
	int yearsOld;
	string bio;
};

class Apartment
{
public:
	Apartment() = default;
	Apartment(int unitNumber, int floorLevel, vector<Person> residents)
	{
		this->unitNumber = unitNumber;
		this->floorLevel = floorLevel;
		this->residents = residents;
	}
	Apartment(const Apartment& apartment) : unitNumber(apartment.unitNumber), floorLevel(apartment.floorLevel), residents(apartment.residents) {};
	void printapartment()
	{
		cout << "Unit number: " << unitNumber << endl;
		cout << "Floor level: " << floorLevel << endl;
		cout << "Residents: " << endl << endl;
		for (size_t i = 0; i < residents.size(); i++)
		{
			residents[i].printperson();
			cout << endl;
		}
	}
	void enterapartment()
	{
		Person temp;
		int count;
		cout << "Enter unit number: "; cin >> unitNumber;
		cout << "Enter floor level: "; cin >> floorLevel;
		cout << "Enter number of residents: "; cin >> count;
		for (size_t i = 0; i < count; i++)
		{
			residents.push_back(temp);
		}
		for (size_t i = 0; i < count; i++)
		{
			residents[i].enterperson();
		}
	}
	~Apartment() = default;

private:
	int floorLevel;
	int unitNumber;
	vector<Person> residents;
};

int main()
{
	Building buildingOne;
	buildingOne.enterbuild();
	Building buildingTwo(buildingOne);
	buildingTwo.printbuild();
}
