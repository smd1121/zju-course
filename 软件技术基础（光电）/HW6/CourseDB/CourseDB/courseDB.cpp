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
	/* 1 列表 2 成绩单 3 增 4 删 */
	/* 0 教师 1 学生 2 课程 3 教学班 */
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
			cout << "请输入学生 ID：\n > ";
			int id;
			cin >> id;
			while (getchar() != '\n');
			cmd << "and studentID = " << id;
		}
		else if (subChoice == 2) {
			cout << "请输入课程 ID：\n > ";
			int id;
			cin >> id;
			while (getchar() != '\n');
			cmd << "and courseID = " << id;
		}
		else if (subChoice == 3) {
			cout << "请输入教学班 ID：\n > ";
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
			cout << "请输入教师姓名：\n > ";
			break;
		case 1:
			cout << "请输入学生姓名：\n > ";
			break;
		case 2:
			cout << "请输入课程名：\n > ";
			break;
		}
		string name;
		char temp;
		getchar();	// 吃掉之前的回车
		while ((temp = getchar()) != '\n')
			name += temp;

		int thisID = thisDB->getTblMaxID(tbls[subChoice]) + 1; 
		// 设置 ID 为对应表中最大 ID + 1

		cmd << "insert into " << tbls[subChoice] << " values (" << thisID << ", '" << name << "')";
		cmdStr = cmd.str();
		thisDB->runSQL(cmdStr);

		cmd.str("");
		cmd << "select * from " << tbls[subChoice] << " where ID = " << thisID;
		cout << "新增的条目：\n";
		cmdStr = cmd.str();
		thisDB->runSQL(cmdStr, idAndNameItems);
	}
	else if (choice == 3) { // insert class
		// 新建课程
		int thisID = thisDB->getTblMaxID(tbls[3]) + 1;
		cmd.str("");
		cmd << "insert into Class values (" << thisID << ")";
		cmdStr = cmd.str();
		thisDB->runSQL(cmdStr);
		cout << "新教学班的编号是 " << thisID << endl;
		// 所属课程号
		cout << "请输入所属课程号：\n > ";
		int courseID;
		cin >> courseID;
		// 插入从属关系
		cmd.str("");
		cmd << "insert into InstanceOf values (" << thisID << ", " << courseID << ")";
		cmdStr = cmd.str();
		thisDB->runSQL(cmdStr);
		// 插入教师
		cout << "请输入教师人数：\n > ";
		int n;
		cin >> n;
		cout << "请输入教师工号，有多个用空格隔开：\n > ";
		while (n--) {
			int teacherID;
			cin >> teacherID;
			// 插入从属关系
			cmd.str("");
			cmd << "insert into Teach values (" << teacherID << ", " << thisID << ")";
			cmdStr = cmd.str();
			thisDB->runSQL(cmdStr);
		}
	}
	else if (choice == 4) { // delete
		switch (subChoice) {
		case 0:
			cout << "请输入教师序号：\n > ";
			break;
		case 1:
			cout << "请输入学生序号：\n > ";
			break;
		case 2:
			cout << "请输入课程序号：\n > ";
			break;
		case 3:
			cout << "请输入教学班序号：\n > ";
			break;
		}
		int ID;
		cin >> ID;
		cmd.str("");
		cmd << "delete from " << tbls[subChoice] << " where ID = " << ID;
		cmdStr = cmd.str();
		thisDB->runSQL(cmdStr);
		cout << "删除成功！" << endl;
	}
}

int main()
{
	string dbFileName = "school.accdb";
	DBHelper db(dbFileName);
	thisDB = &db;

	while (run()) ;	// 除非返回 false，否则无限运行
}

bool run() {
	int choice;
	while (!(choice = chooseFunc())) ; // 循环至读到有效输入
	
	try {
		if (choice == 5)
			scoreOp();
		else if (choice == 6)
			enrollOp();
		else if (choice == 7) {
			cout << "再见。" << endl;
			return false;	// 停止程序
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

	cout << "请输入需要补登或更改成绩的学生编号：\n > ";
	cin >> studentID;
	cout << "请输入班级编号：\n > ";
	cin >> classID;
	cout << "请输入分数：\n >";
	cin >> score;

	stringstream cmd("");

	cmd << "update Enroll set score = " << (int)score << " where "
		<< "studentID = " << studentID << " and classID = " << classID;

	string cmdStr = cmd.str();
	thisDB->runSQL(cmdStr);

	cout << "\n 更新成功。更新的条目是：\n";

	cmd.str("");
	cmd << "select * from Enroll where "
		<< "studentID = " << studentID << " and classID = " << classID;

	cmdStr = cmd.str();
	thisDB->runSQL(cmdStr, enrollItems);
}

void enrollOp() {
	string studentID, classID;

	cout << "请输入需要补选课程的学生编号：\n > ";
	cin >> studentID;
	cout << "请输入班级编号：\n > ";
	cin >> classID;

	stringstream cmd("");

	cmd << "insert into Enroll values (" << studentID << ", " << classID << ", null)";

	string cmdStr = cmd.str();
	thisDB->runSQL(cmdStr);

	cout << "\n 关联的条目是：\n";

	cmd.str("");
	cmd << "select * from Enroll where "
		<< "studentID = " << studentID << " and classID = " << classID;

	cmdStr = cmd.str();
	thisDB->runSQL(cmdStr, enrollItems);
}

int chooseFunc() {
	cout << "欢迎访问教务网后台！\n"
		<< "请输入需要使用的功能序号：\n"
		<< "[1] 查询 教师/学生/课程/教学班 列表\n"
		<< "[2] 查询 学生/课程/教学班 成绩单\n"
		<< "[3] 新增 教师/学生/课程/教学班\n"
		<< "[4] 删除 教师/学生/课程/教学班\n"
		<< "[5] 分数补登或更改\n"
		<< "[6] 学生课程补选\n"
		<< "[7] 退出\n"
		<< "> 请输入您的选择：";
	int choice;
	cin >> choice;
	if (choice < 1 || choice > 8) {
		while (getchar() != '\n');
		cout << "输入有误！请您重新选择。\n\n";
		return 0;
	}
	return choice;
}

int chooseSubFunc(bool haveTeacher) {
	cout << "请选择操作对象：" << endl;
	if (haveTeacher)
		cout << "[0] 教师" << endl;
	cout << "[1] 学生\n[2] 课程\n[3] 教学班\n[4] 返回\n > ";

	int choice;
	cin >> choice;
	if (choice < (!haveTeacher) || choice > 4) {
		while (getchar() != '\n');
		cout << "输入有误！请您重新选择。\n\n";
		return -1;
	}
	return choice;
}