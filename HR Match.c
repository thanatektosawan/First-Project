#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int menu(int sel);
int menu_emp(int sel_emp);
int menu_1(int sel_1);
int menu_emp_1(int sel_emp_1);
int menu_job(int sel_job);
int menu_job_1(int sel_job_1);
void employer();
void job_seeker();
void exit_program();
void post_req_emp();
void view_emp();
void edit_emp();
void view_matched_emp();
void post_req_job();
void view_job();
void edit_job();
void view_matched_job();

int
main(void)
{
	system("COLOR F0");
	int select;

	printf("WELCOME TO THE HUMAN RESOURCES\n");
	printf("    MATCH MAKING SOFTWARE\n\n");
	printf("1. Employer\n\n");
	printf("2. Job Seeker\n\n");
	printf("3. Exit Program\n\n");
	printf("Please select one (enter number): ");
	scanf("%d", &select);

	system("cls");
	menu(select);
	return 0;
}

int menu(int sel)
{
	switch (sel)
	{
	case 1:
		employer();
		break;
	case 2:
		job_seeker();
		break;
	case 3:
		exit_program();
		break;
	default:
		printf("INVALID NUMBER\n");
		printf("PLEASE SELECT AGAIN\n\n");
		menu_1(sel);
	}

	return (sel);
}

int menu_1(int sel_1)	 //When the user entered wrong number
{	 //it will allow the user to enter the number again
	printf("1. Employer\n\n");
	printf("2. Job Seeker\n\n");
	printf("3. Exit Program\n\n");
	printf("Please select one (enter number): ");
	scanf("%d", &sel_1);
	system("cls");
	menu(sel_1);
	return(sel_1);
}

void employer()
{
	int select_emp;
	printf("EMPLOYER\n\n");
	printf("1. Post new job requirements\n");
	printf("2. View profile\n");
	printf("3. Edit profile\n");
	printf("4. View matched job seeker\n");
	printf("5. Return to main menu\n");
	printf("Please select one (enter number): ");
	scanf("%d", &select_emp);
	system("cls");
	menu_emp(select_emp);

}

int menu_emp(int sel_emp)
{
	switch (sel_emp)
	{
	case 1:
		post_req_emp();
		break;
	case 2:
		view_emp();
		break;
	case 3:
		edit_emp();
		break;
	case 4:
		view_matched_emp();
		break;
	case 5:
		main();
		break;
	default:
		printf("INVALID NUMBER\n");
		printf("PLEASE SELECT AGAIN\n\n");
		menu_emp_1(sel_emp);
	}
	return(sel_emp);
}

int menu_emp_1(int sel_emp_1)
{
	printf("1. Post new job requirements\n");
	printf("2. View profile\n");
	printf("3. Edit profile\n");
	printf("4. View matched job seeker\n");
	printf("5. Return to main menu\n");
	printf("Please select one (enter number): ");
	scanf("%d", &sel_emp_1);
	system("cls");
	menu_emp(sel_emp_1);
	return(sel_emp_1);
}
void post_req_emp()
{
	char title[30];
	char loc[30];
	char industry[30];
	char vac[30];
	char work_con[30];
	printf("Please fill in the following\n\n");
	printf("Job Title: ");
	scanf("%s", title);
	printf("Location: ");
	scanf("%s", loc);
	printf("Industry: ");
	scanf("%s", industry);
	printf("Vacancies: ");
	scanf("%s", vac);
	printf("Working Condition: ");
	scanf("%s", work_con);
	FILE *fp;
	fp = fopen("employer.dat", "w");
	if (fp == NULL)
	{
		printf("FILE COULD NOT BE OPENED.\n");
	}
	else
	{
		fprintf(fp, "%s%s%s%s%s", title, loc, industry, vac, work_con);
		fclose(fp);
	}
}

void view_emp()
{
	printf("GG");
}

void edit_emp()
{
	printf("WP");
}

void view_matched_emp()
{
	printf("GGWP");
}

void job_seeker()
{
	int select_job;
	printf("JOB SEEKER\n\n");
	printf("1. Add new requirements\n");
	printf("2. View profile\n");
	printf("3. Edit profile\n");
	printf("4. View matched employer\n");
	printf("5. Return to main menu\n");
	printf("Please select one (enter number): ");
	scanf("%d", &select_job);
	system("cls");
	menu_job(select_job);
}

int menu_job(int sel_job)
{
	switch (sel_job)
	{
	case 1:
		post_req_job();
		break;
	case 2:
		view_job();
		break;
	case 3:
		edit_job();
	case 4:
		view_matched_job();
		break;
	case 5:
		main();
		break;
	default:
		printf("INVALID NUMBER\n");
		printf("PLEASE SELECT AGAIN\n\n");
		menu_job_1(sel_job);
	}
	return(sel_job);
}

int menu_job_1(int sel_job_1)
{
	printf("1. Add new requirements\n");
	printf("2. View profile\n");
	printf("3. Edit profile\n");
	printf("4. View matched employer\n");
	printf("5. Return to main menu\n");
	printf("Please select one (enter number): ");
	scanf("%d", &sel_job_1);
	system("cls");
	menu_job(sel_job_1);
	return(sel_job_1);
}

void post_req_job()
{
	char age[5];
	char contact[30];
	char education[50];
	char experience[30];
	char skills[50];
	printf("Please fill in the following\n\n");
	printf("Age: ");
	scanf("%s", age);
	printf("Contact: ");
	scanf("%s", contact);
	printf("Education: ");
	scanf("%s", education);
	printf("Experience: ");
	scanf("%s", experience);
	printf("Skills: ");
	scanf("%s", skills);
	FILE *fp;
	fp = fopen("job.dat", "w");
		fprintf(fp, "%s\n%s\n%s\n%s\n%s", age, contact, education, experience, skills);
		fclose(fp);

		if (fp == NULL)
		{
			printf("FILE COULD NOT BE OPENED.\n");
		}

}

void view_job()
{
	char display[500];
	int k;
	FILE *view_job;
	view_job = fopen("job.dat", "r");
	k = fscanf(view_job, "%s", &display);
	while (k != EOF)
	{

		printf("%s\n", display);
		k = fscanf(view_job, "%s", &display);


	}
	fclose(view_job);
}

void edit_job()
{
	printf("1");
}

void view_matched_job()
{
	printf("2");
}

void exit_program()
{
	printf("\nThank you for using 'name' program\n\n");
	exit(0);
}
