#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

const int NAME_MAX_LEN = 31;

class Student {
public:
    // constructors
    Student();
    Student(const char* name, int _fn);

    int getFn() const;
    const char* getName() const;

    void setFn(int fn);
    void setName(const char* name);

    // destructor
    ~Student();

private:

    char _name[NAME_MAX_LEN];
    int  _fn;
};


#endif // STUDENT_H_INCLUDED
