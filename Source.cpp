// Data Structure Programs 

#include <iostream>
#include <conio.h>
#include "myFirstClass.h"
class c {
public:
	int x = 10;
};

using namespace std;

int LinerSearchFcn(int Student_Grades[],int Number, int key)
{
	for (int i = 0; i <= (Number - 1); i++)
		if (key == Student_Grades[i])
			return i;
	
	return -1;
}
int BinarySearchFcn(int Student_Grades[],int Low,int High, int key)
{
	int middle = 0;
	if (Low <= High)
	{
		middle = Low + (High - Low) / 2;
		if (key == Student_Grades[middle])	
			return middle;
		if (key < Student_Grades[middle])	
			return BinarySearchFcn(Student_Grades, Low, middle - 1,key);
		if (key > Student_Grades[middle])	
			return BinarySearchFcn(Student_Grades, middle + 1, High, key);	
	}
	return -1;
}
int InerativeBinarySearchFcn(int Student_Grades[],int Low, int High, int key )
{
	int middle;
	while (Low <= High)
	{
		middle = Low + (High - Low) / 2;
		if (key == Student_Grades[middle]) return middle;
		if (key > Student_Grades[middle]) Low = middle + 1;
		else High = middle - 1;
	}
	return -1;
}
int DeleteElementFcn(int Student_Grades[],int Number, int key )
{
	int Position = 0;
	Position = BinarySearchFcn(Student_Grades,0,Number-1,key);
	if (Position == -1)
	{
		cout << "Not Found!";
		return Number;
	}
	for (int i = Position; i < Number - 2; i++)
		Student_Grades[i] = Student_Grades[i + 1];

	return Number - 1;
		

}
int UnSortInsertElementFcn(int Student_Grades[],int key, int Number, int Capacity)
{
	if (Number >= Capacity)
		return Number; 

	Student_Grades[Number] = key;
	return (Number+1);
}
int SortInsertElementFcn(int Student_Grades[],int key , int Number, int Capacity )
{
	if (Number >= Capacity)
		return Number; 
	int i = 0;
	for ( i = Number - 1; (i >= 0 && Student_Grades[i] > key); i--)
		Student_Grades[i + 1] = Student_Grades[i];

	Student_Grades[i + 1] = key;
	return (Number + 1); 
}
void main()
{
	int Student_Grades[10] = { 6,8,9,12,16,18,19,20 };
	int Capacity = sizeof(Student_Grades) / sizeof(Student_Grades[0]);
	int Number = 8;
	int key = 3;
	//int Position = 0;
	//Number = DeleteElementFcn(Student_Grades,Number,key);
	//Number = SortInsertElementFcn(Student_Grades, key, Number, Capacity);
	//for (int i = 0; i < Number; i++)
		//cout << Student_Grades[i]<<"\t";


	//Position = BinarySearchFcn(Student_Grades, 0, Number - 1, key);
	//Position= LinerSearchFcn(Student_Grades,Number,key);
	/*Position = InerativeBinarySearchFcn(Student_Grades, 0, Number - 1, key);
	if (Position == -1)
		cout << "Not Find!" << endl;
	else
		cout << Position << endl;*/
	
	
	_getch();
}