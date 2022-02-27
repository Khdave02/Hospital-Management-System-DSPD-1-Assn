#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
int j = 0;

struct patient
{
	int PatientNumber;
	int age;
	char gender[9];
	char FirstName[20];
	char LastName[20];
	char PhoneNumber[10];
	char ResidentialCity[15];
	char Email[30];
	char Doctor[20];
	char Problem[30];
	int ServiceType;

	struct charges
	{
		char TotalCharge[15];
		char TotalDeposited[15];
		char TotalReturn[15];
	} amount_DB;
};
struct patient pat_records[SIZE];
void merge(struct patient pat_records[], int low, int mid, int high)
{
	int i;
	int left_index = low;
	int right_index = mid + 1;
	int combined_index = low;
	struct patient tempA[SIZE];

	while (left_index <= mid && right_index <= high)
	{
		if (pat_records[left_index].ServiceType <= pat_records[right_index].ServiceType)
		{
			tempA[combined_index++] = pat_records[left_index++];
		}
		else
		{
			tempA[combined_index++] = pat_records[right_index++];
		}
	}

	if (left_index == mid + 1)
	{
		while (right_index <= high)
		{
			tempA[combined_index++] = pat_records[right_index++];
		}
	}
	else
	{
		while (left_index <= mid)
		{
			tempA[combined_index++] = pat_records[left_index++];
		}
	}

	for (i = low; i <= high; i++)
	{
		pat_records[i] = tempA[i];
	}
}
void merge_sort(struct patient pat_records[], int low, int high)
{
	int mid = 0;

	if (low == high)
	{
		return;
	}
	else
	{
		mid = (low + high) / 2;

		merge_sort(pat_records, low, mid);

		merge_sort(pat_records, mid + 1, high);

		merge(pat_records, low, mid, high);
	}
}
void merge_alpha(struct patient pat_records[], int low, int mid, int high)
{
	int i;
	int left_index = low;
	int right_index = mid + 1;
	int combined_index = low;
	struct patient tempA[SIZE];

	while (left_index <= mid && right_index <= high)
	{
		if (strcmp(pat_records[left_index].FirstName, pat_records[right_index].FirstName) < 0)
		{
			tempA[combined_index++] = pat_records[left_index++];
		}
		else if (strcmp(pat_records[left_index].FirstName, pat_records[right_index].FirstName) == 0 && strcmp(pat_records[left_index].LastName, pat_records[right_index].LastName) < 0)
		{
			tempA[combined_index++] = pat_records[left_index++];
		}
		else
		{
			tempA[combined_index++] = pat_records[right_index++];
		}
	}

	if (left_index == mid + 1)
	{
		while (right_index <= high)
		{
			tempA[combined_index++] = pat_records[right_index++];
		}
	}
	else
	{
		while (left_index <= mid)
		{
			tempA[combined_index++] = pat_records[left_index++];
		}
	}

	for (i = low; i <= high; i++)
	{
		pat_records[i] = tempA[i];
	}
}
void merge_sort_alpha(struct patient pat_records[], int low, int high)
{
	int mid = 0;

	if (low == high)
	{
		return;
	}
	else
	{
		mid = (low + high) / 2;

		merge_sort_alpha(pat_records, low, mid);

		merge_sort_alpha(pat_records, mid + 1, high);

		merge_alpha(pat_records, low, mid, high);
	}
}
void print_DB(struct patient pat_records[], int i)
{
	printf("Patient Number is %d\n", pat_records[i].PatientNumber);
	printf("Patient age is %d\n", pat_records[i].age);
	printf("Patient gender is %s\n", pat_records[i].gender);
	printf("Patient name is %s %s\n", pat_records[i].FirstName, pat_records[i].LastName);
	printf("Patient phone number is %s\n", pat_records[i].PhoneNumber);
	printf("Patient Residential_city is %s\n", pat_records[i].ResidentialCity);
	printf("Patient email is %s\n", pat_records[i].Email);
	printf("Patient doctor is %s\n", pat_records[i].Doctor);
	printf("Patient problem_type is %s\n", pat_records[i].Problem);
	printf("Patient service_type is %d\n", pat_records[i].ServiceType);
	printf("Patient total charge %s\n", pat_records[i].amount_DB.TotalCharge);
	printf("Patient total deposited %s\n", pat_records[i].amount_DB.TotalDeposited);
	printf("Patient total return %s\n", pat_records[i].amount_DB.TotalReturn);
}
int add(struct patient pat_records[], int j)
{
	if (j == SIZE)
	{
		printf("record is full\n");
	}
	else
	{

		printf("enter patient number age,gender\n");
		scanf("%d %d %s", &pat_records[j].PatientNumber, &pat_records[j].age, &pat_records[j].gender);
		printf("enter first name , last name , phone number\n ");
		scanf("%s %s %s", &pat_records[j].FirstName, &pat_records[j].LastName, &pat_records[j].PhoneNumber);
		printf("Residential city, email,Doctor,Problem,Service number\n ");
		scanf("%s %s %s %s %d", &pat_records[j].ResidentialCity, &pat_records[j].Email, &pat_records[j].Doctor, pat_records[j].Problem, &pat_records[j].ServiceType);
		printf("enter total charge total return total deposited\n");
		scanf("%s %s %s", &pat_records[j].amount_DB.TotalCharge, &pat_records[j].amount_DB.TotalDeposited, &pat_records[j].amount_DB.TotalReturn);
		merge_sort(pat_records, 0, j);
		j++;
	}
	return j;
}
int delete(struct patient pat_records[], int id_number, int j)
{

	int i = 0, found = 0;

	while (i < j && !found)
	{
		if (pat_records[i].PatientNumber == id_number)
		{
			int t = i;
			found = 1;
			while (t < j)
			{

				pat_records[t].PatientNumber = pat_records[t + 1].PatientNumber;
				pat_records[t].age = pat_records[t + 1].age;
				pat_records[t].ServiceType = pat_records[t + 1].ServiceType;
				strcpy(pat_records[t].gender, pat_records[t + 1].gender);
				strcpy(pat_records[t].FirstName, pat_records[t + 1].FirstName);
				strcpy(pat_records[t].LastName, pat_records[t + 1].LastName);
				strcpy(pat_records[t].PhoneNumber, pat_records[t + 1].PhoneNumber);
				strcpy(pat_records[t].ResidentialCity, pat_records[t + 1].ResidentialCity);
				strcpy(pat_records[t].Email, pat_records[t + 1].Email);
				strcpy(pat_records[t].Doctor, pat_records[t + 1].Doctor);
				strcpy(pat_records[t].Problem, pat_records[t + 1].Problem);
				strcpy(pat_records[t].amount_DB.TotalCharge, pat_records[t + 1].amount_DB.TotalCharge);
				strcpy(pat_records[t].amount_DB.TotalDeposited, pat_records[t + 1].amount_DB.TotalDeposited);
				strcpy(pat_records[t].amount_DB.TotalReturn, pat_records[t + 1].amount_DB.TotalReturn);
				t++;
			}
			j--;
			printf("deleted successfully\n");
		}
		i++;
	}
	if (found == 0)
	{
		printf("Not Found\n");
	}
	return j;
}
void search_pat(int pat_no, char pat_Fname[], char pat_Lname[], struct patient pat_records[])
{
	int found = 0, i = 0;
	while (i < SIZE && !found)
	{
		if (strcmp(pat_Fname, pat_records[i].FirstName) == 0 && strcmp(pat_Lname, pat_records[i].LastName) == 0 || pat_no == pat_records[i].PatientNumber)
		{
			found = 1;
			printf("Name of Patient %s %s\n", pat_records[i].FirstName, pat_records[i].LastName);
			printf("Phone Number is %s , Email is %s , ResidentialCity is %s\n", pat_records[i].PhoneNumber, pat_records[i].Email, pat_records[i].ResidentialCity);
			printf("Doctor is %s , Problem is %s , ServiceType is %d\n", pat_records[i].Doctor, pat_records[i].Problem, pat_records[i].ServiceType);
			printf("Total charge is %s , Total deposited ammount is %s , Total Returned amount is %s\n", pat_records[i].amount_DB.TotalCharge, pat_records[i].amount_DB.TotalDeposited, pat_records[i].amount_DB.TotalReturn);
		}
		i++;
	}
	if (found == 0)
	{
		printf("sorry patient is not found\n");
	}
}
void edit_DB(struct patient pat_records[], char F_name[], char L_name[], int pat_no, int j)
{

	int found = 0;
	int i = 0;
	while (i < j && !found)
	{
		if (strcmp(F_name, pat_records[i].FirstName) == 0 && strcmp(L_name, pat_records[i].LastName) == 0 || pat_no == pat_records[i].PatientNumber)
		{

			found = 1;
			int edit_age, id_num;
			char Resi_city[15], phone_num[10], doc[20], email[30], tot_charge[15], prob[30], ser_type, tot_dep[15], tot_ret[15], F_name[20], L_name[20], gen;
			int edit = 1;
			while (edit)
			{
				int num;
				printf("enter 1 for age 2 for phone_num 3 for Residential city 4 for email 5 for doctor and 6 for problem 7 for seviceType\n");
				printf("enter 8 for totalcharges 9 for totalreturn 10 for totaldeposited 11 for first name 12 for last name 13 for patient number 14 for gender\n");
				scanf("%d", &num);
				switch (num)
				{
				case 1:
					printf("enter new age\n");
					scanf("%d", &pat_records[i].age);

					break;
				case 2:
					printf("enter new phone_num\n");
					scanf("%s", &pat_records[i].PhoneNumber);

					break;
				case 3:
					printf("enter new Resi_city\n");
					scanf("%s", &pat_records[i].ResidentialCity);
					break;
				case 4:
					printf("enter new email\n");
					scanf("%s", &pat_records[i].Email);
					break;
				case 5:
					printf("enter new doctor\n");
					scanf("%s", &pat_records[i].Doctor);
					break;
				case 6:
					printf("enter new problem\n");
					scanf("%s", &pat_records[i].Problem);

					break;
				case 7:
					printf("enter new ser_type\n");
					scanf("%d", &pat_records[i].ServiceType);
					merge_sort(pat_records, 0, j);
					break;
				case 8:
					printf("enter new total charge\n");
					scanf("%d", &pat_records[i].amount_DB.TotalCharge);

					break;
				case 9:
					printf("enter new total returned\n");
					scanf("%d", &pat_records[i].amount_DB.TotalReturn);

					break;

				case 10:
					printf("enter new total deposited\n");
					scanf("%d", &pat_records[i].amount_DB.TotalDeposited);

					break;
				case 11:
					printf("enter new FirstName\n");
					scanf("%s", &pat_records[i].FirstName);

					break;
				case 12:
					printf("enter new LastName\n");
					scanf("%s", &pat_records[i].LastName);

					break;
				case 13:
					printf("enter new Patient Number\n");
					scanf("%d", &pat_records[i].PatientNumber);

					break;

				default:
					printf("invalid input\n");
					break;
				}
				printf("Enter 1 to edit again and 0 for not\n");

				scanf("%d", &edit);
			}
		}
		i++;
	}
	if (found == 0)
	{
		printf("record not found\n");
	}
}
void list_pat(struct patient pat_records[], int j)
{
	printf("enter 1 for list in patients_name in alphabetical order, 2 for emergency patients_list, 3 for records of opd patients\n");
	int n, i = 0;
	scanf("%d", &n);

	switch (n)
	{
	case 1:
		merge_sort_alpha(pat_records, 0, j - 1);
		for (int i = 0; i < j; i++)
		{
			print_DB(pat_records, i);
		}
		merge_sort(pat_records, 0, j - 1);

	case 2:
		while (i < j)
		{
			if (pat_records[i].ServiceType == 0)
			{
				print_DB(pat_records, i);
			}
			i++;
		}
		break;
	case 3:

		while (i < j)
		{
			if (pat_records[i].ServiceType == 1 && pat_records[i].PatientNumber != 0)
			{
				print_DB(pat_records, i);
			}
			i++;
		}
		break;
	default:
		break;
	}
}
void print_outsider_data(struct patient pat_records[], int j)
{
	int i = 0;
	while (i < j)
	{
		if (strcmp(pat_records[i].ResidentialCity, "NAGPUR") != 0)
		{
			print_DB(pat_records, i);
		}
		i++;
	}
}
void max_min_charge(struct patient pat_records[], int j)
{
	int i = 0, max_index = 0, min_index = 0, max = 0, min = atoi(pat_records[1].amount_DB.TotalCharge);
	while (i < j)
	{
		if (atoi(pat_records[i].amount_DB.TotalCharge) > max && pat_records[i].PatientNumber)
		{
			max = atoi(pat_records[i].amount_DB.TotalCharge);
		}
		if (atoi(pat_records[i].amount_DB.TotalCharge) < min && pat_records[i].PatientNumber)
		{
			min = atoi(pat_records[i].amount_DB.TotalCharge);
		}
		i++;
	}
	i = 0;
	while (i < j)
	{

		if (atoi(pat_records[i].amount_DB.TotalCharge) == max)
		{
			printf("Maximum charged patients are\n");
			print_DB(pat_records, i);
		}

		if (atoi(pat_records[i].amount_DB.TotalCharge) == min)
		{
			printf("Minimum charged patients are\n");
			print_DB(pat_records, i);
		}
		i++;
	}
}
void funds_return_data(struct patient pat_records[])
{
	int i = 0;
	while (i < j)
	{
		if (atoi(pat_records[i].amount_DB.TotalReturn) > 0)
		{
			print_DB(pat_records, i);
		}
		i++;
	}
}
void search_pat_by_age(struct patient pat_records[], int age, int j)
{
	int i = 0, found = 0;
	while (i < j)
	{
		if (pat_records[i].age == age)
		{
			print_DB(pat_records, i);
			found = 1;
		}

		i++;
	}
	if (found == 0)
	{
		printf("No patient found for that age\n");
	}
}
void list_doc(struct patient pat_records[], int j)
{
	int i = 0, k = 0, n = 0, found = 0, m = 0, b = 0;
	char pat_0[j][20], pat_01[j][20], pat_1[j][20];
	while (i < j)
	{
		if (pat_records[i].ServiceType == 0)
		{
			found = 0;
			k = 0;
			while (k < n)
			{
				if (strcmp(pat_records[i].Doctor, pat_0[k]) == 0)
				{
					found = 1;
				}
				k++;
			}
			if (found == 0)
			{
				strcpy(pat_0[n], pat_records[i].Doctor);
				n++;
				if (pat_records[i].ServiceType == 1)
				{
					strcpy(pat_01[m], pat_records[i].Doctor);
					m++;
				}
			}
		}
		else
		{
			found = 0;
			k = 0;
			while (k < b)
			{
				if (strcmp(pat_records[i].Doctor, pat_1[k]) == 0)
				{
					found = 1;
				}
				k++;
			}
			if (found == 0)
			{
				strcpy(pat_1[b], pat_records[i].Doctor);
				b++;
			}
		}
		i++;
	}
	printf("doctors treating opd patients");
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", pat_0[i]);
	}
	printf("doctors treating both opd and emergency patients");
	for (int i = 0; i < m; i++)
	{
		printf("%s\n", pat_01[i]);
	}
	printf("doctors treating emergency patients");
	for (int i = 0; i < b; i++)
	{
		printf("%s\n", pat_1[i]);
	}
}

