#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

class Student
{
    char _facNum[10];
    char* _name;
    char* _faculty;
    int _startYear;
public:
    Student(char* facNum, char* name, char* faculty, int startYear);
    Student(const Student& other);
    Student& operator = (const Student& other);
    ~Student();

    void setFacNum(const char* facNum);
    void setName(const char* name);
    void setFaculty(const char* faculty);
    void setStartYear(int startYear) {_startYear = startYear;}

    const char* getFacNum() const {return _facNum;}
    const char* getName() const {return _name;}
    const char* getFaculty() const {return _faculty;}
    int getStartYear() const {return _startYear;}

    void print() const;
private:
    void copyStudent(const Student& other);
    void destroyStudent();
};

#endif // STUDENT_H_INCLUDED
