#include <iostream>
#include <string>
class Employee 
{
    private:
    std::string name;
    int employeeID;
    double salary;

    public:
    // Constructor to initialize employee details
    Employee(std::string empName, int empID, double empSalary) {
    name = empName; 
    employeeID = empID; 
    salary = empSalary; 
    }
// Getter methods for accessing private attributes
std::string getName() {
return name;}

int getEmployeeID(){
return employeeID;}

double getSalary() {
return salary;}

// Setter method for modifying salary
void setSalary(double newSalary) {
if (newSalary >= 0) {
salary = newSalary;}
}

// Display employee information
void displayEmployeeInfo() {
std::cout << "Employee Name:" << name << std::endl;
std:: cout << "Employee ID: " << employeeID << std::endl;
std::cout << "Salary: INR " << salary << std::endl;}
};

int main(){

// Create an Employee object and initialize it
Employee emp1 ("Manik Shah", 101, 50000.0);

// Access and display employee information
emp1.displayEmployeeInfo();

//Modify the salary using the setter method
emp1.setSalary(55000.0);

// Display updated employee information
emp1.displayEmployeeInfo();

return 0;
}
