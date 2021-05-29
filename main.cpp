#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Bipartite_graph
{
    int  w[100][100], option;
public:
    int number_of_vertexes, vcolor[100], counter=0;
    bool check = false;
    void inputMatrix();
    void coloring(int);
    bool promising(int);
    void print();
};


void Bipartite_graph::inputMatrix()
{
    bool check_input = true;
    while (check_input)
    {
        cout << "How do you want to input number: \n";
        cout << "1. Manual\n2. Random automatic\n";
        cout << "Your option: ";
        cin >> option;
        cout << "--------------------------------\n";
        if (option == 1 || option == 2)
            check_input = false;
    }

    int flag = true;
    while (flag)
    {
        cout << "How many vertex you have(at least 3): ";
        cin >> number_of_vertexes;
        if (number_of_vertexes < 3)
            cout << "\nthe number is under 3\n";
        else
            flag = false;
    }
        w[number_of_vertexes][number_of_vertexes];


        if (option == 1)
        {
            cout << "\n*** Please enter your Adjacency matrix ***\n";
            for (int i=0; i<number_of_vertexes-1; i++)
            {
                for (int j=i+1; j<number_of_vertexes; j++)
                {
                    cout << "\tEnter element [" << i+1 << "][" << j+1 << "] = ";
                    cin >> w[i][j];
                    w[j][i] = w[i][j];
                }
                cout << "\t------------------------\n";
            }
        }


        if (option == 2)
        {
            int counter_one=0;
            bool connectivity = true;
            srand (time(NULL));
            while(connectivity) //If the graph isn't connectivity set graph again
            {
                for (int i=0; i<number_of_vertexes; i++)
                {
                    for (int j=0; j<number_of_vertexes; j++)
                    {
                        w[i][j] = rand() % 2;
                        if (w[i][j] == 1)
                            counter_one++;  //counting the number of edges
                        w[j][i] = w[i][j];
                    }
                    w[i][i] = 0;    // in adjacency matrix main diameter has to be 0
                }

                // If the number of edges is less than number of vertexes set graph again
                if (counter_one < number_of_vertexes-1)
                {
                    counter_one = 0;
                    connectivity = true;
                }
                else
                    connectivity = false;
            }
        }
}


void Bipartite_graph::coloring(int i)
{
    int color;
    if (promising(i))
    {
        if (i == number_of_vertexes-1)
        {
            check = true;
            cout << "\n\n\t*** The color of each vertex is: ***\n";
            cout << "\t------------------------------------\n";
            for (int j=0; j<number_of_vertexes; j++)
            {
                cout << "\t   Vertex " << j+1 << " -------> color " << vcolor[j] << endl;
                counter++;  //counter variable is used for exiting recursive functions
            }
        }
        else
            for (color=1; color<=2; color++)
            {
                vcolor[i+1] = color;
                coloring(i+1);
            }
    }
}


bool Bipartite_graph::promising(int i)
{
    if (check)
        return false;
    int j=0;
    bool flag = true;
    while (j<i && flag)
    {
        // there is a edge between vertex[i] & vertex[j] and they have a same color
        if (w[i][j] && vcolor[i] == vcolor[j])
            flag = false;
        j++;
    }
    return flag;
}


void Bipartite_graph::print()
{
    cout << "\n\n\t*** Your adjacency matrix is: ***\n";
    cout << "\t----------------------------------\n";
    for (int i=0; i<number_of_vertexes; i++)
    {
        cout << "\t";
        for (int j=0; j<number_of_vertexes; j++)
        {
            cout << w[i][j] << "\t";
        }
        cout << endl;
    }
}


int main()
{
    int vcolor[1]; // for bipartite graph we need two color
    Bipartite_graph E;
    E.vcolor[0] = 1;    //coloring first vertex
    E.inputMatrix();
    E.print();
    E.coloring(0);
    if (E.counter == E.number_of_vertexes)
        cout << "\n\t** This is a Bipartite graph **\n";
    else
        cout << "\n\t** This is NOT a Bipartite graph **\n\n";

    cout << "\n\n\t  -----------------------\n";
    cout << "\t | Student: Erfan Riahi  |\n\t | Student ID: 971490031 |\n\t | Year: 2020            |\n";
    cout << "\t  -----------------------";
    return 0;
}
