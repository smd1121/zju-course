#include "pch.h"
#include "DBHelper.h"

DBHelper* thisDB;
vector<string> idAndNameItems = { "ID", "name" };
vector<string> enrollItems = { "studentID", "classID", "score" };
vector<string> classItems = { "ID", "courseName", "teacherName" };
vector<string> transcriptItems = { "studentID", "studentName", "courseID",
								   "courseName", "score", "classID" };

bool run();
void scoreOp();
void enrollOp();
void otherOp(int choice, int subChoice);
int chooseFunc();
int chooseSubFunc(bool haveTeacher);

void otherOp(int choice, int subChoice) {
	/* 1 �б� 2 �ɼ��� 3 �� 4 ɾ */
	/* 0 ��ʦ 1 ѧ�� 2 �γ� 3 ��ѧ�� */
	stringstream cmd("");
	string cmdStr;
	static const string tbls[] = { "Teacher", "Student", "Course", "Class" };

	if (choice == 1 && subChoice != 3) { // list
		cmd << "select * from " << tbls[subChoice] << " order by ID";
		cmdStr = cmd.str();
		thisDB->runSQL(cmdStr, idAndNameItems);
	}
	else if (choice == 1 && subChoice == 3) { // list of classes
		cmd << "select Class.ID as ID, Course.Name as courseName, Teacher.Name as teacherName "
			<< "from Class, Teach, Teacher, InstanceOf, Course "
			<< "where Class.ID = InstanceOf.classID and courseID = Course.ID "
			<< "and Class.ID = Teach.classID and teacherID = Teacher.ID "
			<< "order by Class.ID";

		cmdStr = cmd.str();
		thisDB->runSQL(cmdStr, classItems);
	}
	else if (choice == 2) { // transcript
		cmd << "select studentID, Student.name as studentName, courseID, "
			<< "Course.name as courseName, score, Enroll.classID as classID "
			<< "from Student, Enroll, Class, InstanceOf, Course "
			<< "where Student.ID = studentID and Enroll.classID = Class.ID "
			<< "and InstanceOf.classID = Class.ID and courseID = Course.ID ";
		if (subChoice == 1) {
			cout << "������ѧ�� ID��\n > ";
			int id;
			cin >> id;
			while (getchar() != '\n');
			cmd << "and studentID = " << id;
		}
		else if (subChoice == 2) {
			cout << "������γ� ID��\n > ";
			int id;
			cin >> id;
			while (getchar() != '\n');
			cmd << "and courseID = " << id;
		}
		else if (subChoice == 3) {
			cout << "�������ѧ�� ID��\n > ";
			int id;
			cin >> id;
			while (getchar() != '\n');
			cmd << "and Class.ID = " << id;
		}
		cmdStr = cmd.str();
		thisDB->runSQL(cmdStr, transcriptItems);
	}
	else if (choice == 3 && subChoice != 3) { // insert
		switch (subChoice) {
		case 0:
			cout << "�������ʦ������\n > ";
			break;
		case 1:
			cout << "������ѧ��������\n > ";
			break;
		case 2:
			cout << "������γ�����\n > ";
			break;
		}
		string name;
		char temp;
		getchar();	// �Ե�֮ǰ�Ļس�
		while ((temp = getchar()) != '\n')
			name += temp;

		int thisID = thisDB->getTblMaxID(tbls[subChoice]) + 1; 
		// ���� ID Ϊ��Ӧ������� ID + 1

		cmd << "insert into " << tbls[subChoice] << " values (" << thisID << ", '" << name << "')";
		cmdStr = cmd.str();
		thisDB->runSQL(cmdStr);

		cmd.str("");
		cmd << "select * from " << tbls[subChoice] << " where ID = " << thisID;
		cout << "��������Ŀ��\n";
		cmdStr = cmd.str();
		thisDB->runSQL(cmdStr, idAndNameItems);
	}
	else if (choice == 3) { // insert class
		// �½��γ�
		int thisID = thisDB->getTblMaxID(tbls[3]) + 1;
		cmd.str("");
		cmd << "insert into Class values (" << thisID << ")";
		cmdStr = cmd.str();
		thisDB->runSQL(cmdStr);
		cout << "�½�ѧ��ı���� " << thisID << endl;
		// �����γ̺�
		cout << "�����������γ̺ţ�\n > ";
		int courseID;
		cin >> courseID;
		// ���������ϵ
		cmd.str("");
		cmd << "insert into InstanceOf values (" << thisID << ", " << courseID << ")";
		cmdStr = cmd.str();
		thisDB->runSQL(cmdStr);
		// �����ʦ
		cout << "�������ʦ������\n > ";
		int n;
		cin >> n;
		cout << "�������ʦ���ţ��ж���ÿո������\n > ";
		while (n--) {
			int teacherID;
			cin >> teacherID;
			// ���������ϵ
			cmd.str("");
			cmd << "insert into Teach values (" << teacherID << ", " << thisID << ")";
			cmdStr = cmd.str();
			thisDB->runSQL(cmdStr);
		}
	}
	else if (choice == 4) { // delete
		switch (subChoice) {
		case 0:
			cout << "�������ʦ��ţ�\n > ";
			break;
		case 1:
			cout << "������ѧ����ţ�\n > ";
			break;
		case 2:
			cout << "������γ���ţ�\n > ";
			break;
		case 3:
			cout << "�������ѧ����ţ�\n > ";
			break;
		}
		int ID;
		cin >> ID;
		cmd.str("");
		cmd << "delete from " << tbls[subChoice] << " where ID = " << ID;
		cmdStr = cmd.str();
		thisDB->runSQL(cmdStr);
		cout << "ɾ���ɹ���" << endl;
	}
}

