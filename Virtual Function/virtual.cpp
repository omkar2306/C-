#include<iostream>
#include<string.h>
class employee
{
private:
  char name[10];
  int age;
  int id;
protected:
  float salary;
public:
  employee(const char* name="", int age=0, int id=0, float salary=0.0f)
  {
    strcpy(this->name,name);
    this->age=age;
    this->id=id;
    this->salary=salary;
  }
    char* getName()
    {
      return this->name;
    }
    int getAge()
    {
      return this->age;

    }
    int getId()
    {
      return this->id;
    }
    float getSalary()
    {
      return this->salary;
    }
    virtual float cal_salary()
    {
      return this->salary;
    }
    virtual void display()
    {
      std::cout<<"NAME:"<<this->name<<std::endl<<"AGE:"<<this->age<<std::endl<<"ID:"<<this->id<<std::endl<<"SALARY:"<<this->salary<<std::endl;
    }
};

class manager:public employee
{
public:
  float bonus;
public:
  manager(const char* name="", int age=0, int id=0, float salary=0.0f,int bonus=0):employee(name,age,id,salary)
  {
  this->bonus=bonus;
  }
 float getBonus()
 {
   return this->bonus;
 }
 float cal_salary()
 {
   return (this->salary+this->bonus);
 }
 void display()
 {
  employee::display();
  std::cout<<"BONUS:"<<this->bonus<<std::endl;
 }

};
class saleman:public employee
{
private:
  float insentive;
public:
  saleman(const char* name="", int age=0, int id=0, float salary=0.0f,int insentive=0):employee(name,age,id,salary)
  {
  this->insentive=insentive;
  }
 int getInsentive()
 {
   return this->insentive;
 }
 float cal_salary()
 {
 return(this->salary+this->insentive);
}
 void display()
 {
  employee::display();
  std::cout<<"INSENTIVE:"<<this->insentive<<std::endl;
 }

};
float total_sal(employee* arr[],int n)
{
  int i;
float total_s=0.0f;
for(i=0;i<n;i++)
{
total_s=total_s+arr[i]->getSalary();
}
return total_s;
}
float total_inc(employee* arr[],int n)
{
  int i;
float total_income=0.0f;
for(i=0;i<n;i++)
{
total_income=total_income+arr[i]->cal_salary();
}
return total_income;
}
int main()
{
  int i;
  employee* arr[6];

  arr[0]=new employee("MAHESH",19,33,50000.0f);
  arr[1]=new manager("KIRAN",20,43,50000.0f,5000);
  arr[2]=new saleman("YOGESH",18,53,50000.0f,2000);
  arr[3]=new employee("ADITYA",19,34,50000.0f);
  arr[4]=new manager("AJIT",21,44,50000.0f,5000);
  arr[5]=new saleman("SACHIN",22,54,50000.0f,2000);

  for(i=0;i<6;i++)
  {
    arr[i]->display();
  }

  float total_salary=total_sal(arr,6);
  std::cout<<"TOTAL SALARY:"<<total_salary<<std::endl;

  float total_income=total_inc(arr,6);
  std::cout<<"TOTAL INCOME:"<<total_income<<std::endl;
}
