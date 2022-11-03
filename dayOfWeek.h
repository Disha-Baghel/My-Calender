//Zeller's Rule
//Formula Used
//F = k+[(13*m-1)/5+D+[D/4]+[C/4]-2*C]
//Where 
//k is the day of the month
//m is the month number
//D is the last two digits of the year
//C is the first two digits of the year

// #include <cmath>
// #include <cstring>
// #include <iostream>
// using namespace std;
 
const char* Zellercongruence(int day, int month, int year)
{
    if (month == 1) {
        month = 13;
        year--;
    }
    if (month == 2) {
        month = 14;
        year--;
    }
    int q = day;
    int m = month;
    int k = year % 100;
    int j = year / 100;
    int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    h = h % 7;
    switch (h) {
    case 0:
        //cout << "Saturday \n";
        return "Saturday";
        break;
    case 1:
        //cout << "Sunday \n";
        return "Sunday";
        break;
    case 2:
        //cout << "Monday \n";
        return "Monday";
        break;
    case 3:
        //cout << "Tuesday \n";
        return "Tuesday";
        break;
    case 4:
        //cout << "Wednesday \n";
        return "Wednesday";
        break;
    case 5:
        //cout << "Thursday \n";
        return "Thursday";
        break;
    case 6:
        //cout << "Friday \n";
        return "Friday";
        break;
    }
    return 0;
}
 
// // Driver code
// int main()
// {
//     Zellercongruence(22, 10, 2017); // date (dd/mm/yyyy)
//     return 0;
// }