#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int getNumberOfDays(int , int);
class Calendar{
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
    int getDate(){ 
        return this->date; 
    }
    int getMonth(){ 
        return this->month; 
    }
    int getYear(){ 
        return this->year; 
    }

    /*
    For the Gregorian calendar Zeller's Congruence rule is: 
     h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j
     h is the day of the week (0 = Saturday, 1 = Sunday, 2 = Monday, …, 6 = Friday)
     q is the day of the month
     m is the month (3 = March, 4 = April, 5 = May, …, 14 = February)
     K is the year of the century (year % 100).
     J is the zero-based century (actually ⌊ year/100 ⌋)
    */
    
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
        fin.open(to_string(year)+"\\"+to_string(month)+".txt");
        if(!fin){ 
            cout<<"No note"<<endl; 
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

        if(firstDay==0){
            for(int i=1; i < 7; i++)
            cout<<"\t";
        }
        else{
            for(int i = 1; i < firstDay; i++){
            cout<<"\t";
            }
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
        fout.open(to_string(year)+"\\"+to_string(month)+".txt", ios::app );
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
    if (month<=7 ||  month == 13 || month == 14){
        if(month%2 == 0 && month != 2 && month !=14) {
           return 30;
	    }
        else if (month == 2 || month == 14){
            if(checkLeapYear(year)==1)
                return 29;
            else
                return 28;
        }
        else{
            return 31;
        }
    }
    else if(month>7 && month!=13 && month != 14){
        if(month%2 == 0){
            return 31;
        }
        else{
            return 30;
        }
    }
    return 0;
}

int main(){
    int choice;
    int date, month, year;
    char ch = 'a';
    char c;
    Calendar calendar;
    do{
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
                calendar.setData(date, month, year);
                cout<<"Day : "<<calendar.Zellercongruence();
                break;
            case 2: 
                cout<<"Enter month and year (MM YYYY) : ";
                cin>>month>>year;
                calendar.setData(1, month, year);
                calendar.printMonth();
                while(ch != 'q'){
                    cout<<"Press 'n' to Next, Press 'p' to Previous, Press 's' to show note or Press 'q' to Quit"<<endl;
                    cin>>ch;
                    if(ch=='n'){
                        calendar.increase_month();
                        calendar.printMonth();
                    }
                    else if(ch=='p'){
                        calendar.decrease_month();
                        calendar.printMonth();
                    }
                    else if(ch=='s'){
                        calendar.showNote();
                    }
                }
                break;
            case 3:
                cout<<"Enter date (DD MM YYYY): ";
                cin>>date>>month>>year;
                calendar.setData(date, month, year);
                calendar.addnote();
                break;
            case 4:
                cout<<"Thankyou for using calender!!";
                exit(0);
                break;
            default:
                cout<<"Wrong Choice"<<endl;
        }
        cout<<"\nDo you want to continue ? (y/n)"<<endl;
        cin>>c;
        if(c=='n'|| c=='N')
            cout<<"Thankyou for using Calender!!";
    }while(c=='y'|| c=='Y');
    return 0;
}