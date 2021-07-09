#include <iostream>
#include <string>
#include <conio.h>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;

double p1;
double t1;
double r1;
double n1;
string uinput;
bool isnum;
bool ischar;
string event;
string response = "y";
double independent_event(double &p, double &t, double &r, double &n, vector <int>fn, vector <int>fnr);
double dependent_event(double &p, double &t, double &r, double &n);
int calc_independent_event(double &p, double &t, double &r, double &n, vector <int>&fn, vector <int>&fnr, double &multiple, double &q);
void largeArrayFactorial();
double longDivideArrayNum(vector <int>&divisor, double &divisor_size, vector <int>&dividend, double &dividend_size);
double oldlongDivideArrayNum(vector <int>&divisor, double &divisor_size, vector <int>&dividend, double &dividend_size);
void longMultiplyArrayNum();
int multiply(double x,vector <int>&a ,int size);
int multiply_final(double x,vector <int>&a ,int size);
void printArrayNum(vector <int>ft);
void additionByTens(vector <int>&a, int sd);
double percentage;



bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}




int main() 
{
    while (response == "y")
    {
        cout << "Are these independent (a) or dependent events? (b)? ";
        cin >> event;
        while (true)
        {
            if (event == "a"){
                break;
                }
            if(event == "b") {
                break;
                }
            cout << "\nERROR: please enter valid selection: independent (a) or dependent events (b)? ";
            cout << "\nAre these independent (a) or dependent events? (b)? ";
            cin >> event;
        }
        if (event == "a")
        {
            while (true)
            {
                cout << "\nPlease enter the total number of trials (limit 300): ";
                cin >> uinput;
                isnum = isNumber(uinput);
                while (isnum == false)
                {
                    cout << "\nERROR: Please enter a valid number: ";
                    continue;
                }
                n1 = std::stod(uinput);
                while (n1 > 300)
                {
                    cout << "\nERROR: Number must be less than 301.";
                }
                break;
            }
            cout << "\nPlease enter the number of desired outcome(s): ";
            cin >> uinput;
            isnum = isNumber(uinput);
            while (isnum == false)
            {
                cout << "\nERROR: Please enter a valid number: ";
                cin >> uinput;
                isnum = isNumber(uinput);
            }
            p1 = std::stod(uinput);


            cout <<"\nPlease enter the total number of outcomes: ";
            cin >> uinput;
            isnum = isNumber(uinput);
            while (isnum == false)
            {
                cout << "\nERROR: Please enter a valid number: ";
                cin >> uinput;
                isnum = isNumber(uinput);
            }
            t1 = std::stod(uinput);

        
            while (p1 > t1)
            {
                cout << "\nERROR: number of desired outcomes, " << p1 << " cannot exceed total number of outcomes, " << t1;
                cout << "\nPlease enter the number of desired outcome(s): ";
                cin >> uinput;
                isnum = isNumber(uinput);
                while (isnum == false)
                {
                    cout << "\nERROR: Please enter a valid number: ";
                    cin >> uinput;
                    isnum = isNumber(uinput);
                }
                p1 = std::stod(uinput);


                cout <<"\nPlease enter the total number of outcomes: ";
                cin >> uinput;
                isnum = isNumber(uinput);
                while (isnum == false)
                {
                    cout << "\nERROR: Please enter a valid number: ";
                    cin >> uinput;
                    isnum = isNumber(uinput);
                }
                t1 = std::stod(uinput);
            }
            
            cout << "\nPlease enter the number of times you wish to obtain number of desired outcome(s): ";
            cin >> uinput;
            isnum = isNumber(uinput);
            while (isnum == false)
            {
                cout << "\nERROR: Please enter a valid number: ";
                cin >> uinput;
                isnum = isNumber(uinput);
            }
            r1 = std::stod(uinput);
            while (r1 > n1)
            {
                cout << "\nERROR: Number of times you wish to obtain number of desired outcome(s), " << r1 << ", cannot exceed the number of trials, " << n1;
                cout << ".\nPlease enter the number of times you wish to obtain number of desired outcome(s): ";
                cin >> uinput;
                isnum = isNumber(uinput);
                while (isnum == false)
                {
                    cout << "\nERROR: Please enter a valid number: ";
                    cin >> uinput;
                    isnum = isNumber(uinput);
                }
                r1 = std::stod(uinput);

                while (true)
                {
                    cout << "\nPlease enter the total number of trials (limit: 300): ";
                    cin >> uinput;
                    isnum = isNumber(uinput);
                    
                    while (isnum == false)
                    {
                        cout << "\nERROR: Please enter a valid number: ";
                        continue;
                    }
                    n1 = std::stod(uinput);
                    while (n1 > 300)
                    {
                        cout << "\nERROR: Number must be less than 301.\n";
                        continue;
                    }
                    break;
                }
            }
            vector <int> factn(1,1);
            vector <int> factnr(1, 1);
            independent_event(p1, t1, r1, n1, factn, factnr);
        }
        if (event == "b")
        {
            while (true)
            {
                cout << "\nPlease enter the total number of trials (limit 20): ";
                cin >> uinput;
                isnum = isNumber(uinput);
                if (isnum == false)
                {
                    cout << "\nERROR: invalid input!";
                    continue;
                }
                n1 = std::stod(uinput);
                if (n1 > 21)
                {
                    cout << "\nERROR: number must be less than 21.";
                    continue;
                }
                break;
            }
            
            cout <<"\nPlease enter the desired number of outcomes: ";
            cin >> uinput;
            isnum = isNumber(uinput);
            while (isnum == false)
            {
                cout << "\nERROR: Please enter a valid number: ";
                cin >> uinput;
                isnum = isNumber(uinput);
            }
            p1 = std::stod(uinput);

            cout <<"\nPlease enter the total number of outcomes: ";
            cin >> uinput;
            isnum = isNumber(uinput);
            while (isnum == false)
            {
                cout << "\nERROR: Please enter a valid number: ";
                cin >> uinput;
                isnum = isNumber(uinput);
            }
            t1 = std::stod(uinput);

            while ((p1 >= t1) || (t1 <= n1) )
            {
                cout << "\nERROR: total number of outcomes, " << t1 << ", must be bigger than desired outcomes, "<< p1 << ", but smaller than number of trials, " << n1;
                while (true)
                {
                    cout << "\nPlease enter the total number of trials (limit 20): ";
                    cin >> uinput;
                    isnum = isNumber(uinput);
                    if (isnum == false)
                    {
                        cout << "\nERROR: invalid input!\n";
                        continue;
                    }
                    n1 = std::stod(uinput);
                    if (n1 > 21)
                    {
                        cout << "\nERROR: number must be less than 21.";
                        continue;
                    }
                    break;
                }
                
                cout <<"\nPlease enter the desired number of outcomes: ";
                cin >> uinput;
                isnum = isNumber(uinput);
                while (isnum == false)
                {
                    cout << "\nERROR: Please enter a valid number: ";
                    cin >> uinput;
                    isnum = isNumber(uinput);
                }
                p1 = std::stod(uinput);

                cout <<"\nPlease enter the total number of outcomes: ";
                cin >> uinput;
                isnum = isNumber(uinput);
                while (isnum == false)
                {
                    cout << "\nERROR: Please enter a valid number: ";
                    cin >> uinput;
                    isnum = isNumber(uinput);
                }
                t1 = std::stod(uinput);
            }



            cout << "\nPlease enter the number of times you wish to obtain number of desired outcome(s): ";
            cin >> uinput;
            isnum = isNumber(uinput);
            while (isnum == false)
            {
                cout << "\nERROR: Please enter a valid number: ";
                cin >> uinput;
                isnum = isNumber(uinput);
            }
            r1 = std::stod(uinput);

            while (r1 > p1)
            {
                cout << "\nERROR: total number of times you wish to obtain number of desired outcome(s), " << r1 << ", cannot exceed total number of desired outcomes, " << p1 << ".";
                 cout <<"\nPlease enter the desired number of outcomes: ";
                cin >> uinput;
                isnum = isNumber(uinput);
                while (isnum == false)
                {
                    cout << "\nERROR: Please enter a valid number: ";
                    cin >> uinput;
                    isnum = isNumber(uinput);
                }
                p1 = std::stod(uinput);

                cout << "\nPlease enter the number of times you wish to obtain number of desired outcome(s): ";
                cin >> uinput;
                isnum = isNumber(uinput);
                while (isnum == false)
                {
                    cout << "\nERROR: Please enter a valid number: ";
                    cin >> uinput;
                    isnum = isNumber(uinput);
                }
                r1 = std::stod(uinput);
            }
            vector <int> factn(1,1);
            vector <int> factnr(1, 1);
            percentage = dependent_event(p1,t1,r1,n1);
            cout << "\nanswer is " << percentage << "%\n";
        }
        cout << "\n\nWould you like to calculate another probability? (y) or (n): ";
        cin >> response;
        while (true)
        {
            if (response == "y")
            {
                break;
            }
            if (response == "n")
            {
                break;
            }
            cout << "\nInvalid input!";
            cout << "\nWould you like to calculate another probability? (y) or (n): ";
        }
    }
    return 0;
}


