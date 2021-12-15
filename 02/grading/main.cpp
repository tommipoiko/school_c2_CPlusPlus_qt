#include <iostream>
#include <cmath>

using namespace std;

// Before passing automated tests, do not touch the values of the following
// constants, even if they differ from those you see in Plussa.
// At the end of the course, if you use this program to count your final grade,
// you should update the constants to make them identical with those in Plussa.
unsigned int MAX_N_POINTS = 780;
unsigned int MAX_G_POINTS = 100;


int base_points(int n, int g, int p)
{
    int base_grade = 0;

    if ((n + g)/88 > n/78) {
        if ( (n+g)/88 < 5 || p < 51) {
               base_grade = 0;
           } else if ( (n+g)/88 < 6 ) {
               base_grade = 1;
           } else if ( (n+g)/88 < 7 ) {
               base_grade = 2;
           } else if ( (n+g)/88 < 8 ) {
               base_grade = 3;
           } else if ( (n+g)/88 < 9 ) {
               base_grade = 4;
           } else {
              base_grade = 5;
           }
    } else {
        if ( (n)/78 < 5 || p < 51) {
               base_grade = 0;
           } else if ( (n)/78 < 6 ) {
               base_grade = 1;
           } else if ( (n)/78 < 7 ) {
               base_grade = 2;
           } else {
            base_grade = 2;
           }
    }

    return base_grade;
}

int pro_points(int p)
{
    int pro_grade = 0;

    if ( p < 75) {
            pro_grade = 1;
        } else if (p < 125) {
            pro_grade = 2;
        } else if (p<150) {
            pro_grade = 3;
        } else if (p<175) {
            pro_grade = 4;
        } else {
            pro_grade = 5;
        }

    return pro_grade;
}

int grade_points(int base_grade, int pro_grade, int e, int g)
{
    float grade = 0;

    float x = ((float)base_grade + (float)pro_grade + (float)e) / 3;
    grade = round(x);

    if ( g < 30 && grade > 2 ) {
           grade = 2;
       } else if (g < 40 && grade > 3 ) {
           grade = 3;
       } else if (g < 50 && grade > 4 ) {
           grade = 4;
       }

    if (e == 0) {
        if (grade > 2) {
            grade -= 2;
        } else {
            grade = 1;
        }
    }

    return grade;
}

int main()
{
    unsigned int n = 0;
    unsigned int g = 0;
    unsigned int p = 0;
    unsigned int e = 0;
    cout << "Enter N points, G points, P points: ";
    cin >> n;
    cin >> g;
    cin >> p;
    cout << "Enter exam grade (if no exam, enter zero): ";
    cin >> e;

    int base_grade = base_points(n, g, p);
    if (base_grade == 0) {
        cout << "The final grade is " << base_grade << endl;
        return 0;
    }

    int pro_grade = pro_points(p);

    int grade = grade_points(base_grade, pro_grade, e, g);

    cout << "The final grade is " << grade << endl;

    return 0;
}
