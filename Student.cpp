/*
Mohammad Naseri 9602813
Student Class 
Purpose is to creat 2 classes that one is course and the other is student witch every student can take courses or deleting them from their 
list of courses . both student and course class have name id and some other properthies .
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Sum(vector<Course> crs) { //Just for Student total count of course credits
	int S = 0;
	for (int i = 0; i < crs.size(); i++) {
		S += crs[i].getCredit();
	}
	return S;
}
//==========================================================================
class Course
{
public:
	Course();
	~Course();
	friend class Student;
	friend istream& operator >> (istream& input, Course& crs);
	friend ostream& operator<<(ostream& output, Course& crs);

	void setGrade(int g) {
		this->grade = g;
	}
	int getGrade() {
		return this->grade;
	}
	int getCredit() {
		return this->Credit;
	}
	int getCapacity() {
		return Capacity;
	}
private:
	string Name;
	int Credit;
	double ID;
	int Capacity;
	int grade;

};


istream& operator >> (istream& input, Course& crs) {
	cout << "Plz Enter Course Name : " << endl;
	input >> crs.Name;
	cout << "Plz Enter Course ID : " << endl;
	input >> crs.ID;
	cout << "Plz Enter Course Credit : " << endl;
	input >> crs.Credit;
	cout << "Plz Enter Course Capacity : " << endl;
	input >> crs.Capacity;
	return input;
}

ostream& operator<<(ostream& output, Course& crs) {
	output << "Name : " << crs.Name << " | " << "ID : " << crs.ID << " | " << "Credit : " << crs.Credit << " | " << "Capacity : " << crs.Capacity << endl;
	return output;
}


//----------------------------------------------------------- 

class Student
{
public:
	Student();
	~Student();
	friend istream& operator >> (istream& input, Student& std);
	friend ostream& operator<<(ostream& output, Student& std);

	void showAllCourses() {
		for (int i = 0; i < Courses.size(); i++) {
			cout << Courses[i];
		}
	}
	//add a course to student course list
	void getCourse(Course crs) {
		if (crs.Capacity == 0) { //check the capacity 
			cout << "Capacity For This Course is Full! " << endl;
		}
		else
		{
			Courses.push_back(crs);
			crs.Capacity--; //capacity should decrease by 1
		}
		
	}
	//delete course from student's course list
	void deleteCourse(Course crs) {
		for (int i = 0; i < Courses.size(); i++) {
			if (Courses[i].ID == crs.ID) {
				Courses.erase(Courses.begin() + i);
				crs.Capacity++; //capacity should increase by 1
			}
		}
	}
	//set grades for each course that student has
	void setGrades() {
		int g;
		for (int i = 0; i < Courses.size(); i++) {
			cout << "PLz Enter Mark For " << Courses[i].Name << " : " << endl;
			cin >> g;
			Courses[i].setGrade(g);
		}
	 }
	//get all grades in courses that student has
	void getGrades() {
		for (int i = 0; i < Courses.size(); i++) {
			cout << Courses[i].getGrade;
		}
	}
	//get count of course credits of student
	int getCourseCredits() {
		return CourseCredits;
	}
private:
	double ID;
	string Name;
	int Term;
	vector<Course> Courses;
	int CourseCredits = Sum(Courses);

};


istream& operator >> (istream& input, Student& std) {
	cout << "Plz Enter Student Name : " << endl;
	input >> std.Name;
	cout << "Plz Enter Student ID : " << endl;
	input >> std.ID;

	return input;
}

ostream& operator<<(ostream& output, Student& std) {
	output << "Name : " << std.Name << " | " << "ID : " << std.ID << endl;
	return output;
}


//---------------------------------------------




int main() {
	vector<Course> AllCourses;
	vector<Student> AllStudents;
	int count;
	cout << "Plz Enter Number of Courses : " << endl;
	cin >> count;
	for (int i = 0; i < count; i++) {
		Course crs;
		cin >> crs;
		AllCourses.push_back(crs);
	}
	cout << "Plz Enter Number of Students : " << endl;
	cin >> count;
	for (int i = 0; i < count; i++) {
		Student s;
		cin >> s;
		AllStudents.push_back(s);

	}
	//and the rest should be students taking or deleting courses ...
}