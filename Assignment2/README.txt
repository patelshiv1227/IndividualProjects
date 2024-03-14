Name: Shiv Patel
EECE.4811 201 Operating Systems
Individual Assignment - 2
--------------------------------------------

Contents of the submission:

1. CMakeLists.txt       - This is the file that cmake will use when building the code.
2. common_threads.h     - This is the header file that the source files use as a dependency.
3. fork-join.c          - This is the source file to the first solution.
4. rendezvous.c         - This is the source file to the second solution.
3. barrier.c            - This is the source file to the third solution.
--------------------------------------------

Steps to building and running the code: 

1. Navigate to the project folder (~/IndividualProjects/Assignment2)
2. Run the follwing commands in the commandline:
    - mkdir build
    - cd build 
    - cmake ..
    - cmake --build .
3. There should be 3 executable named "fork-join", "rendezvous", "barrier" made in the build folder.
4. To run the executable, run the following commands.
    - ./fork-join
    - ./rendezvous
    - ./barrier <# of threads to create>
--------------------------------------------