#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
};

class Student : public Person{
public:
    int roll_no;
    Student(string name, int age, int roll_no) : Person(name,age){
        this->roll_no = roll_no;
    }
};

class Teacher{
public:
    string subject;
    int salary;

    Teacher(string subject, int salary){
        this->subject = subject;
        this->salary = salary;
    }
};

class Teaching_Assistant : public Student, public Teacher{
public: 
    Teaching_Assistant(string name, int age, int roll_no, string subject, int salary) : Student(name,age, roll_no), Teacher(subject,salary){
    }
    void getinfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "roll_no: " << roll_no << endl;
        cout << "Subject: " << subject<< endl;
        cout << "Salary: "<< salary << endl;
    }
};

int main(){
    Teaching_Assistant TA("Rahul",26,1234, "AI", 38000); // here passing main class attributes with derived class
    TA.getinfo();
}