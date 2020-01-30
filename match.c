/*----------------------------------------------------------------------------
**
** NAME
**   match -- print lines matching a pattern
**
** SYNOPSIS
**   match [-i] pattern
**
** DESCRIPTION
**   The match utility prints lines read from stdin matching a pattern.
**
**   The pattern must be a simple string (no regular expressions).
**
**   Matching is by default case-sensitive.  The -i option instructs match
**   to ignore case.
**
** EXAMPLES
**   match xyz     #Prints lines containing the string xyz read from stdin
**
** EXIT STATUS
**   0 One or more lines matched
**   1 No lines matched
**   2 An error occurred
**
** AUTHORS
**   01/17/19 Epoch.........................................................jrc
**
**---------------------------------------------------------------------------*/





//Import definitions required to access functionality implemented elsewhere
#include <stdio.h>    //Standard I/O functions and definitions
#include <stdlib.h>   //Standard library (includes exit function)
#include <string.h>  //String manipulation functions

//External variables and constants
static int caseSensitive=1;     //By default, matching is case-sensitive




//-----------------------------------------------------------------------------
//  usage -- Prints a usage message and exits with status=2
//-----------------------------------------------------------------------------
void usage(char* s) {
    
    //Print the usage message to stderr
    fprintf(stderr,"Usage:  %s pattern\n",s);
    
    //Force an exit.  This is equivalent to return 2 in main()
    exit(2);                //Exit status is 2
    
}




//-----------------------------------------------------------------------------
//  main -- The main function invoked by CRT to start the program
//-----------------------------------------------------------------------------
int main(int argc, char **argv) {

    char *pattern;                 //Pointer to the user-supplied pattern
    
    //Initialize the normal (non-error) exit status
    int exitStatus = 1;            //No lines have matched (so far)
    
    //Check for -o option and find the pattern in command-line args
    if (argc==3) {
        if (strcmp(argv[1],"-i")==0){
			caseSensitive=0;  //Ignore case
		} else {
			usage(argv[0]);
		}
        pattern = argv[2];           //Reference to pattern in args
    } else if (argc==2) {
        pattern = argv[1];           //Reference to pattern in args
    } else {
        usage(argv[0]);             //Publish usage message and error exit
    }

	//Verify the pattern is not an empty string
    if (strlen(pattern)==0) usage(argv[0]);

    
    //<<<Insert your implementation for match here>>>

	
	char s[256];
	while(fgets(s, sizeof(s), stdin) != NULL) {
		if(caseSensitive == 0){
			int i = 0;
			while(s[i]){
				s[i] = tolower(s[i]);
				i++;
			}
			int j = 0;
            while(pattern[j]){
                pattern[j] = tolower(pattern[j]);
                j++;
            }

		}
		if(strstr(s, pattern) != NULL) {
			exitStatus = 1;
			printf("%s", s);
		}
	}


    
    //Report the exit status to the CRT
    return exitStatus;
}


