/*
 * @brief       List created "by hand"
 * @date        January 2019
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cctype>
#include <fstream>
#include <iomanip>

using namespace std;


struct Person
{
    string name;
    string surname;
    unsigned short age;

    Person *next;
};

//------------------------------- point 4--------------------------------------------------------
void deleteList(Person *head)
{
    Person *tmp = NULL;

    while (head)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

//------------------------------- point 1--------------------------------------------------------
bool addPerson(Person *&head, string name, string surname, unsigned short age)
{
    Person *newPerson = new Person;
    newPerson -> name = name;
    newPerson -> surname = surname;
    newPerson -> age = age;

    if(!newPerson)
        return false;

    if(!head)
    {
        head = newPerson;
    }
    else
    {
        Person *actual = head;
        while (actual -> next != NULL)
            actual = actual -> next;
        actual -> next = newPerson;
        newPerson -> next = NULL;
    }
    return true;
}


bool readFromFile(Person *&head, string fileName)

{
    if (!(head==NULL))
        deleteList(head);
    head=NULL;
    string name, surname;
    unsigned short age;

    ifstream myFile(fileName.c_str());
    if (myFile)
    {
        while (true)
        {
            myFile>>name;
            if (name.length()==0)
                break;
            myFile>>surname;
            myFile>>age;
            addPerson(head, name, surname, age);
            name="";
            surname="";
            age=0;
            myFile.clear();
            myFile.ignore(10000, '\n');

        }
        cout<<"Data read correctly\n"<<endl;
        return 1;
    }
    else
    {
        cout << "File not found" << endl;
        return 0;
    }
}

//------------------------------- point 2--------------------------------------------------------
bool checkMedian(Person *head, int median)
{
    string surname = head -> surname;
    unsigned short age = head ->age;
    if (surname.find('a') != std::string::npos && age > median)
        return true;
    else
        return false;
}

bool checkK2(Person *head, int age2)
{
    string surname = head -> surname;
    unsigned short age = head -> age;
    if (surname.find('k') != std::string::npos && age > age2)
        return true;
    else
        return false;
}


int* selectionSort(int *myTable, int tableSize)
{
    int i,j,m;
    for(i = 0; i<tableSize-1 ; ++i)
    {
        m = i;
        for(j = i+1; j<tableSize ; ++j)
            if(myTable[j] < myTable[m])
                m = j;
        swap(myTable[i],myTable[m]);
    }
    return myTable;
}


int Median(Person *head)
{
    Person *actual = head;
    int mySize = 0;
    while (actual != NULL)
    {
        mySize +=1;
        actual = actual -> next;
    }
    int age[mySize];
    actual = head;
    for (int i = 0; i < mySize; i++)
    {
        age[i] = actual -> age;
        actual = actual -> next;
    }
    int *sorted = selectionSort(age, mySize);

    if(mySize%2 == 0)
    {
        double med = (sorted[mySize/2] + sorted[mySize/2-1])/2;
        return med;
    }
    else
    {
        return sorted [(mySize)/2];
    }
}

void newElement(Person *&head)
{
    Person *last = head;
    Person *actual = head;
    int age2;

    while(last -> next !=NULL)
        last = last -> next;

    if (head -> next != NULL)
        age2 = head -> next -> age;

    int median = Median(head);
    cout << "Median is: " << median << endl;

    if (head -> next == NULL)
        return;
    else
    {
        if (checkMedian(head, median) || checkK2(head, age2))
        {
            Person *newPerson = new Person;
            newPerson -> age = last -> age;
            newPerson -> name = last -> name;
            newPerson -> surname = last -> surname;

            newPerson -> next = head;
            head = newPerson;
        }
    }

    while (actual -> next != NULL)
    {
        if (checkMedian(actual -> next, median) || checkK2(actual -> next, age2))
        {
            Person *newPerson = new Person;
            newPerson -> age = last -> age;
            newPerson -> name = last -> name;
            newPerson -> surname = last -> surname;

            newPerson -> next = actual -> next;
            actual -> next = newPerson;
            actual = newPerson;
        }
        actual = actual -> next;
    }
}

//------------------------------- point 3--------------------------------------------------------
void deleteOdd(Person *&head)
{
    int odd = 0;
    bool deleted = false;
    Person *actual = head;
    if(actual -> age % 2 == 1)
        odd += 1;
    while (actual -> next != NULL)
    {
        deleted = false;
        if(actual -> next -> age % 2 == 1)
        {
            odd += 1;
            if (odd %2 == 0)
            {
                Person *tmp = actual ->next;
                actual -> next = actual -> next -> next;
                delete tmp;
                deleted = true;
            }
        }
        if (!deleted)
        {
            actual = actual -> next;
        }
    }
}


//------------------------------- point 5--------------------------------------------------------
void printList(Person *head)
{
    cout << "\n-------------------------------" << endl;
    while (head)
    {
        cout << head -> name << " " << head -> surname << ", age: " << head -> age << endl;
        head = head->next;
    }
    cout << "-------------------------------\n" << endl;
}


// ------------------------------MAIN -------------------------------------------------------------

int main(int argc, char* argv[])
{
    Person *head = NULL;
    string fileName;
    cout << "Give the name of a file " << endl;
    cin >> fileName;
    if (!readFromFile(head,fileName))
        return 0;

    cout << "List after reading the file" << endl;
    printList(head);
    newElement(head);
    cout << "List after adding the element according to point 2." << endl;
    printList(head);
    deleteOdd(head);
    cout << "List after deleting almenets according to point 3." << endl;
    printList(head);

    deleteList(head);
}
