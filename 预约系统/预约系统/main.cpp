#define _CRT_SECURE_NO_WARNINGS 1
#include "identity.h"
#include<iostream>
#include<fstream>
#include<string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
using namespace std;

//进入学生子菜单界面
void StudentMenu(Identity*& student)
{
	//父类指针 用于指向子类对象
	while (true) {
		//调用学生子菜单
		student->openMenu();

		//将父类指针 转为子类指针，调用子类中其他方法
		Student* stu = (Student*)student;

		int select = 0;
		//接收用户的选择
		std::cin >> select;

		if (select == 1) {
			//申请预约
			//cout << "申请预约" << endl;
			stu->applyOrder();
		}
		else if (select == 2) {
			//查看我的预约
			//cout << "查看我的预约" << endl;
			stu->showMyOrder();
		}
		else if (select == 3) {
			//查看所有预约
			//cout << "查看所有预约" << endl;
			stu->showAllOrder();
		}
		else if (select == 4) {
			//取消预约
			//cout << "取消预约" << endl;
			stu->cancelOrder();
		}
		else {
			delete student;
			std::cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//进入老师子菜单界面
void TeacherMenu(Identity*& teacher)
{
    //父类指针 用于指向子类对象
    while (true) {
        //调用老师子菜单
        teacher->openMenu();

		//将父类指针 转为子类指针，调用子类中其他方法
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		//接收用户的选择
		cin >> select;

		if (select == 1) {
			//查看所有预约
			//cout << "查看所有预约" << endl;
			tea->showAllOrder();
		}
		else if (select == 2) {
			//审核预约
			//cout << "审核预约" << endl;
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
    }
}
//进入管理员子菜单界面
void managerMenu(Identity*& manager)
{
	//父类指针 用于指向子类对象
    while (true) {
        //调用管理员子菜单
		manager->openMenu();
        //将父类指针 转为子类指针，调用子类中其他方法
        Manager* man = (Manager*)manager;

        int select = 0;
        //接收用户的选择
        cin >> select;

		if (select == 1) {
			//添加账号
            //cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) {
			//查看账号
            //cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			//查看机房信息
            //cout << "查看机房信息" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			//清空预约
            //cout << "清空预约" << endl;
			man->cleanFile();
		}
        else {
            //注销登录
            delete manager;//销毁掉堆区对象
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}
//登录功能
void LoginIn(string fileName, int type)
{
    //父类指针 用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
    ifs.open(fileName, ios::in);

    //判断文件是否存在
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    //准备接受用户信息
    int id = 0;
    string name;
    string pwd;
    
    //判断身份
    if (type == 1) {
		cout << "请输入你的学号" << endl;
        cin >> id;
    }
    else if (type == 2) {
        cout << "请输入你的职工号" << endl;
        cin >> id;
    }
	cout << "请输入你的用户名" << endl;
	cin >> name;
	cout << "请输入你的密码" << endl;
	cin >> pwd;

    if (type == 1) {
        //学生身份验证
        int fId;//从文件中读取的id
        string fName;//从文件中读取的name
        string fPwd;//从文件中读取的pwd
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            //与用户输入信息做对比
            if(fId == id && fName == name && fPwd == pwd) {
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
                //进入学生身份的子菜单
                StudentMenu(person);
				return;
			}
        }
    }
    else if (type == 2) {
        //教师身份验证
        int fId;//从文件中读取的id
		string fName;//从文件中读取的name
		string fPwd;//从文件中读取的pwd
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            //与用户输入信息做对比
            if (fId == id && fName == name && fPwd == pwd) {
                cout << "老师验证登录成功" << endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);
                //进入老师身份的子菜单
                TeacherMenu(person);
                return;
            }
        }
    }
    else if (type == 3) {
		//管理员身份验证
		string fName;//从文件中读取的name
		string fPwd;//从文件中读取的pwd
        while (ifs >> fName && ifs >> fPwd) {
            //与用户输入信息做对比
            if (fName == name && fPwd == pwd) {
                cout << "管理员验证登录成功" << endl;
                system("pause");
                system("cls");
                person = new Manager(name, pwd);
				//进入管理员身份的子菜单
				managerMenu(person);
                return;
            }
        }
    }
    cout << "验证登录失败" << endl;
    system("pause");
    system("cls");

    return;
}

int main()
{
    int select = 0;//用于判断用户的选择

    while (true) {
        cout << "----------------------欢迎预约系统-----------------" << endl;
        cout << endl << "请输入你的身份" << endl;
        cout << "\t\t---------------------------------------\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|           1.学生代表                |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|           2.老师                    |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|           3.管理员                  |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|           0.退出                    |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t--------------------------------------\n";
        cout << "请输入你的选择 : ";

        cin >> select; //接受用户选择
        //根据用户选择 实现不同接口
        switch (select) {
        case 1://学生身份
            LoginIn(STUDENT_FILE, 1);
            break;
        case 2://老师身份
            LoginIn(TEACHER_FILE, 2);
            break;
        case 3://管理员身份
            LoginIn(ADMIN_FILE, 3);
            break;
        case 0://退出系统
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "输入有误，请重新选择!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    return 0;
}
