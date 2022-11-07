#include<iostream>
#include<fstream>
#include<string>

//#include"month.h"
//#include "dayOfWeek.h"

using namespace std;
int getNumberOfDays(int , int);
int getDayNumber(int, int ,int);
class Calender{
    int date;
    int month;
    int year;
    int firstDay;
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
    if (month == 1){
        month = 13;
        year--;
    }
    if (month == 2){
        month = 14;
        year--;
    }
    int q = date;
    int m = month;
    int k = year % 100;
    int j = year / 100;
    int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    h = h % 7;
    firstDay = h;
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
        cout<<"----------------\n";
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
        cout<<", "<<year<<endl;
    }

    void showNote(){
        string line;
        char c;
        ifstream fin;
        fin.open(to_string(year)+"\\"+to_string(month)+"\\"+to_string(date)+".txt");
        if(fin.eof()){ 
            cout<<"No note"; 
            return ;
        }
        while(getline(fin, line)){
        cout<<line<<endl;
        }
        fin.close();
    }

   void printMonth(){
        if(!(month>=1 && month<=12)){
            cout<<"Invalid Month";
            return ;
        } 
        if(!(year >= 1600)){
            cout<<"Invalid Year";
            return ;
        }
        printDate();
        Zellercongruence();
        cout<<"----------------------------------------------------"<<endl;
        cout<<"S\tM\tT\tW\tTh\tF\tS\n";
        cout<<"----------------------------------------------------"<<endl;

        for(int i = 1; i < firstDay; i++){
            cout<<"\t";
        }
        for(int j = 1; j<=getNumberOfDays(month, year); j++){
            if(((j+firstDay-2)%7==0) ) //j!=1
                cout<<endl;
            cout<<j<<"\t";
        }
        cout<<endl;
        cout<<"----------------------------------------------------\n";
        
    }



    void addnote(){
        string line;
        ofstream fout;
        // cout<<"Enter date (DD MM YYYY) : ";
        // cin>>date>>month>>year;
        fout.open(to_string(year)+"\\"+to_string(month)+"\\"+to_string(date)+".txt", ios::app );
        fout<<date<<"."<<month<<"."<<year<<endl;
        cout<<"Enter the note\n";
        while(fout){
            getline(cin, line);
            fout<<line;
            if(line == ".")
            break;
        }
        cout<<"note saved successfully";
        fout.close();

    }

    void increase_month(){
        ++month;
        if(month>12){
            ++year;
            month = month - 12;
        }
    }

    void decrease_month(){
        --month;
        if(month<1){
            if(year<1600){
                cout<<"No record available";
                return ;
            }
            month = month + 12;
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
    else if(month>7){
        if(month%2 == 0){
            return 31;
        }
        else{
            return 30;
        }
    }
}


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
    switch (choice){
    case 1:
        cout<<"Enter date (DD MM YYYY) : ";
        cin>>date>>month>>year;
        calender.setData(date, month, year);
        cout<<"Day : "<<calender.Zellercongruence();
        break;
    case 2: 
        cout<<"Enter month and year (MM YYYY) : ";
        cin>>month>>year;
        calender.setData(1, month, year);
        calender.printMonth();
        while(ch != 'q'){
            
            cout<<"Press 'n' to Next, Press 'p' to Previous, Press 's' to show note or Press 'q' to Quit"<<endl;
            cin>>ch;
            if(ch=='n'){
                calender.increase_month();
                calender.printMonth();
            }
            else if(ch=='p'){
                calender.decrease_month();
                calender.printMonth();
            }
            else if(ch=='s'){
                calender.showNote();
            }
        }
        break;
        case 3:
        cout<<"Enter date (DD MM YYYY): ";
        cin>>date>>month>>year;
        calender.setData(date, month, year);
        calender.addnote();
        break;
        default: 
           ;
    }
}
    
