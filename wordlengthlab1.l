   /* Kathleen Near
    * CS370 Lab1
    * 
    * Changes made:
    * 	- created variable numCount
    * 	- added second rule to detect numbers and increment numCount with every detection
    * 	- added a print statement to output the number of numbers detected in the file
    */

   /*  This lex routine uses a counting array to match alphabeticstrings 
         and make a frequency count.
  
         The real item to notice is that yywrap() is called at EOF and then is run
         to do what we need to do.   yywrap() returns true when we have a successful 
         end to the program.  We may want to return false (0) if we want to lexing process 
         to fail 

        Shaun Cooper
        January 2015
   */
	int lgths[100];
	int numCount = 0;
	
%%
[a-zA-Z]+	lgths[yyleng]++;
[0-9]+		numCount++;
.	|
\n	;
%%
yywrap()
{
	int i;
	printf("Length  No. words\n");
	for (i=1; i<100; i++) {
		if (lgths[i] > 0) {
			printf("%5d%10d\n",i,lgths[i]);
		}
	}
	printf("No. numbers: %d\n",numCount);
	return(1);
}

main()
{  yylex();

}
