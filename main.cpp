#include<iostream>
#include"queue.h"



int main(int argc, char* argv[])
{
    std::cout<<"stl wrapping queue test start"<<std::endl;

    kmj::stl_wrapping_queue<int> s1;
    for (int i = 0; i < 20; i++)
    {
        s1.enqueue(i); //problem with enqueue
    }
    std::cout << "Size: " << s1.size() << std::endl;
    s1.dequeue();      //problem with dequeue
    s1.dequeue();      //problem with dequeue
    std::cout << "Size after dequeue: " << s1.size() << std::endl;
    std::cout << "Front: " << s1.front() << std::endl;
    std::cout << "Back: " << s1.back() << std::endl;

    system("pause");

    return 0;
}