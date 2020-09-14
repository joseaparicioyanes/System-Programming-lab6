# System-Programming-lab6
Write an MPI program, countprimes which will count the number of prime numbers in the numbers
from 1 to n inclusive where n is a long integer. The value for n which should be set in the program
using a constant should be 50,000.
Each process will test its share of the cases.
Each process should print out any primes that it finds in a readable manner indicating which process
found it and the actual prime number found.
The master process should end with printing a total for the count of the number of primes and the
total amount of time taken to find all the primes.
Please follow the following instructions carefully before submitting your work:
Before submission, make sure you clean up the directories so that no miscellaneous files are kept
around in the submission. (Grade would be deducted if useless files are found in the homework
directories.) Include the source code and the Makefile in the submission. Your Makefile can assume
that the path to the MPI compiler is found in the path.
• Take a screenshot of the screen showing the output of running countprimes with 3
processors on ocelot. Name it FirstNameLastName.png or .jpg.
Submit your source file, the screenshot and your Makefile in one zip file called
FirstnameLastnameL6.zip to the assignment dropbox in Canvas.
If the program does not compile using MPICC and do something useful when it runs it will not earn any
credit.
