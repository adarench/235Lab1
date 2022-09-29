#ifndef TODO_LIST_H
#define TODO_LIST_H
#include <iostream>
#include <string>
#include "TodoListInterface.h"
#include <fstream>
#include <vector>

using namespace std;
class TodoList: public TodoListInterface {

public:

vector <string> tasks;

TodoList(){
    cout << "In Constructor" << endl;
    ifstream infile("TODOList.txt");
    string line;
    if (infile.is_open()){
        while( getline (infile, line) ){
            cout << line << '\n';
            tasks.push_back(line);
        }

        infile.close();
    }
    }
    virtual ~TodoList() {
        cout << "In Destructor" << endl;
        ofstream outfile;
        tmpfile.open("TODOList.txt", ofstream::out | ofstream:: trunc);
        for(int i = 0; i < tasks.size(); i++){
            outfile << tasks[i] << endl;
        }
        outfile.close();
    }
    /*
    *   Adds an item to the todo list with the data specified by the string 
"_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task){
        cout << "In add" << _duedate<< " " << _task<< endl;

        tasks.push_back(_duedate+" "+ _task);

    }

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task){
        cout << "In remove " << _task << endl;
        tasks.pop_back(_task);
    }
    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList(){
        cout << "In list" << endl;
        for(int i = 0; i < tasks.size(); i++){
            cout << tasks[i] << endl;
        }
    }
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified 
by _duedate)
    */
    virtual void printDaysTasks(string _date, string _task){

        cout << "In daystasks " << _date +" "+ _task << endl;
    }
};
#endif
