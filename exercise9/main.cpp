#include "student.h"
#include "foreignStudent.h"
#include <iostream>
using namespace std;

int main()
{
    Student student("55555","IvanIvanov","FMI",2013);

    //student.print();

    ForeignStudent foreignStudent("555555","IvanIvanovic","FMI",2013,"Serbia",2000,"Beograd,bul.KnjazObrenovic32");
    foreignStudent.print();

    return 0;
}