int main()
{
	FILE *fp = fopen("ass1.txt", "r");
	char c;

	if (fp != NULL)
	{

		while (fgetc(fp) != EOF && fgetc(fp) != ' ')
		{
			fscanf(fp, "%d", &pat_records[j].PatientNumber);
			if (pat_records[j].PatientNumber != 0)
			{
				c = fgetc(fp);
				fscanf(fp, "%d", &pat_records[j].age);
				c = fgetc(fp);
				fscanf(fp, "%s", &pat_records[j].gender);
				c = fgetc(fp);
				fscanf(fp, "%s", &pat_records[j].FirstName);
				c = fgetc(fp);
				fscanf(fp, "%s", &pat_records[j].LastName);
				c = fgetc(fp);
				fscanf(fp, "%s", &pat_records[j].PhoneNumber);
				c = fgetc(fp);
				fscanf(fp, "%s", &pat_records[j].ResidentialCity);
				c = fgetc(fp);
				fscanf(fp, "%s", pat_records[j].Email);
				c = fgetc(fp);
				fscanf(fp, "%s", &pat_records[j].Doctor);
				c = fgetc(fp);
				fscanf(fp, "%s", &pat_records[j].Problem);
				c = fgetc(fp);
				fscanf(fp, "%d", &pat_records[j].ServiceType);
				c = fgetc(fp);
				fscanf(fp, "%s", &pat_records[j].amount_DB.TotalCharge);
				c = fgetc(fp);
				fscanf(fp, "%s", &pat_records[j].amount_DB.TotalDeposited);
				c = fgetc(fp);
				fscanf(fp, "%s", &pat_records[j].amount_DB.TotalReturn);
				j += 1;
			}
		}
	}

	char f_name[20], l_name[20];
	int p_num, age, process = 1;
	while (process)
	{
		int a;
		printf("enter 1 to add record 2 to search patient 3 to delete 4 to edit 5 to list patient 6 print outsider data 6 to print max min charge 7 to print min - max charge 8 to print return data 9 to print patient age wise 10 to view doctors by service 11 to print all patients\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			j = add(pat_records, j);
			break;
		case 2:
			printf("enter patient number , first name second name\n");
			scanf("%d %s %s", &p_num, &f_name, &l_name);
			search_pat(p_num, f_name, l_name, pat_records);
			break;
		case 3:
			printf("enter patient number u want to delete\n");
			scanf("%d", &p_num);
			delete (pat_records, p_num, j);
			break;
		case 4:
			printf("enter patient number , first name second name\n");
			scanf("%d %s %s", &p_num, &f_name, &l_name);
			edit_DB(pat_records, f_name, l_name, p_num, j);
			break;
		case 5:
			list_pat(pat_records, j);
			break;
		case 6:
			print_outsider_data(pat_records, j);
			break;
		case 7:
			max_min_charge(pat_records, j);
			break;
		case 8:
			funds_return_data(pat_records);
			break;
		case 9:
			printf("enter age of patient\n");
			scanf("%d", &age);
			search_pat_by_age(pat_records, age, j);
			break;
		case 10:
			list_doc(pat_records, j);
			break;
		case 11:
			for (int i = 0; i < j; i++)
			{
				print_DB(pat_records, i);
			}
			break;
		default:
			break;
		}
		printf("enter 1 to continue process 0 to exit the process\n");
		scanf("%d", &process);
	}

	fp = fopen("ass1.txt", "w");

	for (int i = 0; i < j; i++)
	{
		fprintf(fp, "\n\t%d\n", pat_records[i].PatientNumber);
		fprintf(fp, "%d\n", pat_records[i].age);
		fprintf(fp, "%s\n", pat_records[i].gender);
		fprintf(fp, "%s\n", pat_records[i].FirstName);
		fprintf(fp, "%s\n", pat_records[i].LastName);
		fprintf(fp, "%s\n", pat_records[i].PhoneNumber);
		fprintf(fp, "%s\n", pat_records[i].ResidentialCity);
		fprintf(fp, "%s\n", pat_records[i].Email);
		fprintf(fp, "%s\n", pat_records[i].Doctor);
		fprintf(fp, "%s\n", pat_records[i].Problem);
		fprintf(fp, "%d\n", pat_records[i].ServiceType);
		fprintf(fp, "%s\n", pat_records[i].amount_DB.TotalCharge);
		fprintf(fp, "%s\n", pat_records[i].amount_DB.TotalDeposited);
		fprintf(fp, "%s\n", pat_records[i].amount_DB.TotalReturn);
	}
	fclose(fp);

	return 0;
}