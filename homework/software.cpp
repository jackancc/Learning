
#include<iostream>
#include<string>

using namespace std;
class Date {
private:
    int year, month, day;
public:
    Date(int y, int m, int d) {
        Date::year = y;
        Date::month = m;
        Date::day = d;
    }

    Date() {}

    bool isLeapYear() {
        return (year%4 == 0 && year%100 != 0) || year%400 == 0;
    }

    void setDate(int year,int month,int day){
        Date::year=year;
        Date::month=month;
        Date::day=day;
    }

    int getYear() {
        return year;
    }

    int getMonth() {
        return month;
    }

    int getDay() {
        return day;
    }

    int getDayofYear() {
        int i, sum=day;
        int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

        if (isLeapYear())
            for(i=0;i<month;i++)   sum +=b[i];
        else
            for(i=0;i<month;i++)   sum +=a[i];

        return sum;
    }
};

class Software{
public:
    Software();
    Software(Software &another);
    ~Software();
    string getName();
    string getType();
    Date getDate();
    void setSoftwareDate(Date &rdate);
    void setInfo(string name,string type,string store);
    void showInfo();
private:
    string name;
    string type;
    Date deadTime;
    string store;

};

Software::Software() {}

Software::Software(Software &another) {
    name=another.name;
    type="B";
    store="H";
    deadTime=another.deadTime;

}

Software::~Software() {}

string Software::getName() {
    return name;
}

string Software::getType() {
    return type;
}

void Software::setInfo(string name, string type, string store) {
    Software::name=name;
    Software::type=type;
    Software::store=store;
}

void Software::setSoftwareDate(Date &rdate) {
    deadTime.setDate(rdate.getYear(),rdate.getMonth(),rdate.getDay());
}

void Software::showInfo() {
    cout<<"name:"<<name<<endl;
    if (type=="O") {
        type="original";
    } else if (type=="B") {
        type="backup";
    } else {
        type="trial";
    }
    cout<<"type:"<<type<<endl;

    if (store=="D") {
        store="optical disk";
    } else if (store=="U"){
        store="USB disk";
    } else {
        store="hard disk";
    }
    cout<<"media:"<<store<<endl;
}

Date Software::getDate() {
    return deadTime;
}

void showRestDay(int restDay,const int &k_day){
    if(restDay==-k_day){
        cout<<"this software has unlimited use"<<endl;
    } else if (restDay<0) {
        cout<<"this software has expired"<<endl;
    } else {
        cout<<"this software is going to be expired in "<<restDay<<" days"<<endl;
    }
}
int main(){
    int testNum;
    cin>>testNum;
    Date k_date;
    k_date.setDate(2015,4,7);
    const int  DAYOFLINE=k_date.getDayofYear();
    while  (testNum--){
        string name;
        string type;
        string store;
        int year;
        int month;
        int day;
        cin>>name>>type>>store
           >>year>>month>>day;
        Software sw1;
        sw1.setInfo(name,type,store);
        Date d1;
        d1.setDate(year,month,day);
        sw1.setSoftwareDate(d1);
        Software bk_sw1=sw1;
        sw1.showInfo();
        int restDay=sw1.getDate().getDayofYear()-DAYOFLINE;
        showRestDay(restDay,DAYOFLINE);
        Software sw2=sw1;
        sw2.showInfo();
        showRestDay(restDay,DAYOFLINE);
    }
    return 0;
}

