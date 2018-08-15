#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

//Number of symbol table entries
int size = 0;

//Function Declarations:
void Insert();
void Display();
int Search(char lab[]);
void Modify();
void Delete();

//Node for each linked list item in the symbol table
struct SymbTab {
     char label[10], symbol[10];
     int addr;
     struct SymbTab *next;
};
//Linked list entry points
struct SymbTab *first, *last;

/*
 * Main Function:
 * Ouputs a menu to the screen
 *   (1) Inserts an item into the symbol table
 *   (2) Displays the symbol table's contents
 *   (3) Deletes an item from the symbol table
 *   (4) Searches for an item in the symbol table
 *   (5) Modifies the contents of an item in the symbol table
 *   (6) Exits the program
 */
void main() {
     int menuOption, y;
     char searchLabel[10];

     //Ouput menu options, using a switch statement to execute code based on the selected option
     do {
          printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
          printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.MODIFY\n\t6.END\n");
          printf("\n\tEnter your option : ");
          scanf("%d",&menuOption);
          switch(menuOption) {
               case 1:
                    //Inserts and item into the symbol table
                    Insert();
                    break;
               case 2:
                    //Displays the contents of the symbol table
                    Display();
                    break;
               case 3:
                    //Deletes an item from the symbol table
                    Delete();
                    break;
               case 4:
                    //Searches for a specific item in the symbol table
                    printf("\n\tEnter the label to be searched : ");
                    scanf("%s",searchLabel);
                    y=Search(searchLabel);
                    printf("\n\tSearch Result:");
                         if(y==1)
                              printf("\n\tThe label is present in the symbol table\n");
                         else
                              printf("\n\tThe label is not present in the symbol table\n");
                         break;
               case 5:
                    //Modifies the contents of an item in the symbol table
                    Modify();
                    break;
               case 6:
                    //Exits the program
                    exit(0);
          }
     }while(menuOption < 6);

}  /* end of main */

/*
 * Insert Function:
 * Reads in a label for the item being inserted into the symbol table
 * Searches the symbol table to see if an item with that label exists already
 * If one does not already exist, a SymbTab struct is created for it, the label is copied in, additional information (symbol & address) is requested and set, and the insert is performed
 */
/**Changes Made Here**/
void Insert(char *symb) {
     int n;
     //Prompt for and store desired item label
     char l[10];
     printf("\n\tEnter the label : ");
     scanf("%s",l);
     //Checks if an item with that label already exists
     n=Search(l);
     if(n==1)
          printf("\n\tThe label exists already in the symbol table\n\tDuplicate can.t be inserted");
     else {
          //Create symbol table struct
          struct SymbTab *p;
          p=malloc(sizeof(struct SymbTab));
          //Copy in label name
          strcpy(p->label,l);
          //Read in and set "symbol"
          printf("\n\tEnter the symbol : ");
          scanf("%s",p->symbol);
          //Read in and set "address"
          printf("\n\tEnter the address : ");
          scanf("%d",&p->addr);
          //Set next pointer to null (end of linked list)
          p->next=NULL;

          //If inserting into an empty table, set it as the only item (first and last)
          if(size==0) {
               first=p;
               last=p;
          }
          //If table already has one or more items, attach it to the last node in the linked list
          else {                              
               last->next=p;
               last=p;
          }
          size++;
     }
     //Alert user that the insert was successful
     printf("\n\tLabel inserted\n");
}

int fetchAddr(char *symb) {
    return Search(symb);
}

/*
 * Display Function:
 * Ouputs the contents of each node item in the symbol table by traversing the linked list and printing all attributes
 */
void Display() {
     //Start at the first element of the linked list
     int i;
     struct SymbTab *p;
     p=first;
     printf("\n\tLABEL\t\tSYMBOL\t\tADDRESS\n");

     //Traverse the linked list, printing each node's label, symbol, and address
     for(i = 0; i < size; i++) {
          printf("\t%s\t\t%s\t\t%d\n",p->label,p->symbol,p->addr);
          p=p->next;
     }
}

/*
 * Search Function:
 * Searches the symbol table for an item with a given label
 * Returns 1 if a match was found, 0 if no match was found
 */
int Search(char lab[]) {
     //Start at the first element of the linked list
     int i, flag = 0;
     struct SymbTab *p;
     p=first;

     //Traverse the linked list, comparing the label being searched to each node's label
     for(i = 0; i < size; i++) {
          if(strcmp(p->label,lab)==0)
          //Matching item has been found!
          flag=1;
          p=p->next;
     }
     /**CHANGE MADE HERE**/
     //Return flag that has the value 1 if a match was found, and a 0 if no match was found
     if(flag == 1)
	return p->addr;
     else
     	return flag;
}

/*
 * Modify Function:
 * 
 */
void Modify() {
     char l[10], nl[10];
     int add,choice,i,s;
     struct SymbTab *p;
     p=first;
     printf("\n\tWhat do you want to modify?\n");
     printf("\n\t1.Only the label\n\t2.Only the address\n\t3.Both the label and address\n");
     printf("\tEnter your choice : ");
     scanf("%d",&choice);

     switch(choice) {
          case 1:
               printf("\n\tEnter the old label : ");
               scanf("%s",l);
               s=Search(l);
               if(s==0)
                    printf("\n\tLabel not found\n");
               else {
                    printf("\n\tEnter the new label : ");
                    scanf("%s",nl);
                    for(i=0;i<size;i++) {
                         if(strcmp(p->label,l)==0)
                         strcpy(p->label,nl);
                         p=p->next;
                    }
                    printf("\n\tAfter Modification:\n");
                    Display();
               }
               break;
          case 2:
               printf("\n\tEnter the label where the address is to be modified : ");
               scanf("%s",l);
               s=Search(l);
               if(s==0)
                    printf("\n\tLabel not found\n");
               else {
                    printf("\n\tEnter the new address : ");
                    scanf("%d",&add);

                    for(i=0;i<size;i++) {
                         if(strcmp(p->label,l)==0)
                         p->addr=add;
                         p=p->next;
                    }
                    printf("\n\tAfter Modification:\n");
                    Display();
               }
               break;
          case 3:
               printf("\n\tEnter the old label : ");
               scanf("%s",l);
               s=Search(l);

               if(s==0)
                    printf("\n\tLabel not found\n");
               else {
                    printf("\n\tEnter the new label : ");
                    scanf("%s",nl);
                    printf("\n\tEnter the new address : ");
                    scanf("%d",&add);
                    
                    for(i=0;i<size;i++) {
                         if(strcmp(p->label,l)==0) {
                              strcpy(p->label,nl);
                              p->addr=add;
                         }
                         p=p->next;
                    }
                    printf("\n\tAfter Modification:\n");
                    Display();
               }
               break;
     }
}

void Delete() {
     int a;
     char l[10];
     struct SymbTab *p,*q;
     p=first;
     printf("\n\tEnter the label to be deleted : ");
     scanf("%s",l);
     a=Search(l);
     
     if(a==0)
          printf("\n\tLabel not found\n");
     else {
          if(strcmp(first->label,l)==0)
               first=first->next;
          else if(strcmp(last->label,l)==0) {
               q=p->next;
               while(strcmp(q->label,l)!=0) {
                    p=p->next;
                    q=q->next;
               }
               p->next=NULL;
               last=p;
          }
          else {
               q=p->next;
               while(strcmp(q->label,l)!=0) {
                    p=p->next;
                    q=q->next;
               }
               p->next=q->next;
          }
          size--;
          printf("\n\tAfter Deletion:\n");
          Display();
     }
}

