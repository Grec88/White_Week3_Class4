//============================================================================
// Name        : Week3_Class4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person {
public:
	void ChangeFirstName(int year1, const string &first_name) {
		base[year1].name = first_name;
		base[year1].quant1 = 1;
		if (base.size() != 0) {
			for (auto& [key, value] : base) {
				if (year1 == key) {
					base[year1].name = first_name;
				}
				if (year1 < key) {
					base[year1].name = first_name;
					if (value.quant1 == 0) {
						value.name = first_name;
					}
					if (value.quant1 == 1) {
						break;
					}
				} else if (year1 > key && value.quant1 == 0) {
					base[year1].name = first_name;
					base[year1].surname = value.surname;
				}
			}
		}
	}
	void ChangeLastName(int year1, const string &last_name) {
		base[year1].surname = last_name;
		base[year1].quant2 = 1;
		if (base.size() != 0) {
			for (auto& [key, value] : base) {
				if (year1 == key) {
					base[year1].surname = last_name;
				}
				if (year1 < key) {
					base[year1].surname = last_name;
					if (value.quant2 == 0) {
						value.surname = last_name;
					}
					if (value.quant2 == 1) {
						break;
					}
				} else if (year1 > key && value.quant2 == 0) {
					base[year1].surname = last_name;
					base[year1].name = value.name;
				}
			}
		}
	}

	string GetFullName(int year) {
		if (base.size() == 0) {
			return "Incognito";
		}
		if (base.size() != 0) {
			int k = 0, t = 0;
			for (const auto& [key, value] : base) {
				if (year == key) {
					if (value.surname == "") {
						return value.name + " with unknown last name";
					}
					if (value.name == "") {
						return value.surname + " with unknown first name";
					} else {
						return value.name + " " + value.surname;
					}
				}
				if (year < key && t == 0) {
					return "Incognito";
				} else if (year > key) {
					k = key;
					t++;
				}
			}
			if (base[k].surname == "") {
				return base[k].name + " with unknown last name";
			}
			if (base[k].name == "") {
				return base[k].surname + " with unknown first name";
			} else {
				return base[k].name + " " + base[k].surname;
			}
		}
	}



	/*void Print() {
		for (const auto& [key, value] : base) {
			cout << key << " " << value.name << " " << value.surname << endl;
		}
	}*/

private:
	map<int, Person> base;
	string name;
	string surname;
	int quant1;
	int quant2;
};

int main() {
	/*	Person person;

	 person.ChangeFirstName(1965, "Polina");
	 person.ChangeLastName(1967, "Sergeeva");
	 for (int year : {1900, 1965, 1990}) {
	 cout << person.GetFullName(year) << endl;
	 }

	 person.ChangeFirstName(1970, "Appolinaria");
	 for (int year : {1969, 1970}) {
	 cout << person.GetFullName(year) << endl;
	 }

	 person.ChangeLastName(1968, "Volkova");
	 for (int year : {1969, 1970}) {
	 cout << person.GetFullName(year) << endl;
	 }*/
	Person person;
	cout << person.GetFullName(2000) << endl;
	person.ChangeLastName(1968, "1968_2nd");
	person.ChangeLastName(1967, "1967_2nd");
	person.ChangeLastName(1965, "1965_2nd");
	person.ChangeLastName(1966, "1966_2nd");
	for (int year : { 1900, 1920, 1950, 1965, 1966, 1967, 1968 }) {
		cout << person.GetFullName(year) << endl;
	}
	person.ChangeFirstName(1920, "1920_1st");
	person.ChangeFirstName(1900, "1900_1st");
	person.ChangeFirstName(1965, "1965_1st");
	person.ChangeFirstName(1950, "1950_1st");
	for (int year : { 1900, 1920, 1950, 1965, 1966, 1967, 1968 }) {
		cout << person.GetFullName(year) << endl;
	}
	//cout << endl;
	//person.Print();
	return 0;

}
