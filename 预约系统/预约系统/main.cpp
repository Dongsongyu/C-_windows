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

//����ѧ���Ӳ˵�����
void StudentMenu(Identity*& student)
{
	//����ָ�� ����ָ���������
	while (true) {
		//����ѧ���Ӳ˵�
		student->openMenu();

		//������ָ�� תΪ����ָ�룬������������������
		Student* stu = (Student*)student;

		int select = 0;
		//�����û���ѡ��
		std::cin >> select;

		if (select == 1) {
			//����ԤԼ
			//cout << "����ԤԼ" << endl;
			stu->applyOrder();
		}
		else if (select == 2) {
			//�鿴�ҵ�ԤԼ
			//cout << "�鿴�ҵ�ԤԼ" << endl;
			stu->showMyOrder();
		}
		else if (select == 3) {
			//�鿴����ԤԼ
			//cout << "�鿴����ԤԼ" << endl;
			stu->showAllOrder();
		}
		else if (select == 4) {
			//ȡ��ԤԼ
			//cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
		}
		else {
			delete student;
			std::cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//������ʦ�Ӳ˵�����
void TeacherMenu(Identity*& teacher)
{
    //����ָ�� ����ָ���������
    while (true) {
        //������ʦ�Ӳ˵�
        teacher->openMenu();

		//������ָ�� תΪ����ָ�룬������������������
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		//�����û���ѡ��
		cin >> select;

		if (select == 1) {
			//�鿴����ԤԼ
			//cout << "�鿴����ԤԼ" << endl;
			tea->showAllOrder();
		}
		else if (select == 2) {
			//���ԤԼ
			//cout << "���ԤԼ" << endl;
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
    }
}
//�������Ա�Ӳ˵�����
void managerMenu(Identity*& manager)
{
	//����ָ�� ����ָ���������
    while (true) {
        //���ù���Ա�Ӳ˵�
		manager->openMenu();
        //������ָ�� תΪ����ָ�룬������������������
        Manager* man = (Manager*)manager;

        int select = 0;
        //�����û���ѡ��
        cin >> select;

		if (select == 1) {
			//����˺�
            //cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) {
			//�鿴�˺�
            //cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			//�鿴������Ϣ
            //cout << "�鿴������Ϣ" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			//���ԤԼ
            //cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
        else {
            //ע����¼
            delete manager;//���ٵ���������
            cout << "ע���ɹ�" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}
//��¼����
void LoginIn(string fileName, int type)
{
    //����ָ�� ����ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
    ifs.open(fileName, ios::in);

    //�ж��ļ��Ƿ����
    if (!ifs.is_open()) {
        cout << "�ļ�������" << endl;
        ifs.close();
        return;
    }

    //׼�������û���Ϣ
    int id = 0;
    string name;
    string pwd;
    
    //�ж����
    if (type == 1) {
		cout << "���������ѧ��" << endl;
        cin >> id;
    }
    else if (type == 2) {
        cout << "���������ְ����" << endl;
        cin >> id;
    }
	cout << "����������û���" << endl;
	cin >> name;
	cout << "�������������" << endl;
	cin >> pwd;

    if (type == 1) {
        //ѧ�������֤
        int fId;//���ļ��ж�ȡ��id
        string fName;//���ļ��ж�ȡ��name
        string fPwd;//���ļ��ж�ȡ��pwd
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            //���û�������Ϣ���Ա�
            if(fId == id && fName == name && fPwd == pwd) {
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
                //����ѧ����ݵ��Ӳ˵�
                StudentMenu(person);
				return;
			}
        }
    }
    else if (type == 2) {
        //��ʦ�����֤
        int fId;//���ļ��ж�ȡ��id
		string fName;//���ļ��ж�ȡ��name
		string fPwd;//���ļ��ж�ȡ��pwd
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            //���û�������Ϣ���Ա�
            if (fId == id && fName == name && fPwd == pwd) {
                cout << "��ʦ��֤��¼�ɹ�" << endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);
                //������ʦ��ݵ��Ӳ˵�
                TeacherMenu(person);
                return;
            }
        }
    }
    else if (type == 3) {
		//����Ա�����֤
		string fName;//���ļ��ж�ȡ��name
		string fPwd;//���ļ��ж�ȡ��pwd
        while (ifs >> fName && ifs >> fPwd) {
            //���û�������Ϣ���Ա�
            if (fName == name && fPwd == pwd) {
                cout << "����Ա��֤��¼�ɹ�" << endl;
                system("pause");
                system("cls");
                person = new Manager(name, pwd);
				//�������Ա��ݵ��Ӳ˵�
				managerMenu(person);
                return;
            }
        }
    }
    cout << "��֤��¼ʧ��" << endl;
    system("pause");
    system("cls");

    return;
}

int main()
{
    int select = 0;//�����ж��û���ѡ��

    while (true) {
        cout << "----------------------��ӭԤԼϵͳ-----------------" << endl;
        cout << endl << "������������" << endl;
        cout << "\t\t---------------------------------------\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|           1.ѧ������                |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|           2.��ʦ                    |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|           3.����Ա                  |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|           0.�˳�                    |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t--------------------------------------\n";
        cout << "���������ѡ�� : ";

        cin >> select; //�����û�ѡ��
        //�����û�ѡ�� ʵ�ֲ�ͬ�ӿ�
        switch (select) {
        case 1://ѧ�����
            LoginIn(STUDENT_FILE, 1);
            break;
        case 2://��ʦ���
            LoginIn(TEACHER_FILE, 2);
            break;
        case 3://����Ա���
            LoginIn(ADMIN_FILE, 3);
            break;
        case 0://�˳�ϵͳ
            cout << "��ӭ�´�ʹ��" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "��������������ѡ��!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    return 0;
}