double independent_event(double &p, double &t, double &r, double &n, vector <int>fn, vector <int>fnr) {
    string a1;
    double p1 = (*&p/ *&t);
    double q = (1 - p1);
    double percentage = 0;
    double multiple;
    vector <int> hundred(3, NULL);
    hundred[0] = 0;
    hundred[1] = 0;
    hundred[2] = 1;
    double hundred_size = 3;
    cout << "\nAt least (a), at most (b) or exact (c)? ";
    cin >> a1;
    while (true) 
    {
        if (a1 == "a")
        {
            break;
        }
        if (a1 == "b")
        {
            break;
        }
        if (a1 == "c")
        {
            break;
        }
        cout << "\nERROR; please enter valid selection: at least (a), at most (b), or exact (c) ";
        cin >> a1;
    }
    if (a1 == "c")
    {
        int fin_dec_place = calc_independent_event(p1, t, r, n, fn, fnr,multiple, q);
        cout << "\n\nThe answer is: ~";
        bool improbable_check = true;
        bool definite_check = true;
        if (fn.size() >= fin_dec_place)
        {
            for (int j = (fn.size() - 1); j >= (fn.size() - 3); j--)
            {
                if (fn[j] > 0)
                {
                    improbable_check = false;
                }
                if (fn[j] < 9)
                {
                    definite_check = false;
                }
                cout << fn[j];
                if (j == (fin_dec_place))
                {
                    cout <<".";
                }
            }
        }
        else
        {
            cout << ".";
            for (int i = (fin_dec_place - fn.size()); i > 0; i--)
            {
                cout << "0";
            }
            for (int j = (fn.size() - 1); j >= 0; j--)
            {
                if (fn[j] > 0)
                {
                    improbable_check = false;
                }
                if (fn[j] < 9)
                {
                    definite_check = false;
                }
                cout << fn[j];
            }
        }
        cout << "% ";
         if (improbable_check)
        {
            cout << " (chances are virtually zero)";
        }
        if (definite_check)
        {
            cout << " (chances are practically 100%)";
        }
        cout << "\n\n"; 
        return percentage;
    }


    if (a1 == "a")
    {
        double final_answer = 0;
        string final2string;
        while (*&r <= *&n)
        {
            string bresult = "";
            double b2num;
            vector <int> fn(1,1);
            vector <int> fnr(1, 1);

            int fin_dec_place = calc_independent_event(p1, t, r, n, fn, fnr,multiple, q);
            for (int i = (fn.size() - 1); i >= 0; i--)
            {
                bresult += to_string(fn[i]);
                
            }
            if (bresult.size() < fin_dec_place)
            {
                for (int i = 0; i < fin_dec_place; i++)
                {
                    bresult.insert(bresult.begin(), '0');
                }
                *&r += 1;
                // continue;
            }
            fin_dec_place = bresult.size() - fin_dec_place;
            bresult.insert(fin_dec_place, ".");
            b2num = std::stod(bresult);
            final_answer += b2num;
        *&r += 1;
        }
        int exponent = 1;
        final_answer = final_answer * pow(10,1);
        int int_fa = 0;
        int_fa += final_answer;
        while (true)
        {
            if (int_fa > 0)
            {
                break;
            }
            else
            {
                exponent ++;
                final_answer = final_answer * pow(10,1);
                int_fa = 0;
                int_fa += final_answer;
            }
        }
        int_fa+= 1;
        final_answer = int_fa;
        final_answer = final_answer / pow(10,exponent);
        cout << "\n\nthe answer is";
        if (final_answer > 99)
        {
            cout << " over 99%!\n\n";
        }
        else
        {
            cout << ": ~" << final_answer << "%\n\n";
        }
        return percentage;
    }


    if (a1 == "b")
    {
        double final_answer = 0;
        string final2string;
        while (*&r >= 0)
        {
            string bresult = "";
            double b2num;
            vector <int> fn(1,1);
            vector <int> fnr(1, 1);

            int fin_dec_place = calc_independent_event(p1, t, r, n, fn, fnr,multiple, q);
            for (int i = (fn.size() - 1); i >= 0; i--)
            {
                bresult += to_string(fn[i]);
                
            }
            if (bresult.size() < fin_dec_place)
            {
                for (int i = 0; i < fin_dec_place; i++)
                {
                    bresult.insert(bresult.begin(), '0');
                }
                *&r -= 1;
                // continue;
            }
            fin_dec_place = bresult.size() - fin_dec_place;
            bresult.insert(fin_dec_place, ".");
            b2num = std::stod(bresult);
            final_answer += b2num;
        *&r -= 1;
        }
        int exponent = 1;
        final_answer = final_answer * pow(10,1);
        int int_fa = 0;
        int_fa += final_answer;
        while (true)
        {
            if (int_fa > 0)
            {
                break;
            }
            else
            {
                exponent ++;
                final_answer = final_answer * pow(10,1);
                int_fa = 0;
                int_fa += final_answer;
            }
        }
        int_fa+= 1;
        final_answer = int_fa;
        final_answer = final_answer / pow(10,exponent);
        cout << "\n\nthe answer is";
        if (final_answer > 99)
        {
            cout << " over 99%!\n\n";
        }
        else
        {
            cout << ": ~" << final_answer << "%\n\n";
        }
    }
    return percentage;
}

