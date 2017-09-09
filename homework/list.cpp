#include<iostream>
#include<string>

using namespace std;

struct Student {
	string name;
	string stuNum;
	string subject;
	double score;
	string phoneNumber;
	Student *next;
};

Student *head = nullptr;

void deleteNode(string name) {

	Student *p;
	if (!head) {
		cout << "list null ! " << endl;
		return;
	}
	if (head->name == name) {
		p = head;
		head = head->next;
		delete p;
		cout << "delete successful !" << endl;
		return;
	}

	for (Student *pGuard = head; pGuard->next; pGuard = pGuard->next) {

		if (pGuard->next->name == name) {
			p = pGuard->next;
			pGuard->next = p->next;
			delete p;
			cout << "delete successful !" << endl;
			return;
		}
	}

	cout << "NOT FOUND !" << endl;
}


//输入的链表数据中的score必须是从小到大
void insert(Student *stu) {   
	if (!head) {
		head = stu;
		stu->next = nullptr;
		return;
	}
	if (head->score > stu->score) {
		stu->next = head;
		head = stu;
		return;
	}
	Student *pGuard = head;
	while (pGuard->next && pGuard->next->score < stu->score) {
		pGuard = pGuard->next;
	}
	stu->next = pGuard->next;
	pGuard->next = stu;
}


void getInfomation(Student *p1) {
	cin >> p1->name
		>> p1->stuNum
		>> p1->subject
		>> p1->score
		>> p1->phoneNumber;

}

Student * creat(int testNum) {
	Student *p1, *p2;
	p1 = new Student;
	getInfomation(p1);
	p2 = p1;
	int t = testNum - 1;
	while(t--){
		if (!head) {
			head = p1;
		}
		else {
			p2->next = p1;
		}
		p2 = p1;
		p1 = new Student;
		getInfomation(p1);
	}
	p2->next = nullptr;
	delete p1;
	return head;
}

void showList(Student *head) {

	while (head) {

		cout << "name： " << head->name << endl
			<< "studentId： " << head->stuNum << endl
			<< "subject： " << head->subject << endl
			<< "score： " << head->score << endl
			<< "phoneNumber： " << head->phoneNumber<<endl ;
		cout << "-----------------------" << endl;
		head = head->next;
	}

}

int main(int argv ,char *args[]) {

	int testNum;
	cout << "Pls input the number of student：";
	cin >> testNum;
	creat(testNum);
	showList(head);
	//string name;
	//cout << "pls input the name that you want to delete :";
	//cin >> name;

	deleteNode("Jack");
	showList(head);

	Student p;
	p.name = "Tompson";
	p.stuNum = "2015455777";
	p.subject = "math";
	p.score =85;
	p.phoneNumber = "55884445";
	insert(&p);
	showList(head);

	return 0;
}
