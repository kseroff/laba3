//#include <iostream>
//using namespace std;
//
//template<typename T>
//class TPQueue
//{
//private:
//    T* arr;          // массив с данными
//    int size;        // максимальное количество элементов в очереди (размер массива)
//    int begin, end;  // начало очереди  конец очереди
//    int count;       // счетчик элементов
//public:
//    TPQueue(int = 100);          // конструктор по умолчанию
//    ~TPQueue();                 // деструктор
//
//    void push(const T&); // добавить элемент в очередь
//    int GetSize() { return count; }
//    void pop();              // удалить элемент из очереди
//    int GetFront();     // прочитать первый элемент
//    bool isEmpty() { return count == 0; }      // пустая ли очередь?
//};
//
//// конструктор по умолчанию
//template<typename T>
//TPQueue<T>::TPQueue(int sizeQueue) :
//    size(sizeQueue),
//    begin(0), end(0), count(0)
//{
//    // дополнительный элемент поможет нам различать конец и начало очереди
//    arr = new T[size + 1];
//}
//
//// деструктор класса Queue
//template<typename T>
//TPQueue<T>::~TPQueue()
//{
//    delete[] arr;
//}
//
//
//// функция добавления элемента в очередь
//template<typename T>
//void TPQueue<T>::push(const T& item)
//{
//    arr[end++] = item;
//    count++;
//}
//
//// функция удаления элемента из очереди
//template<typename T>
//void TPQueue<T>::pop()
//{
//
//    T max=arr[0];
//    int temp{};
//    for (int i = 0; i < count; i++)
//    {
//        if (max < arr[i]) temp=i;
//    }
//
//    T item = arr[temp];
//    count--;
//
//}
//
//template<typename T>
//int TPQueue<T>::GetFront()
//{
//    T max = arr[0];
//    int temp{};
//    for (int i = 0; i < count; i++)
//    {
//        if (max < arr[i]) temp = i;
//    }
//
//    return arr[temp];
//}
//
//
//int main() {
//
//    TPQueue<int>a;
//
//    a.push(13);
//    a.push(23);
//    a.push(33);
//    a.push(43);
//     
//    cout<<a.GetFront();
//    cout << endl << a.GetSize();
//    a.pop();
//    cout<<endl << a.GetFront();
//
//    cout << endl << a.GetSize();
//
//    return 0;
//}

#include <iostream>
using namespace std;

template<typename T>
class TPQueue 
{
public:
    TPQueue();
    ~TPQueue();
    void push(T data);
    void pop();
    int GetSize() { return Size; }
    T GetFront(); 
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
TPQueue<T>::TPQueue()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
TPQueue<T>::~TPQueue()
{
}

template<typename T>
void TPQueue<T>::push(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else {

        int index = 0;
        Node<T>* current = this->head;
        Node<T>* previous = this->head;
        while (current->pNext != nullptr) {
            if (current->data < data) {
                break;
            }
            previous = current;
            current = current->pNext;
            index++;
        }


        if (index == 0)
        {
            head = new Node<T>(data, head);
            Size++;
        }

        else
        {
            //Node<T>* previous = this->head;

            //for (int i = 0; i < index-1; i++)
            //{
            //    previous = previous->pNext;
            //}

            Node<T>* newNode = new Node<T>(data, previous->pNext);

            previous->pNext = newNode;

            Size++;
        }
    }
}

template<typename T>
void TPQueue<T>::pop()
{
    Node<T>* temp = head;
    head = head->pNext;
    //если самый первый элемент то мы сдвигаем голову на один шаг, а первый элемент удаляем
    delete temp;
    Size--;

}

template<typename T>
T TPQueue<T>::GetFront()
{
    Node<T>* current = this->head;
    return current->data;
}


int main()
{
    TPQueue<int> a;
    a.push(13);
    a.push(23);
    a.push(33);
    a.push(93);
    a.push(43);

    cout << a.GetFront();
    a.pop();
    cout << endl << a.GetFront();
    a.pop();
    cout << endl << a.GetFront();
    a.pop();
    cout << endl << a.GetFront();
    a.pop();
    cout << endl << a.GetFront();

    return 0;
}

