#include <cstdlib> 
#include <string> 

#include <iostream> 
#include <iomanip> 
using namespace std; 

class Student 
{ 
public: Student(); 
        ~Student(); 
        void ReadClasses(); 
        void PrintData(); 
        void Reset(); 
        Student& operator =(const Student& anotherStudent); 
  
private: 
    string name; 
    int numClasses; 
    string *classList; 
}; 
  
  
Student::Student() : name(""), numClasses(0), classList(NULL) 
{ 
} 
  
Student::~Student() 
{ 
    numClasses = 0;
    name = "";
    Reset(); 
} 
  
void Student::Reset() 
{ 
    if (classList) {
        numClasses = 0;  
        delete[] classList; 
        classList = NULL; 
        
    } 
} 
  
void Student::ReadClasses() 
{ 
    Reset(); 
    cout << "Enter student name > "; 
    getline(cin, name); 
    cout << "Enter number of classes > "; 
    cin >> numClasses; 
    cin.ignore(2, '\n'); 
    if (numClasses > 0) { 
        classList = new string[numClasses]; 
        for (int i = 0; i<numClasses; i++) { 
            cout << "Enter name of class " << (i + 1) << " > "; 
            getline(cin, classList[i]); 
        } 
    } 
    cout << endl; 
} 
  
void Student::PrintData() 
{ 
    cout << "Class List: " << endl; 
    for (int i = 0; i < numClasses; i++) { 
        cout << setw(2) << right << i + 1 << ") " << classList[i] << endl; 
    } 
} 
  
Student& Student::operator =(const Student& anotherStudent) 
{ 
    Reset(); 
    numClasses = anotherStudent.numClasses; 
    if (numClasses > 0) { 
        classList = new string[numClasses]; 
        for (int i = 0; i < numClasses; i++) { 
            classList[i] = anotherStudent.classList[i]; 
        } 
    } 
  
    return *this; 
} 
  
int main() 
{ 
  
    Student s1, s2; 
    s1.ReadClasses(); 
    cout << "Student 1's data:" << endl; 
    s1.PrintData(); 
    cout << endl; 
    s2 = s1; 
    cout << "Student 2's data after assignment from student 1:" << endl; 
    s2.PrintData(); 
    s1.Reset(); 
    cout << endl; 
    cout << "Student 1's data after reset:" << endl; 
    s1.PrintData(); 
    cout << endl; 
    cout << "Student 2's data, should still have original classes:" << endl; 
    s2.PrintData(); 
    cout << endl; 
    system("pause"); 
    return 0; 
}