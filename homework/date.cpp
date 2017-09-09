#include<iostream>
#include<iomanip>
#include<cstdio>
using namespace std;

class Date{
private:
	int year;
	int month;
	int day;
public:
	Date();
	Date(int year,int month,int day);
	int getYear();
	int getMonth();
	int getDay();
	void setDate(int year,int month,int day);
	void printDate();
	void addOneDay();
};

Date::Date(){}
Date::Date(int year,int month,int day){
	Date::year=year;
	Date::month=month;
	Date::day=day;
}
int Date::getYear(){
	return year;
}
int Date::getMonth(){
	return month;
}
int Date::getDay(){
	return day;
}
void Date::setDate(int year,int month,int day){
	Date::year=year;
	Date::month=month;
	Date::day=day;
}
void Date::printDate(){
	printf("Today is %d/%02d/%02d\n",year,month,day);
}

void Date::addOneDay(){
	switch(month){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:if(day>0&&day<=30) day+=1; else{  month+=1;day=1;} break;
	case 4:
	case 6:
	case 9:
	case 11:if(day>0&&day<=29) day+=1; else{month+=1;day=1;} break;
	case 2:if(year%4==0&&year%100!=0||year%400==0){if (day>0&&day<=28) day+=1; else{month=3;day=1;}} else{if(day>0&&day<=27) day+=1;else{month=3;day=1;}}break;
	default:if(day>0&&day<=30) day+=1;else{ year+=1;month=1;day=1;}break;
	}
	printf("Tomorrow is %d/%02d/%02d\n",year,month,day);
}

int main(){
	int testNum;
	cin>>testNum;
	int t=testNum/2;
	while(t--){
		int year1,month1,day1;
		cin>>year1>>month1>>day1;
        Date d1(year1,month1,day1);
		d1.printDate();
        d1.addOneDay();

		int year2,month2,day2;
		cin>>year2>>month2>>day2;
		Date d2;
		d2.setDate(year2,month2,day2);
		d2.printDate();
		d2.addOneDay();
	}
	return 0;
}
