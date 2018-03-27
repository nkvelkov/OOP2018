#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

const int NAME_MAX_LEN = 31;


class Student {
public:
    Student();
    Student(const char* name, int _fn);

    Student (const Student& right);

    Student& operator= (const Student& right);

    int getFn() const;
    const char* getName() const;

    void setFn(int fn);
    void setName(const char* name);

    ~Student();

    static int getCurrentNumObjects()
    {
        return id;
    }

    int getUid()
    {
        return _uid;
    }

private:

    static int id;

    int   _uid;
    char* _namePtr;
    char _name[NAME_MAX_LEN];
    int  _fn;
};

#endif // STUDENT_H_INCLUDED
