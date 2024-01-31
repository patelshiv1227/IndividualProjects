Name: Shiv Patel
EECE.4811 201 Operating Systems
Individual Assignment - 1
--------------------------------------------

Contents of the submission:

1. CMakeLists.txt   - This is the file that cmake will use when building the code.
2. file1.txt        - This file contains the data the will be stored in three data structures.
3. main.cpp         - This is the source file that reads from file1.txt and stores the values in a Queue, Stack, and Linked List.
                        It then prints each data structure.
--------------------------------------------

Steps to building and running the code: 

1. Navigate to the project folder (~/IndividualProjects/Assignment1)
2. Run the follwing commands in the commandline:
    - mkdir build
    - cd build 
    - cmake ..
    - cmake --build .
3. There should be an executable named "Assignment1" made in the build folder.
4. To run the executable, run the following command.
    - ./Assignment1 file1.txt
5. The code should now execute with all three data structures printed.
--------------------------------------------