/*
*******************************************************************************************************************************************
 *Purpose/Description:  	This is a simple program whose objective is to find the prime numbers in the range of 1 to 50000. To meet 
			this objective with better effect in terms of execution time, the program uses multiprocessing. There is a constant 
			n equal to 50000, and the program uses a for loop to iterate from 1 to n and thus determine how many prime numbers 
			exist in that range and what they are. At the end, the program shows users the total number of prime numbers and the 
			time it took for the whole process.  

 * Author’s Name: Jose Aparicio
 * Author’s Panther ID: 6186111 
 * Certification: I hereby certify that this work is my own and none of it is the work of any other person.
*********************************************************************************************************************************************
*/
#include <stdio.h>
#include <unistd.h>
#include <mpi.h>

int check_prime (int id, int z) {							//function to check if a number is prime
	int i;										//variable to be used in the for loop
	int prime=1;									//integer to be use as boolean
    	if(z>2){									//1 is not prime by definition, and two is not prime, so the program checks for numbers bigger than 2 
        	for(i=2;i<= z/2;i++){							//for loop to go from 2 to z/2 to check if the reminder of the division is 0
            		if((z%i)==0){							// if statement to check if the reminder of the division is 0
                	prime=0;							//setting the flag to false
	        	break;								//breaking the loop
	    		}
        	}
    	}else{
		prime=0;								//if z<2 the the flag is set to false
    	}
   	 if(prime){									//if flag is true
		printf("Process: %d found prime number: %d\n", id, z);			//print the number and the process
		return 1;								//return 1 to increment the counter
	}
	fflush (stdout);								//cleaninf the stdout
 return 0;										//returning 0 if not prime
}

const long int n = 50000;								//constanto to set the upper bound

int main (int argc, char *argv[]) 							//main function
{
  	int count;            								// Prime numbers found by this proc
  	double elapsed_time;  								// Time to find, count prime numbers
  	int global_count;     								// Total number of solutions prime numbers
  	int i;										//variable to be used in the for loop
  	int id;               								// Process rank 	
  	int p;                								// Number of processes 
  	char hostname[1024];

  	MPI_Init (&argc, &argv);							//initializing the MPI

  	MPI_Comm_rank (MPI_COMM_WORLD, &id);						//getting the process rank (id)
  	MPI_Comm_size (MPI_COMM_WORLD, &p);						//getting the number of processes

  	
  	MPI_Barrier (MPI_COMM_WORLD);							//starting the timer
  	elapsed_time = - MPI_Wtime();

  	count = 0;									//initializing count to 0
  	for (i = id; i <= n; i += p)							//for loop to go number by number
    		count += check_prime (id, i);						//calling the function check the number and increment the counter if it is prime
 
  	MPI_Reduce (&count, &global_count, 1, MPI_INT, MPI_SUM, 0,
	      MPI_COMM_WORLD); 

  	
  	elapsed_time += MPI_Wtime();							//stopping the timer
 
	MPI_Finalize();
  	if (!id) {
    		printf ("\nExecution time %8.6f\n", elapsed_time);			//displaying the execution time
    		fflush (stdout);							//cleaning the stdout
  	}

  	if (!id) 
		printf("There are %d prime numbers\n",global_count);			//displaying the total number of prime numbers
  return 0;
}

