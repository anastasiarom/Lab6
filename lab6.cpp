// lab6.cpp : 9.Класс «Массив».
//

#include <iostream>

using namespace std;

template<class T>
T input(T)
{
    T i;
    bool fail = true;
    do
    {
        rewind(stdin);
        cin >> i;
        if (cin.fail() || cin.rdbuf()->in_avail() > 1)
            cout << "\nError" << endl;
        else
            fail = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (fail);
    return i;
}

template <class T=int> 
class ar
{
protected:
    T  *ms;
    int len;
public:
    ar() : len(0), ms(nullptr) { };
    ~ar()                                         
    {
        delete[] ms;
    }
    void push()
    {
        if (len == 0)
        {
            len = 1;
            ms = new T[len];
            cout << "\nEnter the element: " << endl;
            ms[len - 1] = input(ms[len - 1]);
        }
        else
        {
            T *tmp = new T[len];
            for (int i = 0; i < len; i++)
                tmp[i]=ms[i];
            delete[] ms;
            len++;
            ms = new T[len];
            for (int i = 0; i < len-1; i++)
                ms[i]=tmp[i];
            cout << "\nEnter the element: " << endl;
            ms[len - 1]=input(ms[len - 1]);
            delete[] tmp;
        }
    }
    void pop()
    {
        if (len == 0)
            return;
        if (len == 1)
        {
            len = 0;
            delete[] ms;
        }
        else
        {
            len--;
            T* tmp = new T[len];
            for (int i = 0; i < len; i++)
                tmp[i] = ms[i];
            delete[] ms;
            ms = tmp;
        }
    }
    void output()                               
    {
        cout << "\nArray: " << endl;
        for (int i = 0; i < len; i++)
            cout << ms[i] << "     ";
    }
    void search()
    {
        T n;
        int i;
        cout << "\nEnter the desired element:\n" << endl;
        cin >> n;
        for (i = 0; i < len; i++)
        {
            if (ms[i] == n)
            {
                cout << "\nThe element you are looking for is number " << i + 1 << endl;
                break;
            }  
        }
        if(i==len)
            cout << "\nThere is no such element\n" << endl;
    }
    void sort()
    {
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len-1; j++)
                if (ms[j] > ms[j + 1]) 
                {
                    T tmp = ms[j]; 
                    ms[j] = ms[j + 1]; 
                    ms[j + 1] = tmp; 
                }
    }
    bool operator< (ar& m2) const               
    {
      return (len < m2.len) ? true : false;
    }
    bool operator> (ar& m2) const               
    {
        return (len > m2.len) ? true : false;
    }
    bool operator== (ar& m2) const              
    {
        return (len == m2.len) ? true : false;
    }
    T& operator[](int i)
    {
        if (i<0 || i>len - 1)
        {
            cout << "\nIndex outside the array" << endl;
            exit(1);
        }
        return ms[i];
    }
};

template<> 
class ar<char>
{
protected:
    char* ms;
    int len;
public:
    ar() : len(0), ms(nullptr) { };
    ~ar()
    {
        delete[] ms;
    }
    void push()
    {
        if (len == 0)
        {
            len = 1;
            ms = new char[len];
            cout << "\nEnter the element: " << endl;
            cin >> ms[len - 1];
        }
        else
        {
            char* tmp = new char[len];
            for (int i = 0; i < len; i++)
                tmp[i] = ms[i];
            delete[] ms;
            len++;
            ms = new char[len];
            for (int i = 0; i < len - 1; i++)
                ms[i] = tmp[i];
            cout << "\nEnter the element: " << endl;
            cin >> ms[len - 1];
            delete[] tmp;
        }
    }
    void pop()
    {
        if (len == 0)
            return;
        if (len == 1)
        {
            len = 0;
            delete[] ms;
        }
        else
        {
            len--;
            char* tmp = new char[len];
            for (int i = 0; i < len; i++)
                tmp[i] = ms[i];
            delete[] ms;
            ms = tmp;
        }
    }
    void output()
    {
        cout << "\nArray: " << endl;
        for (int i = 0; i < len; i++)
            cout << ms[i] << "     ";
    }
    void search()
    {
        char n;
        int i;
        cout << "\nEnter the desired element:\n" << endl;
        cin >> n;
        for (i = 0; i < len; i++)
        {
            if (ms[i] == n)
            {
                cout << "\nThe element you are looking for is number " << i + 1 << endl;
                break;
            }
        }
        if (i == len)
            cout << "\nThere is no such element\n" << endl;
    }
    void sort()
    {
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len - 1; j++)
                if (ms[j] > ms[j + 1])
                {
                    char tmp = ms[j];
                    ms[j] = ms[j + 1];
                    ms[j + 1] = tmp;
                }
    }
    bool operator< (ar m2) const
    {
        return (len < m2.len) ? true : false;
    }
    bool operator> (ar m2) const
    {
        return (len > m2.len) ? true : false;
    }
    bool operator== (ar m2) const
    {
        return (len == m2.len) ? true : false;
    }
    char& operator[](int i)
    {
        if (i<0 || i>len - 1)
        {
            cout << "\nIndex outside the array" << endl;
            exit(1);
        }
        return ms[i];
    }
};

class in :public ar<>
{
public:
    void showname()
    {
        cout << "Type's name is  " << typeid(ms).name() << endl;
    }
};

template <class T>
void menu(ar<T>& m)
{
    int n=0;
    do {
        cout << "\n      Menu\n 1 - Add an element\n 2 - Delet an elment\n 3 - Find an element\n 4 - Sorted the array\n 5 - Output the array\n 0 - Exit\n" << endl;
        n = input(n);
        switch (n)
        {
        case 1: {m.push(); m.output(); break; }
        case 2: {m.pop(); m.output(); break; }
        case 3: {m.search(); break;	}
        case 4: {m.sort(); m.output(); break;   }
        case 5: {m.output(); break;  }
        case 0: { return; }
        }
    } while (1);
}
int main()
{
    cout << "\nArray with default argument int" << endl;
    ar<> m1;
    menu(m1);
    cout << "\nArray with the standard type double" << endl;
    ar<double> m2;
    menu(m2);
    cout << "\nArray with specialization char" << endl;
    ar<char> m3;
    menu(m3);
    cout << "\nArray with default argument int" << endl;
    ar<> m4;
    menu(m4);
    cout << "\nCompare 2 arrays" << endl;
    m4.output();
    m1.output();
    if (m4 < m1)
        cout << "\n\nThe first array is smaller than the second\n" << endl;
    if (m4 > m1)
        cout << "\n\nThe first array is bigger than the second\n" << endl;
    if (m1 == m4)
        cout << "\n\nArrays are the same\n" << endl;
    in t;
    t.showname();
}

