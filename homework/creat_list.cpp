#include<iostream>
#include<string>
using namespace std;

struct Student{
	string id;
double score;

   Student *next;
};

Student * creat(int testNum) {
	Student *head, *pS, *pE;
	head = nullptr;
	while (testNum--) {
		string id;
		double score;
		cin >> id >> score;
		pS = new Student;
		pS->id = id;
		pS->score = score;
		if (!head) {
			head = pS;
		}
		else {
			pE->next = pS;	
		}
		pE = pS;
	}
	pS->next = nullptr;
	return head;
}

void showList(Student *head) {
	while (head) {
		cout << "id:" << head->id << endl;
		cout << "score:" << head->score << endl;
		cout << "------------------" << endl;
		head = head->next;
	}
}





int main(int argv, char *args[]) {
		int testNum;
		cin >> testNum;
		showList(creat(testNum));

		return 0;
	}




