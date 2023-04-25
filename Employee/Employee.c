//==============================================
// Name:           George Paul Robert
// Student Number: 117928226
// Email:          grobert1@myseneca.ca
// Workshop:       3
//==============================================

//file: Employee.c by George Paul Robert, 117928226

#include <stdio.h>
#include "Employee.h" //incldues the header file Employee.h containing the structure declaration to be used here


const int SIZE = 4; //size of the employees

int main(void)
{
	struct Employee emp[SIZE] = //declaration of the struct employee array and initialising all its elements to zero
		{
			{0, 0, 0.00},
		};

	int option, found = 0, empId, flag = 0;

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		printf("1. Display Employee Information\n");
		printf("2. Add Employee \n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n");
		printf("Please select from the above options: 5\n");

		scanf("%d", &option); //user input to select the option

		switch (option)
		{
		case 0:	// Exit the program

			break;

		case 1: // Display Employee Data

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (int i = 0; i < SIZE; i++){
				if (emp[i].id != 0){ //print the data if the id is not empty
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
				}
			}

				break;

		case 2:	// Adding Employee

			printf("Adding Employee\n");
			printf("===============\n");
			found = 0; //flag to check if empty element is found before the end of the array so as to not go through the entire array
			for (int i = 0; i < SIZE && found == 0; i++){
				if(emp[i].id == 0){ //condition to check empty element
					found = 1; //flag updated to stop the iteration
					printf("Enter Employee ID: "); 
					scanf("%d", &emp[i].id);
					printf("Enter Employee Age: ");
					scanf("%d", &emp[i].age);
					printf("Enter Employee Salary: ");
					scanf("%lf", &emp[i].salary);
				}
				if(i == (SIZE - 1) && found == 0){
					printf("ERROR!!! Maximum Number of Employees Reached\n\n"); //when the end of the array is reached and no empty space is found
				}
			}
			

			break;

		case 3: //Update Employee salary
			printf("Update Employee Salary\n");
			printf("======================\n");
			flag = 0; //if the employee id is found it is set to 1 therby stopping the do while loop. Otherwise the user is re-prompted to enter the id
			found = 0;

			do{
				printf("Enter Employee ID :");
				scanf("%d", &empId);

				for (int i = 0; i < SIZE && found == 0; i++){
					if(empId == emp[i].id){
						found = 1;
						printf("The current Salary is: %11.2lf \n", emp[i].salary);
						printf("Enter Employee new salary: ");
						scanf("%lf", &emp[i].salary);
						flag = 1;
					}
					if(i == (SIZE-1) && found == 0){
						printf("*** ERROR: Employee ID not found! ***\n");
						flag = 0;
					}
				}
			}while (flag == 0);

			break;

		case 4: //Remove Employee
			printf("Remove Employee\n");
			printf("===============\n");
			flag = 0;
			found = 0;

			do{
				printf("Enter Employee ID :");
				scanf("%d", &empId);

				for (int i = 0; i < SIZE && found == 0; i++){
					if(empId == emp[i].id){
						found = 1;
						printf("Employee %d will be removed\n", emp[i].id);
						emp[i].id = 0; //employee removed by setting the id ie. unique identifer to 0
						flag = 1;
					}
					if(i == (SIZE-1) && found == 0){
						printf("*** ERROR: Employee ID not found! ***\n");
						flag = 0;
					}
				}
			}while (flag == 0);

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0); // checking for exit option and continues as long as option isnt 0;
	printf("Exiting Employee Data Program. Good Bye!!!\n");

	return 0;
}
