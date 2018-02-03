////////////////////////////////////////////////////////////////////////////////
//
//  Author:         Ibrahim Sardar
//  Class:          CSCI 363
//  Filename:       Client.cpp
//  Date:           11/17/2017
//  Description:    Main implementation for Client class.
//
////////////////////////////////////////////////////////////////////////////////
//
//  Honor Pledge:
//
//  I pledge that I have neither given nor received any help on this assignment.
//
//  ibsardar
//
////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2017 Copyright Holder All Rights Reserved.
//
////////////////////////////////////////////////////////////////////////////////

//
// (resources)
//
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include "Expression_Node.h"
#include "Expression_Tree_Builder.h"
#include "Expression_Tree_Evaluator.h"
#include "Client.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

//
//  run
//
void Client::run() {

    // user input expression
    string exp;

    // user input expression list
    Queue< Array<string> > exp_queue;

    // builder for infix_to_postfix
    Expression_Tree_Builder builder;

    // evaluator for expression tree
    Expression_Tree_Evaluator evaluator;

    // menu - obtain user input expressions
    cout << "\nWelcome to the Multiple Expression Calculator! (now using better design patterns!)" << endl;
    cout << "Instructions:" << endl;
    cout << "\t- Type \"QUIT\" on a seperate line to end your input." << endl;
    cout << "\t- Separate each operator/operand with a space." << endl;
    cout << "\nEnter your expressions:" << endl;
    while(true) {

        // user input string
        std::getline(cin, exp);
        if (exp == "QUIT")
            break;

        // parse expression into an Array
        Array<string> infix = this->parse(exp);

        // enqueue valid expression, exception if invalid
        if (this->is_valid(infix))
            exp_queue.enqueue(infix);
        else
            cout << "Invalid expression format: last input was ignored." << endl;
    }

    // for each expression...
    while(!exp_queue.is_empty()) {

        // get postifx queue from dequeued infix expression
        Array<string> arr = exp_queue.dequeue();
        Queue<string> postfix = this->infix_to_postfix(arr);

        // edge case: single number input
        if (postfix.size() == 1) {
            cout << "Result: " << postfix.dequeue() << endl;
            continue;
        }

        // build and get expression tree from postfix queue
        builder.build_expression(postfix);
        Expression_Node * tree = builder.get_expression();

        try {

            // get result
            int result = evaluator.evaluate(tree);

            // print result
            cout << "Result: " << result << endl;

        // check for math errors
        } catch (std::exception & e) {

            // print exception error and notify
            cout << e.what() << endl;
            cout << "(a result was ignored...)" << endl;
        }

        // free tree memory
        delete tree;
    }

    // wait then quit
    cout << "Press any key to quit." << endl;
    cin.ignore();
}

//
//  parse
//
Array<string> Client::parse(string infix) {

    // helper variables
    std::stringstream ss;
    string token;
    Queue<string> items;

    // tokenize string
    ss.clear();
    ss.str(infix);
    while(getline(ss, token, ' '))
        items.enqueue(token);

    // resultant infix array
    Array<string> infix_array(items.size());

    // pop all queue items into infix array
    for (int i=0; i<infix_array.size(); i++) {
        infix_array[i] = items.dequeue();
    }

    // return infix expression
    return infix_array;
}

//
//  is_integer
//
bool Client::is_integer(string str) {

    // convert string to char array for compatability with strtol
    const char * character_list = str.c_str();

    // this pointer will be used with the above character array
    // like the reading head in a turing machine
    char * ptr_to_last_consumed_character;

    // number's base
    // (10 is for base10 as 2 is for binary/base2)
    int radix = 10;

    // try to convert the character array to a base10 int
    long value = std::strtol(character_list, &ptr_to_last_consumed_character, radix);

    // if the starting character is invalid
    // (i.e. not a '+', '-', nor a digit)
    if (ptr_to_last_consumed_character == character_list) {

        // invalid number
        return false;

    // if the string begins with a number but is
    // interrupted by some invalid character before
    // reaching the end of the string
    } else if (*ptr_to_last_consumed_character != '\0') {

        // invalid number
        return false;

    // all characters are valid number characters
    } else {

        // if the number is larger than or smaller than the
        // maximum or minimum possible values of an integer
        if ((int)value != value) {

            // invalid integer
            return false;

        // if the number is within the bounds of the maximum
        // or minimum possible values of an integer
        } else {

            // valid integer
            return true;
        }
    }
}

