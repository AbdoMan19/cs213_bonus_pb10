#include "bits\stdc++.h"
using namespace std;
class MonthError: public exception
{
public:
    const char* what() const throw()
    {
        return "Month Error";
    }
};
class DayError: public exception
{
public:
    const char* what() const throw()
    {
        return "Day Error";
    }
};
string convertMonth(int month)
{
    switch(month)
    {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
    }
}
void convertDate(string date) throw(MonthError, DayError)
{
    int month{0},day{0};
    for(int i=0;i<date.size();i++){
        if(date[i]=='/'){
            month=stoi(date.substr(0,i));
            day=stoi(date.substr(i+1,date.size()-i-1));
            break;
        }

    }
    if(month < 1 || month > 12) {
        MonthError i;
        throw i;
    }
    if(month == 2 && day > 29) {
        DayError i;
        throw i;
    }
    if(day < 1 || day > 31) {
        DayError i;
        throw i;
    }
    cout << convertMonth(month) << " " << day << endl;
}
int main()
{
    string  date;
    cin >>date;
    try
    {
        convertDate(date);
    }
    catch(MonthError &e)
    {
        cout << e.what() << endl;
    }
    catch(DayError &e)
    {
        cout << e.what() << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;

}