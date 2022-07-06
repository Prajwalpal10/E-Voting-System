#include<stdlib.h>
#include<stdio.h>
#include<string.h>


void printMessageCenter(const char* message)
{
    int len =0; 
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
    	  	
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}


void headMessage(const char *message)
{
    system("cls");
    printf("\t\t\t*****************************************************************************");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                Voting Machine                     ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t-----------------------------------------------------------------------------");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}

void welcomeMessage()
{
    headMessage("Welcome to The Election");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  *------------------*\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                ELECTRONIC                 =");
    printf("\n\t\t\t        =                  VOTING                   =");
    printf("\n\t\t\t        =                 MACHINE                   =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  *------------------*\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");

}

void main()
{

    char username[15];
    char password[12];


    printf("Enter your username:\n");
    scanf("%s",&username);

    printf("Enter your password:\n");
    scanf("%s",&password);

    if(strcmp(username,"GRP9")==0)
	{
        if(strcmp(password,"MCA_FY")==0)
	 {

        printf("\nWelcome.Login Success!");
        welcomeMessage();
        int n,n1,n3,n4,n5,maxi,sum,pos,flag,k=0,co=0,br=0,flag1=0;
        char filename[10];
        char st[100][100],vote[100][100];
        char sy[100],cp[20],t[100];
        int count[100]={0};char n2,a;
        printf("\n          ..................... WELCOME TO CLAIM YOUR RIGHT TO VOTE ......................\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n\n\n");
        sleep(3);
        headMessage("CANDIDATES");
	        do{
	        	 printf("\nEnter the number of candidates participating in the election :\n");//entering candidate details
	       		 scanf("%d",&n5);
	       		 if(n5<=1)
					{
	        			printf("\n\t!! Election Not Possible For Single Candidate !!\n");	
					}
			}while(n5<=1);
			
		
        int i = 0,j;
    
        while(i<n5)
        {
            int temp=0;
            printf("\n\n\n");
            printf("==========for %d candidate=========\n",i+1);
            printf("\n\n");
            printf("Enter the Name of the candidate : \n");
            scanf("%s",st[i]);
            //gets(st);
            printf("\nEnter the Symbol of the candidate :\n");
            scanf(" %c",&a);
            for(j = 0; j<i; j++)
             {
                if(sy[j] == a)
                {
                    printf("\n\aThe symbol is already taken.\n\n");
                    printf("Please re-enter the details of the candidate.\n");
                    temp = 1;
                    break;
                }
             }
            if (temp == 0)
            {
                sy[i] = a;
                i++;
            }
       }
       
        printf("\n\n\n");
        printf("Enter 1 to vote or any other key to exit the poll :\n");
        scanf("%d",&n1);
        if(n1!=1)
            exit(1);
            
        NextVote:
        	
        while(n1==1)
        {
			printf("\n\n\n");printf("\n\n\n");
            printf("Press enter to continue....\n");
             
            
            	
            char *data =  malloc(sizeof(char) * 8);
            label:
            headMessage("VOTER DETAILS");
            printf("\nEnter your voter ID\n");
            scanf("%s",data);
            
            strcpy(vote[k],data);
            k++;

            if(strcmp(t,data)==0)
                co=-1;

            for(i=0;i<k+1;i++)
            {
                if(strcmp(data,vote[i])==0)
                      co++;
          			
            }
            if(co==1)
                flag=0;
            else
                {flag=1;
	                co=0;
	               	printf("\a\a\a\a\aError!!!! \nYou already casted your vote ||\n Or\nYou Are Not Registered ");printf("\n\n\n");
					sleep(2);
					goto label;
			     }
				    				
                
        if(flag==0)
        {

            FILE *fp = fopen("voters.csv", "r");

            if (!fp)
			 {
                printf("Voter List is Not Present. First Add Voter List And Try Again!!\n");
                break;

             }


            char buf[1024];
            int field_count = 0;

            int entries = 0;
            fgets(buf, 1024, fp);
            char *field = strtok(buf, ",");
            while(fgets(buf, 1024, fp))
            {   field_count = 0;
                field = strtok(buf, ",");
                if(strcmp(field,data) == 0 )
                {
                    while(field)
					{
                        if (field_count == 0) 
						{
                            printf("\nVOTER ID:\t");
                        }
                        if (field_count == 1) 
						{
                            printf("AGE:\t");
                        }
                        if (field_count == 2) 
						{
                            printf("NAME:\t");
                        }
                        if (field_count == 3)
						 {
                            printf("PLACE:\t");
                        }

                        printf("%s\n", field);
                        field = strtok(NULL, ",");

                        field_count++;
                    }
                    printf("\n");
                }  
				
           }
			

            fclose(fp);


            printf("\n\n\n");printf("\n\n\n");
            printf("Press any key to continue......\n");
            getch();


        printf("Cast your vote by selecting the symbol of your representative\n");
                headMessage("CASTING THE VOTE");
                printf("\n");printf("\n");printf("\n");
                printf("Enter the symbol of your Representative :\n");
                for(i=0;i<n5;i++)
                {
                    printf("%d.  %s (%c)\n",i+1,st[i],sy[i]);
                }
                    int fl=0;
                    scanf(" %c",&n2);
                    for(i=0;i<n5;i++)
                    {																																																																																																																																																													
	                    if(n2==sy[i])
	                        {
								fl=1;
	                        	break;
	                        }
	                    else
	                        fl=0;
                    }
                    if(fl==1)
                    {
                    	for(i=0;i<n5;i++)
                    	{
                   			 if(n2==sy[i])
                       			 count[i]++;
	                     }
						sleep(3);
	                    printf("\aThank You ! Your vote has been casted.\n");printf("\n\n\n");printf("\n\n\n");
	                    sleep(3);
						printf("Press any key to continue\n");
                    }
                    else{

                        strcpy(t,data);
                        printf("\n\n\n");
                        printf("\aWrong symbol is entered. Enter the correct symbol\n");
                        printf("The details are to be re-entered.\n");
                        printf("\n\n\n");
                        printf("Press any key to continue\n");

                        continue;
                    }

          headMessage("MENU");

          while(n1==1)
           {
             printf("\n");printf("\n");printf("\n");

             printf("Enter your choice \n1.  Results\n2.  Difference between the votes of any two candidates\n3.Finish your voting\n4.  EXIT the Poll\n  ");
             scanf("%d",&n);
				switch(n)
				{
					
					case 1:
					{
						headMessage("Results");
                    	printf("\n\n\n");
                   		printf("The Result according to votes casted so far is as follows : \n");
                   		printf("\n");printf("\n");printf("\n");
                    	for(i=0;i<n5;i++)
                    		{
	                     		 printf(" %s( %c):  %d\n",st[i],sy[i],count[i]);
                   			 }
                   		 
						break;
					}
					
					case 2:
					{
						headMessage("Difference");
                    	 printf("\n\n\n");
                    	 for(i=0;i<n5;i++)
               			  {
		                    printf("%d.  %s (%c)\n",i+1,st[i],sy[i]);
                		  }
	                     printf("Enter the serial nos. of whose vote count differences are to be known : \n");
	
	                     scanf("%d%d",&n3,&n4);
	                     if(count[n3-1]==count[n4-1])
	                        printf("It's a Tie between both the candidates'\n");
	                     printf("\n\n\n");
	                     printf("The difference between %s and %s is %d",st[n3-1],st[n4-1],count[n3-1]-count[n4-1]);
							break;
					}
						
							
					case 3:
					  {
						goto NextVote;
						break;
				      } 
					case 4:
						{
						  n1=0;
						  break;
					    }
					default : printf("\aWRONG OPTION ENTERED TRY AGAIN");
				}//SWITCH
              
            }//WHILE
       }
        else
            printf("\a\a\a\a\aError!!!! You already casted your vote ");printf("\n\n\n");
            
			printf("press any key to continue\n");
        }
        headMessage(" FINAL RESULTS");
        for(i=0; i<n5; i++)
            {

                
                sprintf(filename, "file%d.txt", i+1);
                FILE * fPtr;

                
                if(fPtr == NULL)
                {
                    printf("Unable to create file.\n");
                    exit(EXIT_FAILURE);
                }

                
                fPtr = fopen(filename, "w");
                printf("\nCandidate : %s",st[i]);

                fprintf(fPtr,"candidate:%s\n",st[i]);

                printf("\t Symbol : %c",sy[i]);
                fprintf(fPtr,"symbol:%c\n",sy[i]);

                printf("\t Votes : %d\n",count[i]);
                fprintf(fPtr,"votes:%d\n",count[i]);

                
                fclose(fPtr);
            }


        }else{
    printf("\nwrong password\n");
    main();
}
    }else{
    printf("\nUser doesn't exist\n");
    main();
}

}
