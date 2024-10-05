#pragma once
#include "globalFile.h"
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "student.h"
#include "teacher.h"	
#include"identity.h"
#include "computerRoom.h"

using namespace std;

//����Ա��
class Manager: public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);
	//�˵�����
	virtual void openMenu();
	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();
	//����ظ� ����1 Ҫ����id ����2 Ҫ��������
	bool checkRepeat(int id, int type);

	//ѧ������
	vector<Student> vStu;
	//��ʦ����
	vector<Teacher> vTea;

	//������Ϣ
	vector<ComputerRoom> vCom;
};