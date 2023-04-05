// program to perform NFA in c++
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
using namespace std;

class Transition
{
public:
    string str;
    int cnt;
    string *list;

    // a function to tokenize the string and store it in the list
    void strTokenize()
    {
        comma();
        char *cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());
        char *p = strtok(cstr, ","); // in strtok() first parameter has t0 be a character array
        int i = 0;
        list = new string[cnt];
        // tokenize the string and create a list of states for that symbol
        while (p != 0)
        {
            list[i] = p;
            i++;
            p = strtok(NULL, ",");
        }
    }

    void showList()
    {
        for (int i = 0; i < cnt; i++)
            cout << list[i] << " ";
    }

private:
    // function to count the comma (',') in the entered set of states
    void comma()
    {
        cnt = 1;
        size_t found = str.find(',');
        while (found != string::npos)
        {
            cnt++;
            found = str.find(',', found + 1);
        }
    }
};

int main()
{
    Transition **trans;
    int nos;
    string *states, *final, str, input, temp[nos], current[nos];
    char *alf;
    int nofs, noa, i, j, k, x, y, z, f, flag, cnt, temp_last, curr_last;

    cout << "Enter the total number of states and the "
         << "number of final states :\n";
    cin >> nos >> nofs;
    states = new string[nos];
    final = new string[nofs];
    cout << "Enter the states (enter the start state first)\n";
    for (i = 0; i < nos; i++)
        cin >> states[i];
    cout << "Enter the final states\n";
    for (i = 0; i < nofs; i++)
        cin >> final[i];

    cout << "Enter the number of symbols in the alphabet : ";
    cin >> noa;
    alf = new char[noa];
    cout << "Enter the symbols for the alphabet:\n";
    for (i = 0; i < noa; i++)
        cin >> alf[i];

    // allocating space for the transition table
    trans = new Transition *[nos];
    for (j = 0; j < nos; j++)
        trans[j] = new Transition[noa];

    // retrieving the information for transition table
    cout << "Enter the information for the transition table"
         << " (enter t when no move is possible from the given state) :\n";
    for (i = 0; i < nos; i++)
    {
        cout << "Write the transitions for state " << states[i] << endl;
        for (j = 0; j < noa; j++)
        {
            cout << "On input symbol " << alf[j] << ": ";
            cin >> trans[i][j].str;
            trans[i][j].strTokenize();
        }
    }
    cout << endl
         << "the transition table entered by you is :\n";
    for (i = 0; i < nos; i++)
    {
        for (j = 0; j < noa; j++)
        {
            trans[i][j].showList();
            cout << "\t\t";
        }
        cout << endl;
    }

    // this array of strings will contain the states that are currently being considered
    while (true)
    {
        cout << "\nEnter the input string (enter exit to stop the program) : ";
        cin >> input;
        if (input == "exit")
            exit(0);

        curr_last = 0;
        current[curr_last] = states[0]; // initialising the current state with the start state
        for (i = 0; i < input.length(); i++)
        {
            // getting the index of the alphabet symbol
            for (j = 0; j < noa; j++)
                if (alf[j] == input[i])
                    break;

            // processing of the input string by the NFA

            /*  first for an input we will pop off from the current
                then we will scan all the transitions from that state for the input symbol
                then we will add these transition to the temp variable if it was not previously present
                finally we will replace the values in current with the values in temp
                curr_last has to be updated accordingly
                index of the alphabet symbol is stored in j
                Transition is T[current_state_being scanned][j]
            */

            // to get the current states number scan states[k]

            temp_last = 0;

            for (k = 0; k <= curr_last; k++)
            { // loop for scanning the transitions from every state in current
                if (current[k] == "t")
                    continue;
                for (x = 0; x < nos; x++)
                    if (states[x] == current[k])
                        break;
                cnt = trans[x][j].cnt;
                for (y = 0; y < cnt; y++)
                { // iterating the list of transitions
                    str = trans[x][j].list[y];
                    flag = 0;
                    for (z = 0; z < temp_last; z++)
                    { // checking whether the state is already present in the temp[]
                        if (str == "t")
                        {
                            flag = 1;
                            break;
                        }
                        if (temp[z] == str)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0)
                        temp[temp_last++] = str;
                }
                // updating the current and curr_last
            }

            for (y = 0; y <= temp_last; y++)
                current[y] = temp[y];
            curr_last = temp_last - 1; // as the last increment was not required
        }

        f = 0;
        // loop checking for acceptance
        for (i = 0; i <= curr_last; i++)
        {
            for (j = 0; j < nofs; j++)
                if (final[j] == current[i])
                {
                    cout << "\n----The string has been accepted----\n";
                    f = 1;
                    break;
                }
            if (f == 1)
                break;
        }

        if (f == 0)
            cout << "\n----The string has been rejected----\n";
    }
    return 0;
}