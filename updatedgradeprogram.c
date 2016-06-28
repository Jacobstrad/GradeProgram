#include <stdio.h>
#include <stdbool.h>
#define ERROR 1
	// function prototypes
	int pointscalculator(char);
	int examgradepoints(char);
	int neededpointscalc(int, char);
	int main(int argc, char *argv)
	{
		char response;
		int i = 1;
		char grade, desiredgrade;
		int globalpoints = 0;
		int flag = 0;
		int neededpoints;
		char examgrade; //only applicable if in third or fourth quarter
		printf("Where are you in the year?\n");
		printf("a. Currently in first quarter.\n");
		printf("b. Currently in second quarter.\n");
		printf("c. Currently in third quarter.\n");
		printf("d. Currently in fourth quarter.\n");
		
		// while loop to account for a possible invalid input, the default case will reset the loop
		while(true)
		{		
			response = getchar();
			switch(response)
			{
				case 'a':
					while(i <= 1)
					{
						printf("Quarter %d Grade: ", i);
						scanf(" %c", &grade);
						if(pointscalculator(grade) == ERROR) // error checking
						{
							puts("Invalid input\n");
							continue; 
						}
						globalpoints += pointscalculator(grade);
						break;
					}
						break;
				case 'b':
					while(i < 2)
					{
						printf("Quarter %d Grade: ", i);
						scanf(" %c", &grade);
						if(pointscalculator(grade) == ERROR) 
						{
							puts("Invalid input\n");
							continue;
						}
						globalpoints += pointscalculator(grade);
						i++;
					}
						break;
				case 'c':
					while(i < 3)
					{
						printf("Quarter %d Grade: ", i);
						scanf(" %c", &grade);
						if(pointscalculator(grade) == ERROR)
						{
							puts("Invalid input\n");
							continue;
						}
						globalpoints += pointscalculator(grade);
						i++;
					}
						while(true)
						{
							puts("Midterm Grade:\n");
							scanf(" %c", &examgrade);
							if(examgradepoints(examgrade) == ERROR)
							{
								puts("Invalid Input\n");
								continue;
							}
							globalpoints += examgradepoints(examgrade);
							break;
						}
						i++;
						break;
				case 'd':
					while(i < 4)
					{
						printf("Quarter %d Grade: ", i);
						scanf(" %c", &grade);
						if(pointscalculator(grade) == ERROR)
						{	
							puts("Invalid input\n");
							continue;
						}
						globalpoints += pointscalculator(grade);
						i++;
					}
						while(true)
						{
							puts("Midterm Grade:\n");
							scanf(" %c", &examgrade);
							if(examgradepoints(examgrade) == ERROR)
							{
								puts("Invalid Input");
								continue;
							}
							globalpoints += examgradepoints(examgrade);
							break;
						}
						break;
				default:
					puts("Please enter a valid letter\n");
					flag = 1; // indicates whether to continue or break the loop
					break;
			}
			if(flag == 1)
			{
				flag = 0;
				continue;
			}
			if(flag == 0)
			{
				break;
			}
		}
		while(true)
		{
			puts("What grade do you want?\n");
			scanf(" %c", &desiredgrade);
			if(neededpointscalc(globalpoints, desiredgrade) == ERROR) // error checking
			{
				puts("Invalid input\n");
				continue;
			}
			neededpoints = neededpointscalc(globalpoints, desiredgrade);	
			break;
		}
		// was going to take the time to print out every possible grade combination, but figured that would not be worth it
		printf("You need %d points to achieve your goal\n", neededpoints);
		puts("If you are unaware how many points each grade is worth, it is as follows:\n");
		puts("Quarter Grades:\n");
		puts("A - 8 points\n");
		puts("B - 6 points\n");
		puts("C - 4 points\n");
		puts("D - 2 points\n");
		puts("E - 0 points\n");
		puts("For exams just half the points earned for quarters... so an A is 4, a B is 3, etc.");
		return 0;
	}

	int pointscalculator(char grade) 
	{
		int points = 0;
		int errorflag = 0;
		switch(grade)
		{
			case  'a':
				points += 8;
				break;	
			case  'b':
				points += 6;
				break;
			case  'c':
				points += 4;
				break;
			case  'd':
				points += 2;
				break;
			case  'e':
				points += 0;
				break;
			default:
				errorflag = 1;
		}
		if(errorflag == 1)
		{
			return ERROR;
		}
		if(errorflag == 0)
		{
			return points;
		}
	}
	
	int neededpointscalc(int globalpoints, char desiredgrade)
	{
		int finalpoints, localneededpoints;
		int errorflag = 0;
		switch(desiredgrade)
		{
			case 'a':
				finalpoints = 35;
				localneededpoints = finalpoints - globalpoints;
				break;
			case 'b':
				finalpoints = 25;
				localneededpoints = finalpoints - globalpoints;
				break;
			case 'c':
				finalpoints = 15;
				localneededpoints = finalpoints - globalpoints;
				break;
			case 'd':
				finalpoints = 5;
				localneededpoints = finalpoints - globalpoints;
				break;
			case 'e':
				localneededpoints = 0;
			default:
				errorflag = 1;
		}
		if(errorflag == 1)
		{
			errorflag == 0;
			return ERROR;
		}
		if(errorflag == 0)
		{
			return localneededpoints;
		}	
	}
	
	int examgradepoints(char examgrade)
	{
		int points = 0;
		int errorflag = 0;
		switch(examgrade)
		{
			case 'a':
				points += 4;
				break;
			case 'b':
				points += 3;
				break;
			case 'c':
				points += 2;
				break;
			case 'd':
				points += 1;	
				break;	
			case 'e':	
				points += 0;
				break;
			default:
				errorflag = 1;
		}
		if(errorflag == 1)
		{
			errorflag = 0;
			return ERROR;
		}
		if(errorflag == 0);
		{
			return points;
		}
	}

	
