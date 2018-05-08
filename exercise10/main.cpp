#include "student.h"
#include "foreignStudent.h"
#include "workingStudent.h"
#include <iostream>
using namespace std;

int main()
{
    Student student("55555","IvanIvanov","FMI",2013);
    student.print();
    cout << "==================================\n";

    Student student1(student);
    student.print();
    cout << "==================================\n";


    ForeignStudent foreignStudent("555555","IvanIvanovic","FMI",2013,"Serbia",2000,"Beograd,bul.KnjazObrenovic32");
    foreignStudent.print();
    cout << "==================================\n";

    ForeignStudent foreignStudent1(foreignStudent);
    foreignStudent.print();
    cout << "==================================\n";


    WorkingStudent workingStudent("66666","PetyrPetrov","FMI",2012,3000);
    workingStudent.print();
    cout << "==================================\n";

    WorkingStudent workingStudent1(workingStudent);
    workingStudent.print();

    return 0;
}
