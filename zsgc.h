#include <string>
#include<stdio.h>
#include <unistd.h>

using namespace std;
#define MAX 20	//定义通讯录最大人数
//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别: 1男 2女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//设计通讯录的结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录的联系人个数
	int m_Size;
};
extern void showMenu();
extern void addPerson(Addressbooks* abs);
extern void showPerson(Addressbooks* abs);
extern int isExist(Addressbooks* abs, string name);
extern void deletePerson(Addressbooks* abs);
extern void findPerson(Addressbooks* abs) ;
extern void modifyPerson(Addressbooks* abs);
extern void cleanPerson(Addressbooks* abs);
extern void rose();
