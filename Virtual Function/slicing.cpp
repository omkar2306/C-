#include<iostream>
#include<string.h>
class person
{
private:
  char name[20];
  int age;
public:
  person(const char* name="",int age=0)
  {
    strcpy(this->name,name);
    this->age=age;

  }
  void setName(const char* name="")
  {
    strcpy(this->name,name);
  }
  void setAge(int age=0)
  {
     this->age=age;
  }

  const char* getName()
  {
    return this->name;

  }
  int getAge()
  {
    return this->age;
  }
  void display()
  {
    std::cout<<"NAME:-"<<this->name<<std::endl<<"AGE:-"<<this->age<<std::endl;
  }
};
class employee:public person
{
private:
  int id;
  float salary;
public:
  employee(const char* name="", int age=0, int id=0, float salary=0.0f):person(name,age)
  {
    this->id=id;
    this->salary=salary;

  }
  void setId(int id=0)
  {
    this->id=id;
  }
  void setSalary(float salary=0.0f)
  {
    this->salary=salary;
  }
  int getId()
  {
    return this->id;
  }
  float getSalary()
  {
    return this->salary;
  }
  void display()
  {
    person::display();
    std::cout<<"ID:-"<<this->id<<std::endl<<"SALARY:-"<<this->salary<<std::endl;
  }

};
int main()
{
  person p1("mahiraj,758");
employee e1("MAHESH",19,3183,500000);
p1=e1;
p1.display();
}