int main()
{
	string dbFileName = "school.accdb";
	DBHelper db(dbFileName);
	thisDB = &db;

	while (run()) ;	// ���Ƿ��� false��������������
}

bool run() {
	int choice;
	while (!(choice = chooseFunc())) ; // ѭ����������Ч����
	
	try {
		if (choice == 5)
			scoreOp();
		else if (choice == 6)
			enrollOp();
		else if (choice == 7) {
			cout << "�ټ���" << endl;
			return false;	// ֹͣ����
		}
		else {
			int subChoice;
			while ((subChoice = chooseSubFunc(choice != 2)) < 0);
			if (subChoice == 4)
				return true;
			otherOp(choice, subChoice);
		}
	} catch (_com_error& e)
	{
		cerr << "[Error] " << e.Description() << endl << endl;
	}
	
	return true;
}

void scoreOp() {
	string studentID, classID;
	double score;

	cout << "��������Ҫ���ǻ���ĳɼ���ѧ����ţ�\n > ";
	cin >> studentID;
	cout << "������༶��ţ�\n > ";
	cin >> classID;
	cout << "�����������\n >";
	cin >> score;

	stringstream cmd("");

	cmd << "update Enroll set score = " << (int)score << " where "
		<< "studentID = " << studentID << " and classID = " << classID;

	string cmdStr = cmd.str();
	thisDB->runSQL(cmdStr);

	cout << "\n ���³ɹ������µ���Ŀ�ǣ�\n";

	cmd.str("");
	cmd << "select * from Enroll where "
		<< "studentID = " << studentID << " and classID = " << classID;

	cmdStr = cmd.str();
	thisDB->runSQL(cmdStr, enrollItems);
}

void enrollOp() {
	string studentID, classID;

	cout << "��������Ҫ��ѡ�γ̵�ѧ����ţ�\n > ";
	cin >> studentID;
	cout << "������༶��ţ�\n > ";
	cin >> classID;

	stringstream cmd("");

	cmd << "insert into Enroll values (" << studentID << ", " << classID << ", null)";

	string cmdStr = cmd.str();
	thisDB->runSQL(cmdStr);

	cout << "\n ��������Ŀ�ǣ�\n";

	cmd.str("");
	cmd << "select * from Enroll where "
		<< "studentID = " << studentID << " and classID = " << classID;

	cmdStr = cmd.str();
	thisDB->runSQL(cmdStr, enrollItems);
}

int chooseFunc() {
	cout << "��ӭ���ʽ�������̨��\n"
		<< "��������Ҫʹ�õĹ�����ţ�\n"
		<< "[1] ��ѯ ��ʦ/ѧ��/�γ�/��ѧ�� �б�\n"
		<< "[2] ��ѯ ѧ��/�γ�/��ѧ�� �ɼ���\n"
		<< "[3] ���� ��ʦ/ѧ��/�γ�/��ѧ��\n"
		<< "[4] ɾ�� ��ʦ/ѧ��/�γ�/��ѧ��\n"
		<< "[5] �������ǻ����\n"
		<< "[6] ѧ���γ̲�ѡ\n"
		<< "[7] �˳�\n"
		<< "> ����������ѡ��";
	int choice;
	cin >> choice;
	if (choice < 1 || choice > 8) {
		while (getchar() != '\n');
		cout << "����������������ѡ��\n\n";
		return 0;
	}
	return choice;
}

int chooseSubFunc(bool haveTeacher) {
	cout << "��ѡ���������" << endl;
	if (haveTeacher)
		cout << "[0] ��ʦ" << endl;
	cout << "[1] ѧ��\n[2] �γ�\n[3] ��ѧ��\n[4] ����\n > ";

	int choice;
	cin >> choice;
	if (choice < (!haveTeacher) || choice > 4) {
		while (getchar() != '\n');
		cout << "����������������ѡ��\n\n";
		return -1;
	}
	return choice;
}