double dependent_event(double &p, double &t, double &r, double &n) {
    string a1;
    int index_0;
    int index_1;
    int index_2;
    cout << "\nAt least (a), at most (b) or exact (c)? ";
    cin >> a1;
    while (true) 
    {
        if (a1 == "a")
        {
            break;
        }
        if (a1 == "b")
        {
            break;
        }
        if (a1 == "c")
        {
            break;
        }
        cout << "\nERROR; please enter valid selection: at least (a), at most (b), or exact (c) ";
        cin >> a1;
    }
    int trial = 0;
    int final_calculations = 6;
    int chances_losing = (*&t - *&p);
    int size;
    double answer = 0;
    double y;
    double x;
    vector <double> calculations(6, 1);
    vector <double> temp_calc(6, 1);
    while (trial < *&n)
    {
        if (trial == 0)
        {
            calculations[0] = double(*&p / *&t);
            calculations[1] = 1;
            calculations[2] = 0; 
            calculations[3] = (*&p / *& t);
            calculations[4] = 0;
            calculations[5] = 1;
            trial += 1;
            temp_calc.clear();
            continue;
        }
        for (int i = 0; i < calculations.size(); i++)
        {
            temp_calc.push_back(calculations[i]);
        }
        calculations.clear();
        size = temp_calc.size();
        for (int i = 0; i < size / 3; i++)
        {
            index_0 = (0 + (i * 3)); 
            index_1 = (1 + (i * 3));
            index_2 = (2 + (i*3));
            y = temp_calc[index_0] * ((chances_losing - temp_calc[index_2]) / (*&t - trial));
            calculations.push_back(y);
            calculations.push_back(temp_calc[index_1]);
            calculations.push_back(temp_calc[index_2] + 1);
            x = temp_calc[index_0] * ((chances_losing - temp_calc[index_1]) / (*&t - trial));
            calculations.push_back(x);
            calculations.push_back(temp_calc[index_1]+ 1);
            calculations.push_back(temp_calc[index_2]);
        }
        trial += 1;
        temp_calc.clear();
    }
    if (a1 == "c")
    {
        size = calculations.size();
        for (int i = 0; i < size / 3; i++)
        {
            index_0 = (0 + (i * 3)); 
            index_1 = (1 + (i * 3));
            if (calculations[index_1] == *&r)
            {
                answer += calculations[index_0];
            }
        }
    }
    if (a1 == "a")
    {
        size = calculations.size();
        for (int i = 0; i < size / 3; i++)
        {
            index_0 = (0 + (i * 3)); 
            index_1 = (1 + (i * 3));
            if (calculations[index_1] >= *&r)
            {
                answer += calculations[index_0];
            }
        }
    }
    if (a1 == "b")
    {
        size = calculations.size();
        for (int i = 0; i < size / 3; i++)
        {
            index_0 = (0 + (i * 3)); 
            index_1 = (1 + (i * 3));
            if (calculations[index_1] <= *&r)
            {
                answer += calculations[index_0];
            }
        }
    }
    return answer;
}


