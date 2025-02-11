#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

bool comp1(Student x, Student y) {
    return x.getName() < y.getName();
}

bool comp2(Student x, Student y) {
    return x.getAge() < y.getAge();
}

int main ()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            {
            string nimi;
            int ika;
            cout<<"Syota nimi"<<endl;
            cin>>nimi;
            cout<<"Syota ika"<<endl;
            cin>>ika;
            Student uusiStudent(nimi, ika);
            studentList.push_back(uusiStudent);
            break;
            }

        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            {
            for (int i = 0;i < distance(studentList.begin(),studentList.end());i++){
                studentList[i].printStudentInfo();
            }
            break;
            }

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            {

            sort(studentList.begin(),studentList.end(),comp1);
            for (auto i : studentList){
                i.printStudentInfo();
            }
            break;
            }

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            {
            sort(studentList.begin(),studentList.end(),comp2);
            for (auto i : studentList){
                i.printStudentInfo();
            }
            break;
            }

        case 4:
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            {
            string nimi;
            cout<<"Syota nimi"<<endl;
            cin>>nimi;
            auto it = find_if(studentList.begin(), studentList.end(),[nimi](Student& obj){return nimi ==obj.getName();});
            if (it != studentList.end()){
                it->printStudentInfo();
            }
            else {
                cout<<"Opiskelijaa ei loytynyt"<<endl;
            }
            break;
            }

        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
}   while(selection < 5);

return 0;
}
