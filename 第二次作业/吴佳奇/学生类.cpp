#include<iostream>
#include<string>
using namespace std;

class scores {
	int math;
	
	int english;
	
	int pc;
	
	static int summath;

	static int sumenglish;

	static int sumpc;

public:
	scores() {}//默认构造函数
	scores(int math,int english,int pc) //构造函数
	{
		change(math, english, pc);
		summath += math;
		sumenglish += english;
		sumpc += pc;
	}
	~scores() {}//析构函数
	scores(const scores&score) {
		math = score.math;
		english = score.english;
		pc = score.pc;
	}//复制构造函数
	int getmath() {

		return math;
	}

	int getenglish() {
		return english;
	}

	int getpc() {
		return pc;
	}
	
	static int getmathsum(int math) {
		
		return summath;
	}
	
	static int getenglishsum(int english)
	{
		
	
		return  sumenglish;
	}
	
	static int getpcsum(int pc)
	{
		
		return sumpc;
	
	}
	
	
	
	void change(int math,int english,int pc) {
		this->english = english;
		this->math = math;
		this->pc = pc;
	
	}
	
	int getaverage() {
		return (math + english + pc) / 3;
	}

};
int scores::sumenglish = 0;
int scores::summath = 0;
int scores::sumpc = 0;


class student {
	
	string name;
	
	int number;
	
	scores score;
	
	static int members;

public:
	
	static int getmembers()
	{
		return members;
	}
	
	student(string name, int number, int math, int english, int pc) :score(math, english, pc)
	{
		this->name = name;
	
		this->number = number;
		
		members++;
		score.getpcsum(pc);
		score.getmathsum(math);
		score.getenglishsum(english);
	}//构造函数
	
	~student() {}//析构函数

	student(const student& st) {
		name = st.name;
		number = st.number;
		score = st.score;
	}//复制构造函数
	
	void changest(string name, int number, int math, int english, int pc) {
		
		this->name = name;

		this->number = number;

		score.change(math, english, pc);
	}
	
	static int mathaverage(int math) {
		return math/members ;
	
	}
	
	static int englishaverage(int english) {
		return english/members ;

	}
	
	static int pcaverage(int pc) {
		return pc /members;

	}
	static void printmem() {
		cout <<"总人数为："<< members << endl;
	}

	void printaverage() {
		cout << "数学平均成绩为：" << mathaverage(score.getmathsum(score.getmath())) << endl
			 << "英语平均成绩为：" << englishaverage(score.getenglishsum(score.getenglish())) << endl
			 <<"计算机平均成绩为："<< pcaverage(score.getpcsum(score.getpc()))<<endl<<endl;
	
	}
	void print() {
		cout <<"姓名是："<< name <<endl
			 <<"学号是:"<< number <<endl
			 <<"英语成绩为:"<< score.getenglish()<<endl 
			 <<"数学成绩为:"<< score.getmath()<<endl
			 <<"计算机成绩为:" << score.getpc()<<endl
			<<"平均成绩为:"<<score.getaverage()<<endl<<endl;
	}
};
int student::members = 0;
int main()
{
	student st1("张三",1911203201,90,91,92);//创建学生  姓名 学号 英语  数学 计算机
	st1.print();//显示学生数据
	st1.printaverage();
				student st2("李四", 191203202, 80, 90, 99);
	st2.print();
	st1.printaverage();//输出单科平均成绩
	st1.changest("老王", 191203224, 11, 12, 13);//更改学生数据
	st1.print();//显示学生数据
	student::printmem();//静态函数 输出静态成员“总人数”
	return 0;



}