double longDivideArrayNum(vector <int>&divisor, double &divisor_size, vector <int>&dividend, double &dividend_size)
{
    int size_difference = (dividend_size - divisor_size) - 1;
    int temp_size_difference = 0;
    temp_size_difference += size_difference;
    int leftover;
    int carry;
    int zero_counter;
    vector <int> answer(1,0);
    string stranswer;
    zero_counter = 0;
    carry = 0;
    int check = 0;
    int temp_i;
    int str2int;
    string indchar;
    for (int i = 0; i < size_difference; i++)
    {
        answer.insert(answer.begin(), 0);
    }
    for (int i = 0; i < size_difference; i++)
    {
        divisor.insert(divisor.begin(), 0);
        divisor_size +=1;
    }
    while (dividend_size >= divisor_size)
    {
        
        if (dividend_size == divisor_size)
        {
            for (int i = divisor_size; i <= 0; i--)
            {
                if (divisor[i] > dividend[i])
                {
                    check = 1;
                    break;
                }
                
            }
        }
        if (check == 1)
        {
            break;
        }
        else
        {
            additionByTens(answer, size_difference);
            for (int i = 0; i < divisor_size; i++)
            {
                temp_i = 0;
                if (divisor[i] > dividend[i])
                {
                    leftover = divisor[i] - dividend[i];
                    leftover = 10 - leftover;
                    dividend[i] = leftover;
                    temp_i = i + 1;
                    while (true)
                    {
                        if (dividend[temp_i] > 0)
                        {
                            dividend[temp_i] -= 1;
                            break;
                        }
                        else
                        {
                            dividend[temp_i] = 9;
                            temp_i += 1;
                        }
                    }
                    
                }
                else
                {
                    dividend[i] -= divisor[i];
                }
            }
            for (int i = (dividend_size - 1); i >= 0; i--)
            {
                if (dividend[i] == 0)
                {
                    dividend.pop_back();
                    dividend_size -= 1;
                    if (size_difference >= 1)
                    {
                        divisor.erase(divisor.begin());
                        divisor_size -= 1;
                        size_difference-= 1;
                    }
                }
                else
                {
                    break;
                }
            
            }  
        }
    }
    dividend.clear();
    for (int i = 0; i < answer.size(); i++)
    {
        dividend.insert(dividend.begin(),answer[i]);
    }
    dividend_size = dividend.size();
    int dp = dividend_size - temp_size_difference;
    return dp;
}


