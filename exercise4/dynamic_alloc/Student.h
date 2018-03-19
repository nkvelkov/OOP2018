#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

class Student {
public:
    // Constructors
    Student();
    Student(const char* name, int _fn);

    // Copy constructor
    Student (const Student& right);

    // operator =
    // Student& operator = (const Student& right);

    int getFn() const;
    const char* getName() const;

    void setFn(int fn);
    void setName(const char* name);

    // Destructor
    ~Student();

private:
    char* _name;
    int   _fn;
};

#endif // STUDENT_H_INCLUDED
