#include <iostream>
#include <vector>
using namespace std;

class Person{
    private:
        string first_name, last_name;
    public:
        Person(string first_name, string last_name): first_name(first_name), last_name(last_name) {}
        Person() = default;
        void Printname(){
            cout << first_name << endl << last_name << endl; 
        }
        void Setter(string first_name, string last_name){
            this -> first_name = first_name;
            this -> last_name = last_name;
        }
        string Getter(){
            return first_name + " " + last_name + "\n";
        }
        static void printNames(vector <Person*> people){
            for(auto person : people){
                person -> Printname();
            }
        }
};

class Student : public Person{
    private:
        int group;
    public:
        Student(string first_name, string last_name, int group) : Person(first_name, last_name), group(group) {};
        int getGroup(){
            return group;
        }
        void SetGroup(int group){
            this -> group = group;
        }
        void Info(){
            cout << Getter() << getGroup() << endl;
        }
};

int main(){
    Person p1("Vitaliy", "Shaybekov");
    vector <Person*> people;
    //p1.Setter();

    cout << p1.Getter() << endl;
    
    Student s("Starodumov", "Grigoriy", 2371);
    s.Info();

    people.push_back(&p1);
    people.push_back(&s);

    Person::printNames(people);

    return 0;
}