int multiply(double x,vector <int>&a ,int size)
{
   x = floor(x * 1000);
    int carry=0,i,p;
    for(i=0;i<size;++i)
    {
        p=a[i]*x+carry;
        a[i]=p%10;
        carry=p/10;
    }
    while(carry!=0)
    {
        a.push_back((carry%10));
        carry=carry/10;
        size++;
    } 
    a.erase(a.begin());
    a.erase(a.begin());
    a.erase(a.begin());
    size--;
    size--;
    size--;
    return size;
}


int multiply_final(double x,vector <int>&a ,int size)
{
    size = a.size();
    bool exponent_found = false;
    std::ostringstream streamObj2;
    streamObj2 << x;
    std::string strObj2 = streamObj2.str();
    string exponent = "";
    int exponent2num;
    for (int i = 0; i < (strObj2.size() - 1); i++)
    {
        if (strObj2[i] == '-')
        {
            exponent_found = true;
            i++;
            exponent+= strObj2[i];
            i++;
            exponent+= strObj2[i];
            break;
        } 
        continue;
    }
    if (exponent_found)
    {
        exponent2num = std::stoi(exponent);
    }
    else
    {
        exponent2num = size;
    }
    x = floor(x * pow(10,(exponent2num + 2)));
    int carry=0,i,p;
    for(i=0;i<size;++i)
    {
        p=a[i]*x+carry;
        a[i]=p%10;
        carry=p/10;
    }
    while(carry!=0)
    {
        a.push_back((carry%10));
        carry=carry/10;
        size++;
    } 
    exponent2num++;
    exponent2num++;
    return exponent2num;
}

