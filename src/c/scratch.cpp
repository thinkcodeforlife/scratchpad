#include <iostream>

using namespace std;

class Animal
{
	private:	
		int age;
	public:
		string name;
		Animal(string n, int a)
		{
			name = n;
			age = a;
		}
		int getAge()
		{
			return age;
		}
		void setAge(int a)
		{
			age = a;
		}
		void getInfo()
		{
			cout << name << " is " << getAge() << " years old" << endl;
		}
};

int main()
{
	Animal dog("daisy", 12);
	dog.getInfo();
	dog.setAge(15);
	dog.getInfo();
	return 0;
};

