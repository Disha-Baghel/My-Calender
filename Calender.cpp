#include<iostream>
//#include "dayOfWeek.h"

using namespace std;
class Calender{
    int date;
    int month;
    int year;
    public:
    void setData(int date, int month, int year){
        this->date = date;
        this->month = month;
        this->year = year;
    }
    int getDate(){ return this->date; }
    int getMonth(){ return this->month; }
    int getYear(){ return this->year; }
    void setYear(){ this->year = this->year - 1000; }

    const char* Zellercongruence(){
    if (month == 1) {
        month = 13;
        year--;
    }
    if (month == 2) {
        month = 14;
        year--;
    }
    int q = date;
    int m = month;
    int k = year % 100;
    int j = year / 100;
    int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    h = h % 7;
    switch (h) {
        case 0:
        return "Saturday";
        case 1:
        return "Sunday";
        case 2:
        return "Monday";
        case 3:
        return "Tuesday";
        case 4:
        return "Wednesday";
        case 5:
        return "Thursday";
        case 6:
        return "Friday";
        }
        return 0;
    }

    void printDate(){
        cout<<"-----------------\n";
        switch(month){
            case 1: cout<<"January"; break;
            case 2: cout<<"February"; break;
            case 3: cout<<"March"; break;
            case 4: cout<<"April"; break;
            case 5: cout<<"May"; break;
            case 6: cout<<"June"; break;
            case 7: cout<<"July"; break;
            case 8: cout<<"August"; break;
            case 9: cout<<"September"; break;
            case 10: cout<<"October"; break;
            case 11: cout<<"November"; break;
            case 12: cout<<"December"; break;
        }
        cout<<", "<<year;
        cout<<"\n---------------------\n";
    }

    void printMonth(int x, int y){
        int nod, day, cnt, d = 1, x1 = x, y1 = y, isNote = 0;
        if(!(month>=1 && month<=12)){
            cout<<"Invalid Month";
            return ;
        } 
        if(!(year >=1600)){
            cout<<"Invalid Month";
            return ;
        }
        printDate();
        y += 3;
        cout<<"S    M    T    W    Th    F    S\n";
        y++;
        nod = getNumberOfDays(month, year);
        day = getDayNumber(d, month, year);
        switch(day){
            case 0: 
            x=x;
            cnt =1;
            break;
            case 1: 
            x = x + 4;
            cnt = 2;
            break;
            case 2: 
            x = x + 8;
            cnt = 3;
            break;
            case 3:
            x = x + 12;
            cnt = 4;
            break;
            case 4: 
            x = x + 16;
        }

    }

};

int checkLeapYear(int year){
    if(year%400 == 0 || (year%100 != 0 && year%4 == 0)){
        return 1;
    }
    return 0;
}

int getNumberOfDays(int month, int year){
    if (month<=7){
        if(month%2 == 0 && month != 2) {
           return 30;
	    }
        else if (month == 2){
            if(checkLeapYear(year)==1)
                return 29;
            else
                return 28;
        }
        else{
            return 31;
        }
    }
    else{
        if(month%2 == 0){
            return 31;
        }
        else{
            return 30;
        }
    }
}

int getDayNumber(int date, int month, int year){
    int rem = 0, t1, t2, y = year;
    // calender.getYear() = calender.getYear() - 1000;
    year = year - 1600;
    while (year >= 100)
    {
        rem = rem + 5;
        year = year - 100;
    }
    rem = rem%7;
    t1 = (year-1)/4;
    t2 = year-1-t1;
    t1 = t1*2 + t2;
    t1 = t1%7;
    rem = rem + t1;
    rem = rem % 7;
    t2 = 0;
    for(t1 = 1; t1<month; t1++){
        t2 += getNumberOfDays(t1, y);
    }
    t2 = t2 + date;
    t2 = t2 % 7;
    rem = rem + t2;
    rem = rem % 7;
    if(y > 2000)
        rem = rem + 1;
    rem = rem % 7;
    return rem;
}

// const char* getName(int day){
//     switch (day){
//         case 3: return "Sunday";
//         case 4: return "Monday";
//         case 5: return "Tuesday";
//         case 6: return "Wednesday";
//         case 7: return "Thursday";
//         case 1: return "Friday";
//         case 2: return "Saturday";
//         default: return "Error";
//     }
// }

// const char *getDay(){
//     int d = 0;
//     if(calender.getMonth()<1 && calender.getMonth()>12){
//         return ("invalid month");
//     }
//     if(calender.getDate()<1 && calender.getDate()>getNumberOfDays(calender.getMonth(), calender.getYear())){
//         return ("Invalid Date");
//     }
//     if(calender.getYear()>=1000){
//         d = getDayNumber(calender.getDate(), calender.getMonth(), calender.getYear());
//         d = d%7;
//         return (getName(d));
//     }
//     else{
//         return ("Please give year more 1000");
//     }
// }

int main(){
    int choice;
    int date, month, year;
    char ch = 'a';
    Calender calender;
    cout<<"Press 1 to find out the day"<<endl;
    cout<<"Press 2 to print all the day of month"<<endl;
    cout<<"Press 3 to add note"<<endl;
    cout<<"Press 4 to exit"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"Enter date (DD MM YYYY) : ";
        cin>>date>>month>>year;
        calender.setData(date, month, year);
        cout<<"Day : "<<calender.Zellercongruence();
        break;
    case 2: 
        cout<<"Enter month and year (MM YYYY) : ";
        cin>>month>>year;
        while(ch != 'q'){
            calender.printMonth(20, 5);
        }

    default:
        ;
    }
}
