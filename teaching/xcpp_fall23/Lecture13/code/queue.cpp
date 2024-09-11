#include <iostream>
#include <queue>
#include <string>

int main()
{
    std::queue<std::string> str_queue;

    str_queue.push("string1");
    str_queue.push("string2");
    str_queue.push("string3");

    std::cout << "the size of the queue is: " << str_queue.size() << std::endl;
    std::cout << "the front one " << str_queue.front() << std::endl;
    std::cout << "the back one " << str_queue.back() << std::endl;

    str_queue.pop();
    std::cout << "the front one " << str_queue.front() << std::endl;

    str_queue.pop();
    std::cout << "the front one " << str_queue.front() << std::endl;

    str_queue.pop();

    if (str_queue.empty())
        std::cout << "the queue is empty!" << std::endl;

    return 0;
}
