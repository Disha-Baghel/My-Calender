#include<iostream>
#include<fstream>
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

    void printMonth(){
        if(!(month>=1 && month<=12)){
            cout<<"Invalid Month";
            return ;
        } 
        if(!(year >=1600)){
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
            if(((j+firstDay-2)%7==0) && (j!=1))
                cout<<endl;
            cout<<j<<"\t";
        }
        cout<<endl;
        cout<<"----------------------------------------------------\n";
    }

    void addnote(){
    //     FILE *fp;
    //     ofstream fout;
        
    // fp = fopen("note.dat","ab+");
    // system("cls");
    // printf("Enter the date(DD/MM): ");
    // scanf("%d%d",&R.dd, &R.mm);
   
    // printf("Enter the Note(50 character max): ");
    // fflush(stdin);
    // scanf("%[^\n]",R.note);
    // if(fwrite(&R,sizeof(R),1,fp)){
    //     gotoxy(5,12);
    //     puts("Note is saved sucessfully");
    //     fclose(fp);
    // }else{
        
    //     puts("\aFail to save!!\a");
        
    // }
    
    // printf("Press any key............");
    
    // fclose(fp);
    string line;
    ofstream fout;
    fout.open("note.txt");
    while(fout){
        getline(cin, line);
        if(line == "-1");
        break;
    }
    cout<<"note saved successfully";
    fout.close();

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

void showNote(){
    string line;
    ifstream fin;
    fin.open("note.txt");
    while(getline(fin, line)){
        if(line==NULL){
            
        }
        cout<<line<<endl;
    }
    fin.close();
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
        calender.setData(1, month, year);
        while(ch != 'q'){
            calender.printMonth();
            cout<<"Press 'n' to Next, Press 'p' to Previous or Press 'q' to Quit"<<endl;
            cin>>ch;
            if(ch=='n'){
                increase_month();
                calender.printMonth();
            }
            else if(ch=='p'){
                decrease_month();
                calender.printMonth();
            }
            else if(ch=='s'){
                showNote();
            }
        }
        break;
        case 3:
        calender.addnote();
        break;
    default: 
        ;
    }
}
    
