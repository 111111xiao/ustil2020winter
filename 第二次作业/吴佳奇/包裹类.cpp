#include<iostream>
#include<string>
using namespace std;


class package {
	string sender;
	string receiver;
	string address;
	int weight;



public:
	package(int weight,string sender, string receiver, string address) {
		this->weight = weight;
		this->receiver = receiver;
		this->sender = sender;
		this->address = address;
	}
	string getsender() {
		return sender;
	}
	string getreceiver() {
		return receiver;
	}
	string getaddress() {
		return address;
	}
	int getweight() {
		return weight;
	}
	virtual int caculatecost() = 0;//纯虚函数
};

class normal :package {
	int firstcost;
	int overcost;
	int firstweight;
public:
	int getfirstcost() {
		return firstcost;
	}
	int getovercost() {
		return overcost;
	}
	normal(int weight, string sender, string receiver, string address):package(weight,sender,receiver,address)
	{
		firstcost = 20;
		overcost = 5;
		firstweight = 10;
	}
	int caculatecost() {
		if (getweight() > firstweight)
			return ((getweight() - firstweight) * 5 + 20);
		else 
			return firstcost;
	}//虚函数
	void print() {
		cout<<"该邮件的费用为" << caculatecost() << endl;
	}

};

class hurry :package {
	int startcost;
	int distance;
public:
	hurry(int weight, string sender, string receiver, string address,int distance) :package(weight, sender, receiver, address)
	{
		startcost = 50;
		this->distance = distance;
	}
	int caculatecost() {
		return (startcost + getweight() * 10 + distance * 0.02);//虚函数
	}
	void print() {
		cout << "该邮件的费用为" << caculatecost() << endl;
	}
};

int main() {
	normal pac1(20, "Jim", "Sam", "NewYork");//重量 寄件人 收件人 地址
	hurry pck2(20, "Jim", "Sam", "NewYork", 30);//重量 寄件人 收件人 路程
	pac1.print();
	pck2.print();
	return 0;
}
