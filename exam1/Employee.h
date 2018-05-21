#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

const int NAME_MAX_LEN = 31;

class Employee
{
public:
    Employee();
    Employee(const char*, int id, int startYear);
    bool operator < (const Employee& other);
    Employee& operator = (const Employee& other);

    const char* getName() const;
    int getId() const;
    int getStartYear() const;

    void setName(const char* newName);
    void setId(int id);
    void setStartYear(int startYear);

    static int getNumEqualities();

private:
   char       _name[NAME_MAX_LEN];
   int        _id;
   int        _startYear;
   static int _equalityCounter;
};

#endif // EMPLOYEE_H_INCLUDED