int calc_independent_event(double &p, double &t, double &r, double &n, vector <int>&fn, vector <int>&fnr, double &multiple, double &q)
{
    double factn_size, factnr_size;
    factn_size = 1;
    factnr_size = 1;
    
    for(double i=2;i<=*&n;++i)
    {
        if (i <= *&r)
        {
            continue;
        }
        factn_size = multiply(i,fn,factn_size);
    }
    int nr;
    nr = (*&n - *&r);
    for(double i=2;i<=nr;++i)
    {
        factnr_size = multiply(i,fnr,factnr_size);
    }
    int dec_place = longDivideArrayNum(fnr, factnr_size, fn, factn_size);
    multiple  = pow(*&p, *&r) * pow(q, (*&n - *&r)) * 100;
    int fin_dec_place = multiply_final(multiple, fn, factn_size);
    return fin_dec_place;
}

void printArrayNum(vector <int>ArrayNum)
{
    cout << "\nAMOUNT OF DIGITS:" << ArrayNum.size() <<"\n";
    for (int i = (ArrayNum.size() - 1); i >= 0; i--)
    {
        cout << ArrayNum[i];
    }
    cout << "\n\n";
}


void additionByTens(vector <int>&a, int sd)
{
    string straddition = "1";
    for (int i = 0; i < sd; i++)
    {
        straddition+= "0";
    }
    int carry = 1;
    int INDEX_NUMBER = a.size() - straddition.size();
    int size = 0;
    size+= straddition.size();
    while (true)
    {
        if (carry == 0)
        {
            break;
        }
        else
        {
            carry--;
            if (a[INDEX_NUMBER] == 9)
            {
                carry ++;
                a[INDEX_NUMBER] = 0;
                size++;
                if (size > a.size())
                {
                    a.insert(a.begin(),1);
                    break;
                }
                else
                {
                    INDEX_NUMBER--;
                    continue;
                }
            }
            else
            {
                a[INDEX_NUMBER]++;
                continue;
            }
        }
    }
}

double oldlongDivideArrayNum(vector <int>&divisor, double &divisor_size, vector <int>&dividend, double &dividend_size)
{
    int size_difference = (dividend_size - divisor_size) - 1;
    int temp_size_difference = 0;
    temp_size_difference += size_difference;
    int leftover;
    int carry;
    int zero_counter;
    long long int answer;
    answer = 0;
    string stranswer;
    zero_counter = 0;
    carry = 0;
    int check = 0;
    int temp_i;
    int str2int;
    string indchar;
    for (int i = 0; i < size_difference; i++)
    {
        divisor.insert(divisor.begin(), 0);
        divisor_size +=1;
    }
    while (dividend_size >= divisor_size)
    {
        if (dividend_size == divisor_size)
        {
            for (int i = divisor_size; i <= 0; i--)
            {
                if (divisor[i] > dividend[i])
                {
                    check = 1;
                    break;
                }
                
            }
        }
        if (check == 1)
        {
            break;
        }
        else
        {
            answer += 1* pow(10, size_difference);
            for (int i = 0; i < divisor_size; i++)
            {
                temp_i = 0;
                if (divisor[i] > dividend[i])
                {
                    leftover = divisor[i] - dividend[i];
                    leftover = 10 - leftover;
                    dividend[i] = leftover;
                    temp_i = i + 1;
                    while (true)
                    {
                        if (dividend[temp_i] > 0)
                        {
                            dividend[temp_i] -= 1;
                            break;
                        }
                        else
                        {
                            dividend[temp_i] = 9;
                            temp_i += 1;
                        }
                    }
                    
                }
                else
                {
                    dividend[i] -= divisor[i];
                }
            }
            for (int i = (dividend_size - 1); i >= 0; i--)
            {
                if (dividend[i] == 0)
                {
                    dividend.pop_back();
                    dividend_size -= 1;
                    if (size_difference >= 1)
                    {
                        divisor.erase(divisor.begin());
                        divisor_size -= 1;
                        size_difference-= 1;
                    }
                }
                else
                {
                    break;
                }
            
            }  
        }
    }
    stranswer = to_string(answer);
    dividend.clear();
    for (int i = (stranswer.length() - 1); i >= 0; i--)
    {
        indchar = stranswer[i];
        str2int = std::stoi(indchar);
        dividend.push_back(str2int);
    }
    dividend_size = dividend.size();
    int dp = dividend_size - temp_size_difference;
    return dp;
}
