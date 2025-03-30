#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <iostream>
#include "math.h"
using namespace std;
int fract_nod(int a, int b) {
    if (b == 0) return a;
    return fract_nod(b, a % b);
}
class Fraction {
public:
    int numer, denom;

    Fraction(int n = 0, int d = 1) {
        numer = n;
        denom = d;
    }

    Fraction reduce() {
        int a = max(abs(numer), abs(denom)), b = min(abs(numer), abs(denom));
        int sgn;
        if (numer * denom >= 0) sgn = 1;
        else sgn = -1;
        int nod = fract_nod(a, b);
        return Fraction(sgn * (abs(numer) / nod), abs(denom) / nod);
    }

    void show() {
        cout << "\t" << numer;
        if (denom != 1) cout << "/" << denom;
    }

    Fraction operator + (Fraction& other) {
        return
            Fraction(
                numer * other.denom + denom * other.numer,
                denom * other.denom
            ).reduce();
    }

    Fraction operator - (Fraction& other) {
        Fraction a(numer, denom);
        Fraction b(-other.numer, other.denom);
        return a + b;
    }

    Fraction operator * (Fraction& other) {
        return
            Fraction(
                numer * other.numer, denom * other.denom
            ).reduce();
    }

    Fraction operator / (Fraction& other) {
        Fraction a(numer, denom);
        Fraction b(other.denom, other.numer);
        return a * b;
    }
};
Fraction input(string& s) {
    int n = 0, d = 0, deg = 0;
    int slash_pos = s.find('/');
    if (slash_pos != s.npos) {
        int i = slash_pos - 1;
        while (i > -1) {
            if (s[i] != '-')
                n += (s[i] - 48) * pow(10, deg++);
            else
                n = -n;
            i--;
        }
        deg = 0;
        i = s.size() - 1;
        while (i > slash_pos) {
            if (s[i] != '-')
                d += (s[i] - 48) * pow(10, deg++);
            else
                d = -d;
            i--;
        }
    }
    else {
        d = 1;
        int i = s.size() - 1;
        while (i > -1) {
            if (s[i] != '-')
                n += (s[i] - 48) * pow(10, deg++);
            else
                n = -n;
            i--;
        }
    }
    Fraction f;
    if (d) f = Fraction(n, d).reduce();
    else f = Fraction(n);
    return f;
}

void inputMatrix(vector<vector<Fraction>>& matrix)
{
    int rows = 0;
    int cols = 0;
    cout << "Rows " << endl;
    cin >> rows;
    cout << "Cols " << endl;
    cin >> cols;
    matrix.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix[i].resize(cols);
    }
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < cols; i++)
        {
            cout << "Input (" << j << " ," << i << " )" << endl;
            cin >> matrix[j][i].numer;
            matrix[j][i].denom = 1;
        }
    }
}

int main()
{

    vector<vector<Fraction>> matrix = {};
    inputMatrix(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j].numer << '/' << matrix[i][j].denom << ' ';
        }
        cout << "end" << endl;
    }
    int basicRow = 0;
    int basicCol = 0;
    int countBasic = 0;
    while (1)
    {
        cout << "Row " << countBasic << endl;
        cin >> basicRow;
        cout << "Col " << countBasic << endl;
        cin >> basicCol;
        if (basicRow == -1) break;
        countBasic++;
        Fraction buf = matrix[basicRow][basicCol];
        for (int i = 0; i < matrix[0].size(); i++)
        {
            matrix[basicRow][i] = matrix[basicRow][i] / buf;
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            if (i != basicRow)
            {
                Fraction del = matrix[i][basicCol];
                matrix[i][basicCol] = { 0,1 };
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    if (j != basicCol)
                    {
                        Fraction a = matrix[basicRow][j] * del;
                        matrix[i][j] = matrix[i][j] - a;
                    }
                }
            }
            //printf("DEBUG");
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                cout << matrix[i][j].numer << '/' << matrix[i][j].denom << ' ';
            }
            cout << "end" << endl;
        }
    }
    return 0;
}