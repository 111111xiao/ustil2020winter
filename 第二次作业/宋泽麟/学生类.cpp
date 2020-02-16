#include <iostream>
#include <string>
#define MAX 100
using namespace std;

// 基类
class Student
{
	int id;
	string name;
	static int sum;
	int num;
	double subject[10];
public:
	void input(Student s[], int);
	int change(Student s[], int);
	void print(Student s[], int);
	int avg(Student s[]);
protected:
	
}stu[MAX];

// 派生类
class Score : public Student
{
public:
	
};

void Student::input(Student s[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "输入第" << i + 1 << "个学生的学号：";
		cin >> s[i].id;
		cout << "输入第" << i + 1 << "个学生的姓名：";
		cin >> s[i].name;
		s[i].num = 0;
		for (int j = 0; j < 3; j++)
		{
			cout << "输入第" << j + 1 << "门课的成绩：";
			cin >> s[i].subject[j];
			s[i].num += s[i].subject[j];
		}
		cout << endl;
	}
}

int Student::change(Student s[], int n) {
	cout << "请问是否修改信息(1/0):";
	int t;
	cin >> t;
	if (0 == t) {
		system("cls");
		return 0;
	}
	for (int i = 0; i < 1; i++)
	{
		cout << "输入要修改信息学生的学号：";
		cin >> s[i+1].id;
		cout << "输入要修改信息学生的姓名：";
		cin >> s[i+1].name;
		for (int j = 0; j < 3; j++)
		{
			cout << "输入修改后第" << j + 1 << "门课的成绩：";
			cin >> s[i+1].subject[j];
			s[i+1].num += s[i+1].subject[j+1];
		}


		cout << endl;
	}
	system("cls");
}

int Student::avg(Student s[]) {
	int j;
	j=(s[0].num + s[1].num + s[2].num) / 3;
	return j;
}

void Student::print(Student s[], int n)
{
	for (int i = 0; i < n; i++)
	{
		Student p;
		cout << "第" << i + 1 << "名学生信息" << endl;
		cout << "学号：" << s[i].id << endl;
		cout << "姓名：" << s[i].name << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << "第" << j + 1 << "门课的成绩：" << s[i].subject[j] << endl;
		}
		cout << "第"<<i+1<<"个学生平均成绩为：";
			p.avg(stu);
			cout << endl;
	}
}

int main(void)
{
	int num;
	cout << "输入学生个数：";
	cin >> num;
	cout << endl;
	Student s;
	s.input(stu, num);
	s.change(stu, num);
	s.print(stu, num);
	return 0;
}
