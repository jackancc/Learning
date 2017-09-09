#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct Task {
	int id;
	string  task1;
	string  task2;
	string  task3;
};
int isCopy(Task* ,Task*);

int main() {
	int testNum;
	cin >> testNum;
	Task *info = new Task[testNum];
	Task *t1, *t2;
	t1 = info;
	t2 = t1 + 1;
	for (int i = 0; i < testNum; i++) {
		cin >> info[i].id
			>> info[i].task1
			>> info[i].task2
			>> info[i].task3;
	}
	for (int i = 0; i < testNum - 1; i++,t1++) {
		t2 = t1 + 1;
		for (int j = i + 1; j < testNum; j++,t2++) {
			if (isCopy(t1, t2)) {
				cout << t1->id << " " << t2->id << " " << isCopy(t1, t2) << endl;
			}

		}
	}


	return 0;
}

int  isCopy(Task *ts1,Task *ts2) {
	// string类的末端什么都没有，只能选取短字符串的长度进行比较
	//char类型的字符串会有\0作为结束符
	int len11 = (ts1->task1).length();
	int len12 = (ts2->task1).length();
	int len21 =(ts1->task2).length();
	int len22 = (ts2->task2).length();
	int len31 = (ts1->task3).length();
	int len32 = (ts2->task3).length();   
	int count1 = 0, count2 = 0, count3 = 0;
	int len1 = len11 > len12 ? len12 : len11;
	int len2 = len21 > len22 ? len22 : len21;
	int len3 = len31 > len32 ? len32 : len31;


	for (int i = 0; i <=len1; i++) {
		if (ts1->task1[i] == ts2->task1[i]) {
			count1++;
		}
	}
	for (int i = 0; i <= len2; i++) {
		if (ts1->task2[i] == ts2->task2[i]) {
			count2++;
		}
	}
	for (int i = 0; i <=len3; i++) {
		if (ts1->task3[i] == ts2->task3[i]) {
			count3++;
		}
	}

	if (double(count1 / len1) > 0.9)
		return 1;
	else if (double(count2 / len2)>0.9)
		return 2;
	else if (double(count3 / len3)>0.9)
		return 3;
	else
		return 0;

}
