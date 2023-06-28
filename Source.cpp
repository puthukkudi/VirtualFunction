/*
* 
* Virtual Function Demo
* Created by : Prashant Puthukkudi
* Date : 28/06/2023
* 
*/



#include<iostream>


class Employee
{
public :

	void Promote() // not overridden
	{
		std::cout << "Employee class Promote"<<std::endl;
	}

	void RaiseSalary() // no virtual declared and tried to override
	{
		std::cout << "Employee class RaiseSalary" << std::endl;
	 }

	virtual void Terminate() // declared virtual and tried to override
	{
		std::cout << "Employee class Terminate :/" << std::endl;
	}

	/*
	* Only non virtual function can be static. Below statement will throw error
	*/
	//static virtual void NoHike() = 0; // pure virtual

	virtual void NoHike() = 0; // pure virtual
};

class Engineer : public Employee
{
public:
	void RaiseSalary()
	{
		std::cout << "Engineer class RaiseSalary" << std::endl;
	}

	void Terminate() override   // keyword override is optional
	{
		std::cout << "Engineer class Terminate :/" << std::endl;
	}

	void NoHike() override
	{
		std::cout << "Engineer class NoHike :/" << std::endl;
	}
};



int main()
{
	/*
	*  Compiler will throw error in below line if pure virtual method is not defined in Child class.
	*/
	Employee* emp = new Engineer();     // up casting 
	emp->Promote();
	emp->RaiseSalary();
	emp->Terminate();
	emp->NoHike();


	std::cin.get();
}