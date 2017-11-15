# N-Queens-Problem


The program solves the N-Queens problem using min-conflict strategy. 

The program is executed by the ‘main()’ function. A seed is first set so a random number is generated in the initialize() function which then assigns a position to every queen. Then the state of the system is print using the printState() function. 

The min conflict is calculated using the search() function. The program creates an array of the number of conflicts in each column. Then the queen is moved to the spot where the number of conflicts are the least. The program continues this until the number of conflicts for each queen is 0. 

The program is controlled by the isFInalState() function. If the boolean return value is false, search() is called again. 

