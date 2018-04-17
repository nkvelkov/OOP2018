#include "StudentStream.h"


std::ostream& operator << (std::ostream& out, StudentStream const& student)
{
    out << student.fn << std::endl;

    return out;
}

std::istream& operator >> (std::istream& in, StudentStream& student)
{
    in >> student.fn;

    return in;
}
