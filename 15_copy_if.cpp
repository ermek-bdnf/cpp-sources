//15_2 copy_if
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Person
{
	public:
		Person(string name, double score, int age) //constructor
		{
			this->Name = name;
			this->Score = score;
			this->Age = age;
		}
		bool operator()(const Person &p) //predicate
		//accepts a Person object (&p) as a parameter
		{
			return p.Score > 180;
			//we check whether the number of points is higher
			//this object (p), that is, the student�.
			//if yes, it returns the boolean value 1 (true)
			//if not, then 0(false)
		}
		string Name;
		double Score;
		int Age;
};

int main()
{
	vector<Person> people
	{
	Person("Maryah", 200, 19),
	Person("John", 300, 19),
	Person("Andrew", 130, 20),
	Person("Katty", 180, 17),
	Person("Izabella", 220, 18),
	Person("Sussane", 240, 19),
	Person("Maryah", 240, 17),
	Person("Maryah", 290, 22)
	};
	
	vector<Person> result;
	copy_if(people.begin(), people.end(), back_inserter(result), 
	[](const Person &p)
	{
		return p.Score >= 200;//p.Name == "Maryah";
		//return p.Age < 20 && p.Score > 200 && p.Name == "Maryah";
	});
	
	cout << "����� ���������:\t" << result.size() << endl;
	sort(result.begin(), result.end(),
		[](const Person &p1, const Person &p2)
	{
		//return p1.Name < p2.Name;
		return p1.Age < p2.Age;
	});
	for(auto el : result)
	{
		cout << "Name: " << el.Name << "\t\tScore: " << el.Score <<
		"\tAge: " << el.Age << endl;
	}
	/*
	copy_if(people.begin(), people.end(), back_inserter(result));
	//copying elements of vector people to vector result
	for(auto el : result)
	{
		cout << "Name: " << el.Name << "\t\tScore: " << el.Score << endl;
	}
	*/
	/*
	auto result = find_if(people.begin(), people.end(), [](const Person &p)
	{
		return p.Name == "Maryah";
		//return p.Score == 200;
		//return p.Score == 200 && p.Name == "Maryah";
	});
	if(result == people.end())
	{
		cout << "-" << endl;
	}
	else
	{
		cout << "+" << endl;
	}
	/*
	vector<int> v = { -11,14,16,15,16,14,12 }; 
	auto result = find_if(v.begin(),v.end(),[](int a)
	{
		//return a%2 == 0;
		//return a < 0;
		return a == 12;
	});
	if(result == v.end())
	{
		cout << "-" << endl;
	}
	else
	{
		cout << "+" << endl;
	}
	*/
	return 0;
}
