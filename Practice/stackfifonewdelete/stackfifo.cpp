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
    s.pData = newData;
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