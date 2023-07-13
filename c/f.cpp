#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

string stk = "z";
map<string, map<char, map<char, pair<string, function<void()>>>>> transitions;

void pushA()
{
    stk += "aa";
}

void nothing() {}

void pushAZ()
{
    stk += "za";
}

void pushZ()
{
    stk += "z";
}

void initializeTransitions()
{
    // Transitions for q0 state
    transitions["q0"]['0']['z'] = make_pair("q0", pushAZ);
    transitions["q0"]['0']['a'] = make_pair("q0", pushA);
    transitions["q0"]['1']['z'] = make_pair("q0", pushAZ);
    transitions["q0"]['1']['a'] = make_pair("q0", pushA);
    transitions["q0"]['C']['z'] = make_pair("q1", nothing);

    // Transitions for q1 state
    transitions["q1"]['0']['a'] = make_pair("q1", nothing);
    transitions["q1"]['1']['a'] = make_pair("q1", nothing);
    transitions["q1"]['C']['a'] = make_pair("q2", pushZ);

    // Transitions for reject states
    transitions["q0"]['C']['z'] = make_pair("reject", nothing);
    transitions["q0"]['C']['a'] = make_pair("reject", nothing);
    transitions["q0"]['C']['b'] = make_pair("reject", nothing);

    transitions["q1"]['0']['z'] = make_pair("reject", nothing);
    transitions["q1"]['0']['a'] = make_pair("reject", nothing);
    transitions["q1"]['0']['b'] = make_pair("reject", nothing);
    transitions["q1"]['1']['z'] = make_pair("reject", nothing);
    transitions["q1"]['1']['a'] = make_pair("reject", nothing);
    transitions["q1"]['1']['b'] = make_pair("reject", nothing);
}

int PDA(string input_string, bool print_output)
{
    input_string += 'C';
    string current_state = "q0";
    string running_string;

    for (char i : input_string)
    {
        pair<string, function<void()>> transition;
        try
        {
            transition = transitions[current_state][i][stk.back()];
        }
        catch (const exception &e)
        {
            cout << "rejected" << endl;
            return 1;
        }
        current_state = transition.first;
        if (print_output)
        {
            running_string += i;
            cout << string(80, '-') << endl;
            cout << "Running String: " << running_string << endl;
            cout << "String Read: " << i << endl;
            cout << "Current State: " << current_state << endl;
        }
        if (current_state == "accepted")
        {
            cout << "accepted" << endl;
            return 1;
        }
        else if (current_state == "q2")
        {
            cout << "Accepted" << endl;
            if (print_output)
            {
                cout << "Stack: " << stk << endl;
            }
            return 0;
        }
        function<void()> exe = transition.second;
        stk.pop_back();
        exe();
        if (print_output)
        {
            cout << "Stack: " << stk << endl;
        }
    }

    // If the loop ends without reaching a final state, it's rejected
    cout << "rejected" << endl;
    return 1;
}

int main()
{
    initializeTransitions();

    string input_string;
    cout << "Please Enter the string:" << endl;
    cin >> input_string;
    cout << "\t\tFOR THE STRING " << input_string << ":" << endl;

    // Check if the input string contains invalid characters
    bool hasInvalidCharacter = false;
    for (char c : input_string)
    {
        if (c != '0' && c != '1')
        {
            hasInvalidCharacter = true;
            cout << "Invalid character: " << c << endl;
            break;
        }
    }

    if (!hasInvalidCharacter)
    {
        PDA(input_string, true);
    }
    else
    {
        cout << "rejected" << endl;
    }

    return 0;
}