//
//  is_valid
//
bool Client::is_valid(Array<string> & infix) {

    // # of opened parenthesis
    int opened = 0;

    // 0: nothing
    // 1: left-parenthesis
    // 2: right-parenthesis
    // 3: operator
    // 4: operand
    int last_type = 0;

    // while looping through infix array, check for the following:
    // - balanced parenthesis
    // - proper operand/operator/parenthesis placement
    for (int i=0; i<infix.size(); i++) {

        // check for integer
        if (this->is_integer(infix[i])) {

            // invalid format if integer follows a
            // right-parenthesis or an operand
            if (last_type == 2 || last_type == 4)
                return false;

            // mark current item as operand
            last_type = 4;

        // check for a 1 character string
        } else if (infix[i].size() == 1) {

            // check for operator or parenthesis
            switch (infix[i][0]) {

                case '(':

                    // increment number of opened parenthesis
                    opened++;

                    // invalid format if left-parenthesis follows a
                    // right-parenthesis or an operand
                    if (last_type == 2 || last_type == 4)
                        return false;

                    // mark current item as left-parenthesis
                    last_type = 1;

                    // get out of the switch statement
                    break;

                case ')':

                    // decrement number of opened parenthesis
                    opened--;

                    // invalid format if right-parenthesis is the first
                    // item or follows a left-parenthesis or an operator
                    if (last_type == 0 || last_type == 1 || last_type == 3)
                        return false;

                    // mark current item as right-parenthesis
                    last_type = 2;

                    // get out of the switch statement
                    break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '%':

                    // invalid format if any of the above operators is the
                    // first item or follows a left-parenthesis or an operator
                    if (last_type == 0 || last_type == 1 || last_type == 3)
                        return false;

                    // mark current item as operator
                    last_type = 3;

                    // get out of the switch statement
                    break;

                default:

                    // if none of the above characters was found, the
                    // current item must be an invalid character
                    return false;
            }

        // else it is a non-integer item of a size longer than 1
        } else {

            // invalid item
            return false;
        }
    }

    // if last item is "(" or some operator,
    // then we have an invalid expression
    if (last_type == 1 || last_type == 3)
        return false;

    // if opened is more than zero, we have too many "(",
    // if opened is less than zero, we have too many ")"
    if (opened != 0)
        return false;

    // if the checks survived up to here, expression format must be valid
    return true;
}

//
//  get_precedence
//
int Client::get_precedence(std::string op) {

    // return appropriate precedence
    // (smaller value == higher precedence)
    if (op == "%" || op == "/" || op == "*")
        return 2;
    else if (op == "-" || op == "+")
        return 1;
    else
        return 0;
}

//
//  infix_to_postfix
//
Queue<string> Client::infix_to_postfix(Array<string> & infix) {

    // easier to push into than Array
    Queue<string> postfix_queue;

    // used to help convert infix to postfix
    Stack<string> postfix_stack;

    // go through infix item-by-item
    for (int i=0; i<infix.size(); i++) {

        //
        // CASE 1 - open parenthesis
        //
        if (infix[i] == "(")

            // place next item on the stack
            postfix_stack.push(infix[i]);

        //
        // CASE 2 - close parenthesis
        //
        else if (infix[i] == ")") {

            // pop stack until we reach the start of this parenthesis
            while (postfix_stack.top() != "(") {

                // transfer top item into queue
                postfix_queue.enqueue(postfix_stack.top());
                postfix_stack.pop();
            }

            // don't forget to pop that open parenthesis!
            postfix_stack.pop();
        }

        //
        // CASE 3 - operators
        //
        else if (infix[i] == "+" || infix[i] == "-" || infix[i] == "*" ||
                infix[i] == "/" || infix[i] == "%") {

            // if stack is empty
            if (postfix_stack.is_empty()) {

                // push onto stack
                postfix_stack.push(infix[i]);

            // if stack contains operators or parenthesis
            } else {

                // note: higher precedence means more important
                // pop until precedence of stack top is less than current item
                // or if stack becomes empty
                while (!postfix_stack.is_empty() &&
                        this->get_precedence(postfix_stack.top()) >= this->get_precedence(infix[i])) {

                    // pop the top into the queue
                    postfix_queue.enqueue(postfix_stack.top());
                    postfix_stack.pop();
                }

                // push current item onto stack
                postfix_stack.push(infix[i]);
            }
        }

        //
        // CASE 4 - numbers
        //
        else

            // output number into queue
            postfix_queue.enqueue(infix[i]);
    }

    // empty the rest of the stack into the queue
    while (!postfix_stack.is_empty()){

        // pop the top into the queue
        postfix_queue.enqueue(postfix_stack.top());
        postfix_stack.pop();
    }

    // return postfix expression
    return postfix_queue;
}
