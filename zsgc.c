#include<iostream>
#include<string.h>
#include"zsgc.h"
#include<stdlib.h>
#include<stdio.h>
#include <signal.h>  // 关于信号的头文件
#include <unistd.h>
//1、添加学生信息
void addPerson(Addressbooks* abs)
{
	//判断学生信息表是否已满，如果满了不再添加
	if (abs->m_Size == MAX) {
		cout << "学生信息表已满，无法添加" << endl;
		return;
	}
	else {
		//添加具体的学生信息

		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		int sex = 0;

		while (true)
		{
			//如果输入的是1或者2，可以退出循环；如果输入的有误，重新输入。
			cin >> sex;//cin涉及到缓冲区的问题，如果输入的格式不符合，错误的数据会一直留在缓冲区，因此如下进行了一些修补
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				//cout << "输入错误，请重新输入" << endl;
			}
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			} 
			else {
				cout << "输入有误，请重新输入" << endl;
			}
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//学号
		cout << "请输入学号" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新学生信息表中的人数
		abs->m_Size++;

		cout << "添加成功" << endl;
		sleep(10);
		system("clear");
		
	}
}

//2、显示所有学生信息
void showPerson(Addressbooks* abs) {
	//判断学生信息表中人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的学生信息信息
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else 
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";//利用单目运算符返回男女比较快
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "学号：" << abs->personArray[i].m_Addr << endl;
		}
	}
	sleep(10);
	system("clear");
}

//检测学生信息是否存在，如果存在，返回学生信息所在数组中的具体位置，不存在返回-1
//参数1代表学生信息表，参数2代表对比姓名
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++) {
		//找到用户输入的姓名了
		if (abs->personArray[i].m_Name == name)
		{
			//cout << "****检验是否遍历查询到人了的标记****" << endl;//debug用的
			return i;			
		}
		return -1;//如果遍历结束都没找到，返回-1
	}
	return -1;	//这个return-1很关键，因为如果不写的话当同学录为空的时候根本就进不去上面的for循环
				//isExist会返回很奇怪的数使得后面delete对一块空火箭未知的地方进行了操作
}

//3、删除学生信息
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的学生信息" << endl;

	string name;
	cin >> name;
	int ret = -1;
	ret = isExist(abs, name);
	//ret==-1 没查到		//ret！=-1 查到了
	if (ret != -1) {
		//查到此人，要进行删除操作
		for (int i = ret; i < abs->m_Size; i++) {
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新学生信息表中的人员数
		cout << "删除成功" << endl;
	
		system("clear");	
	}
	else {
		cout << "查无此人" << endl;
	}
	sleep(10);
	system("clear");
}

//4、查找学生信息
void findPerson(Addressbooks* abs) 
{
	cout << "请输入您要查找的学生信息" << endl;
	string name;
	cin >> name;
	//判断学生信息是否存在于学生信息表中
	int ret = isExist(abs, name);

	if (ret != -1)	//找到学生信息
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "学号：" << abs->personArray[ret].m_Addr << endl;
	}
	else {	//未找到学生信息
		cout << "查无此人" << endl;
	}
	sleep(10);
	system("clear");
}

//5、修改指定学生信息信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的学生信息" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)//找到学生信息
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		cout << "请输入性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				//输入正确就退出循环输入
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age	= age;
		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//学号
		cout << "请输入学号：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
	}
	else//未找到学生信息
	{
		cout << "查无此人" << endl;
	}

	sleep(10);
	system("clear");
}

//6、清空所有学生信息
void cleanPerson(Addressbooks* abs)
{
	int x = 0;
	cout << "是否真的要清空学生信息？" << endl;
	cout << "1---是" << endl;
	cout << "2---否" << endl;
	cin >> x;
	if (x == 1)
	{
		abs->m_Size = 0;
		cout << "学生信息表已清空" << endl;
	}
	else 
	{
		cout << "退出清空操作" << endl;
	}
	sleep(10);
	system("clear");
}

