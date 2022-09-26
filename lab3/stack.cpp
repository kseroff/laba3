//#include <iostream>
//using namespace std;
//
//template<typename T>
//class TStack
//{
//private:
//    T* arr;          // массив с данными
//    int size;        // максимальное количество элементов в очереди (размер массива)
//    int begin, end;  // начало очереди  конец очереди
//    int count;       // счетчик элементов
//public:
//    TStack(int = 100);          // конструктор по умолчанию
//    ~TStack();                 // деструктор
//
//    void push(const T&); // добавить элемент в очередь
//    int GetSize() { return count; }
//    void pop();              // удалить элемент из очереди
//    int GetBack() { return arr[--end]; }      // прочитать первый элемент
//    bool isEmpty() { return count == 0; }      // пустая ли очередь?
//};
//
//// конструктор по умолчанию
//template<typename T>
//TStack<T>::TStack(int sizeQueue) :
//    size(sizeQueue),
//    begin(0), end(0), count(0)
//{
//    // дополнительный элемент поможет нам различать конец и начало очереди
//    arr = new T[size + 1];
//}
//
//// деструктор класса Queue
//template<typename T>
//TStack<T>::~TStack()
//{
//    delete[] arr;
//}
//
//
//// функция добавления элемента в очередь
//template<typename T>
//void TStack<T>::push(const T& item)
//{
//    arr[end++] = item;
//    count++;
//
//    // проверка кругового заполнения очереди
//    if (end > size)
//        end -= size + 1; // возвращаем end на начало очереди
//}
//
//// функция удаления элемента из очереди
//template<typename T>
//void TStack<T>::pop()
//{
//    T item = arr[end];
//    count--;
//}
//
//
//int main() {
//
//    TStack<int>a;
//
//    a.push(13);
//    a.push(23);
//    a.push(33);
//    a.push(43);
//    a.push(53);
//
//    cout << a.GetBack();
//    a.pop();
//    cout<<endl << a.GetBack();
//    a.pop();
//    cout << endl << a.GetBack();
//
//    return 0;
//}

#include <iostream>
using namespace std;

template<typename T>
class TStack 
{
public:
    TStack();
    ~TStack();
    void push(T data);
    void pop();
    int GetSize() { return Size; }
    T GetBack();
    bool isEmpty() { return Size == 0; } 

private:

    template<typename T>
    struct Node
    {
        Node* pNext; 
        T data;

        Node(T data = T(), Node* pnext = nullptr)
        {
            this->data = data; 
            this->pNext = pnext;
        }
    };
    int Size;
    Node<T>* head; 

};

template<typename T>
TStack<T>::TStack()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
TStack<T>::~TStack()
{
}

template<typename T>
void TStack<T>::push(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else {
        Node<T>* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
void TStack<T>::pop()
{
    Node<T>* previous = this->head;
    for (int i = 0; i < Size - 2; i++) {
        previous = previous->pNext;
    }
    Node<T>* todelete = previous->pNext;
    previous->pNext = todelete->pNext;
    delete todelete;
    Size--;

}

template<typename T>
T TStack<T>::GetBack()
{
    int counter = 0;
    Node<T>* current = this->head;
    while (true)
    {
        if (counter==Size-1) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

int main()
{
    TStack<int> a;
    a.push(13);
    a.push(23);
    a.push(33);
    a.push(43);

    cout << a.GetBack();
    cout << endl << a.GetSize();
    a.pop();
    cout << endl << a.GetBack();

    cout << endl << a.GetSize();

    return 0;
}

