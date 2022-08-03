// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

using namespace std;

int ThreadVar1 = 0;
int ThreadVar2 = 0;
bool DidQuit = false;

void HelloWorldThread1()
{
    while (!DidQuit)
    {
        ThreadVar1++;
        if (ThreadVar1==1000)
        {
            ThreadVar1 = 0;
        }
    }
}
void HelloWorldThread2()
{
    while (!DidQuit)
    {
        ThreadVar2++;
        if (ThreadVar2 == 1000)
        {
            ThreadVar2 = 0;
        }
    }
}
int main()
{
    cout << "Hello World!\n";
    char UserInput;
    thread thread1(HelloWorldThread1);
    thread thread2(HelloWorldThread2);
    while (!DidQuit)
    {
        cout << "Enter 1 or 2  to view that thread or 3 to view both or q to quit" << endl;
        cin >> UserInput;
        if (UserInput == '1')
        {
            cout << "ThreadVar1: " << ThreadVar1 << endl;
        }
        else if (UserInput == '2')
        {
            cout << "ThreadVar2: " << ThreadVar2 << endl;
        }
        else if (UserInput == '3')
        {
            cout << "ThreadVar1: " << ThreadVar1 << endl;
            cout << "ThreadVar2: " << ThreadVar2 << endl;
        }
        else if (UserInput=='q')
        {
            DidQuit = true;
            cout << "ThreadVar1: " << ThreadVar1 << endl;
            cout << "ThreadVar2: " << ThreadVar2 << endl;
        }
    }
    thread1.join();
    thread2.join();
    return 0;

}