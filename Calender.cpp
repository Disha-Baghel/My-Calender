#include<iostream>

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
}calender;

int checkLeapYear(){
    if(calender.getYear()%400 == 0 || (calender.getYear()%100 != 0 && calender.getYear()%4 == 0)){
        return 1;
    }
    return 0;
}

int getNumberOfDays(int month, int year){
    // switch (month)
    // {
    // case 1: return 31;
    // case 2: if(checkLeapYear()==1)
    //             return 29;
    //         else
    //             return 28;
    // case 3: return 31;
    // case 4: return 30;
    // case 5: return 31;
    // case 6: return 30;
    // case 7: return 31;
    // case 8: return 31;
    // case 9: return 30;
    // case 10: return 31;
    // case 11: return 30;
    // case 12: return 31;      
    // default:
    //     return -1;
    // }
    if (month<=7){
        if(month%2 == 0 && month != 2) {
           return 30;
	    }
        else if (month == 2){
            if(checkLeapYear()==1)
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
    int rem = 0, t1, t2, y = calender.getYear();
    // calender.getYear() = calender.getYear() - 1000;
    calender.setYear();
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


const char *getDay(){
    int d = 0;
    if(calender.getMonth()<1 && calender.getMonth()>12){
        return ("invalid month");
    }
    if(calender.getDate()<1 && calender.getDate()>getNumberOfDays(calender.getMonth(), calender.getYear())){
        return ("Invalid Date");
    }
    if(calender.getYear()>=1000){
        d = getDayNumber(calender.getDate(), calender.getMonth(), calender.getYear());
    }
}
int main(){
    int choice;
    int date, month, year;
    // Calender calender;
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
        cout<<"Day : "<<getDay();
        break;

    default:
        ;
    }
}
