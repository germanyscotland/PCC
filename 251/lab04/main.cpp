/*
 * JEREMY SKOGLAND
 * MARCH 5 2021
 * CS 251 NEFT
 * LAB 4
 *
 */

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    cout << "=========================" << endl;
    cout << "=====JEREMY SKOGLAND=====" << endl;
    cout << "=======CS 251 NEFT=======" << endl;
    cout << "==========LAB 4==========" << endl;
    cout << "=========================" << endl;

    string tempMatrixRow;
    string space = " ";
    int spaceIndex;
    string matrix[10][10];
    int i = 0;
    int j = 0;
    int k = 0;
    int numVertices = 0;

    cout << "Enter WAM Please." << endl;

    getline (cin, tempMatrixRow);

    while (tempMatrixRow != "" || k < 9)
    {
        spaceIndex = tempMatrixRow.find(space);
        matrix[0][numVertices++] = tempMatrixRow.substr(0, spaceIndex);
        tempMatrixRow = tempMatrixRow.substr(spaceIndex+1, tempMatrixRow.back());
        k++;
        if (spaceIndex == -1)
            break;
          }

    for (int p = 1; p < numVertices; p++)
    {
        int q = 0;
        k = 0;
        cin.clear();
        getline (cin, tempMatrixRow);

        while (tempMatrixRow != "" || k < 9)
        {
            spaceIndex = tempMatrixRow.find(space);
            matrix[p][q++] = tempMatrixRow.substr(0, spaceIndex);
            tempMatrixRow = tempMatrixRow.substr(spaceIndex+1, tempMatrixRow.back());
            k++;
            if (spaceIndex == -1)
                break;
        }
    }

    cout << endl
         << "The WAM Entered is:" << endl;

    cout << setw(5);
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
        cout << matrix[i][j] << setw(5);
        }
        cout << endl;
    }
    cout << endl;




cout << "The output from Prim's algorithm is:" << endl;

    int min = 9999999;
    int minI = 0;
    int minJ = 0;
    int mst[numVertices][numVertices];

    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
            mst[i][j] = 0;
    }

    for (i = 0; i < numVertices; i++)
    {
        for (j = i; j < numVertices; j++)
        {
            string weight = matrix[i][j];
            stringstream prim(weight);
            int wt = 0;
            prim >> wt;

            if (wt < min && wt != 0)
            {
                min = wt;
                minI = i;
                minJ = j;
            }
        }
        mst[minI][minJ] = min;
        mst[minJ][minI] = min;
        min = 9999999;
    }

    cout << setw(5);
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            cout << mst[i][j] << setw(5);
        }
        cout << endl;
    }
    cout << endl;

}

