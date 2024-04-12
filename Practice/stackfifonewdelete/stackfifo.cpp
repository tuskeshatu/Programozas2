// Old C style struct implementation

/*
struct stack
{
    int elements;
    int *pData;
};

void push(stack &s, int value)
{
    int *newData = new int[s.elements + 1];
    for (int i = 0; i < s.elements; i++)
    {
        newData[i] = s.pData[i];
    }
    newData[s.elements] = value;
    delete[] s.pData;
    s.pData = newData;;;
    s.elements++;
}

int pop(stack &s)
{
    if (s.elements == 0)
    {
        // Stack is empty, handle the error accordingly
        // For example, throw an exception or return a default value
    }
    int value = s.pData[s.elements - 1];
    s.elements--;
    int *newData = new int[s.elements];
    for (int i = 0; i < s.elements; i++)
    {
        newData[i] = s.pData[i];
    }
    delete[] s.pData;
    s.pData = newData;
    return value;
}
*/

namespace datastructs
{
    
} // namespace datastructs


// My own Stack

#include <initializer_list>
#include <algorithm>
#include <stdexcept>

class Stack
{
private:
    size_t elements; // Number of elements in the stack
    int *pData;      // Pointer to the dynamic array storing the elements

public:
    Stack() : elements(0), pData(nullptr) {} // Default constructor

    Stack(const std::initializer_list<const int> init_list) : elements(init_list.size()) // Constructor with initializer list
    {
        pData = new int[elements];
        std::copy(init_list.begin(), init_list.end(), pData);
    }

    Stack(const Stack &param) // Copy constructor
    {
        pData = new int[param.elements];
        std::copy(param.pData, param.pData + param.elements, pData);
    }

    ~Stack() // Destructor
    {
        delete[] pData;
    }

    Stack &operator=(const Stack &param) // Assignment operator
    {
        if (this != &param)
        {
            delete[] pData;

            elements = param.elements;

            pData = new int[elements];

            std::copy(param.pData, param.pData + elements, pData);
        }

        return *this;
    }

    int pop() // Remove and return the top element of the stack
    {
        if (elements == 0)
            throw std::out_of_range("Stack is empty");

        int retval = pData[elements - 1];

        int *newData = new int[elements - 1];

        std::copy(pData, pData + elements - 1, newData);

        delete[] pData;

        pData = newData;

        elements--;

        return retval;
    }

    void push(const int param) // Add an element to the top of the stack
    {
        int *newData = new int[elements + 1];

        std::copy(pData, pData + elements, newData);

        newData[elements] = param;

        elements++;

        delete[] pData;

        pData = newData;

        return;
    }

    bool empty() // Check if the stack is empty
    {
        if (elements == 0)
            return true;

        return false;
    }

    int peek() const // Return the top element of the stack without removing it
    {
        if (elements == 0)
            throw std::out_of_range("Stack is empty");

        return pData[elements - 1];
    }

    int getAt(size_t idx) const // Return the element at a specific index in the stack
    {
        if (idx >= elements)
            throw std::out_of_range("Stack is overindexed");

        return pData[idx];
    }

    size_t getSize() const // Return the number of elements in the stack
    {
        return elements;
    }

    void clear() // Remove all elements from the stack
    {
        delete[] pData;

        pData = nullptr;
        elements = 0;
    }
};


// Copilots FIFO based on my Stack
class Fifo
{
private:
    size_t capacity; // Maximum number of elements in the FIFO
    size_t size;     // Number of elements currently in the FIFO
    int *pData;      // Pointer to the circular buffer storing the elements
    size_t front;    // Index of the front element
    size_t rear;     // Index of the rear element

public:
    Fifo(size_t capacity) : capacity(capacity), size(0), pData(new int[capacity]), front(0), rear(0) {} // Constructor with capacity

    Fifo(const std::initializer_list<int> init_list) : capacity(init_list.size()), size(init_list.size()), pData(new int[capacity]), front(0), rear(0) // Constructor with initializer list
    {
        std::copy(init_list.begin(), init_list.end(), pData);
    }

    Fifo(const Fifo &param) : capacity(param.capacity), size(param.size), pData(new int[capacity]), front(param.front), rear(param.rear) // Copy constructor
    {
        std::copy(param.pData, param.pData + capacity, pData);
    }

    ~Fifo() // Destructor
    {
        delete[] pData;
    }

    Fifo &operator=(const Fifo &param) // Assignment operator
    {
        if (this != &param)
        {
            delete[] pData;

            capacity = param.capacity;
            size = param.size;
            front = param.front;
            rear = param.rear;

            pData = new int[capacity];

            std::copy(param.pData, param.pData + capacity, pData);
        }

        return *this;
    }

    void enqueue(const int param) // Add an element to the rear of the FIFO
    {
        if (size == capacity)
            throw std::out_of_range("FIFO is full");

        pData[rear] = param;
        rear = (rear + 1) % capacity;
        size++;
    }

    int dequeue() // Remove and return the front element of the FIFO
    {
        if (size == 0)
            throw std::out_of_range("FIFO is empty");

        int retval = pData[front];
        front = (front + 1) % capacity;
        size--;

        return retval;
    }

    bool empty() // Check if the FIFO is empty
    {
        return size == 0;
    }

    int frontElement() const // Return the front element of the FIFO without removing it
    {
        if (size == 0)
            throw std::out_of_range("FIFO is empty");

        return pData[front];
    }

    size_t getSize() const // Return the number of elements in the FIFO
    {
        return size;
    }

    void clear() // Remove all elements from the FIFO
    {
        front = 0;
        rear = 0;
        size = 0;
    }
};

int main(int argc, char const *argv[])
{
    Stack stack{1, 2, 3};

    int fasz = stack.pop();

    Fifo fifo{1, 2, 3};

    int kuksi = fifo.dequeue();

    return 0;
}