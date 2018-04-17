#include "Student.h"


std::ostream& operator << (std::ostream& out, Student const& student)
{
    out << student.fn << std::endl;

    return out;
}

std::istream& operator >> (std::istream& in, Student& student)
{
    in >> student.fn;

    return in;
}
