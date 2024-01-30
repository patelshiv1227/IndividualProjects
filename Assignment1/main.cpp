#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <list>
using namespace std;

int main(int argc, char** argv)
{
    int txtContent;             // Variable to store the contents of the text file into a string.
    string fileName;            // Name of the text file.
    fstream txtFile;            // Variable to store the instance of the file to work with.
    queue <int> data_Queue;     // Queue data structure.
    stack <int> data_Stack;     // Stack data structure.
    list <int> data_List;       // Linked List data structure.
    list <int>::iterator i;     // Iterator.

    // Parse commandline arguements.
    for (int i = 0; i < argc; i++) 
    {
        fileName = argv[i];
    }

    // Open file1.txt to perform a read operation.
    txtFile.open(fileName,ios::in);

    // Verify if the file is open or not.
    if(txtFile.is_open())
    {
        // Read the contents of the file and store them in appropriate data structures.
        while(txtFile >> txtContent)
        {
            // Store the content in each data structure.
            data_Queue.push(txtContent);
            data_Stack.push(txtContent);
            data_List.push_back(txtContent);
        }

        // Close the file.
        txtFile.close();

        // Sorting the linked list in ascending order.
        data_List.sort();

        // Print the contents of the queue.
        cout << "QUEUE CONTENTS:" << endl;
        while(!(data_Queue.empty()))
        {
            cout << data_Queue.front() << " ";
            data_Queue.pop();
        }
        cout << endl << endl;

        // Print the contents of the stack.
        cout << "STACK CONTENTS:" << endl;
        while(!(data_Stack.empty()))
        {
            cout << data_Stack.top() << " ";
            data_Stack.pop();
        }
        cout << endl << endl;

        // Print the contents of the linked list.
        cout << "LIST CONTENTS:" << endl;
        for (i = data_List.begin(); i != data_List.end(); ++i)
        {
            cout << *i << " ";
        }
        cout << endl << endl;
    }
    else
    {
        cout << "Could not open the file..." << endl;
    }

    return 0;
}