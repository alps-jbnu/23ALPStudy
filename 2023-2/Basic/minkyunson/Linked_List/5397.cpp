#include <iostream>
#include <string>
using namespace std;

class dll{
private:
    char c;
    dll * prev;
    dll * next;
public:
    void init()
    {
        c = NULL;
    }
    void input(char i)
    {
        c = i;
    }
    void add_prev(dll * a)
    {
        prev = a;
        a -> next = this;
    }
    void add_next(dll * a)
    {
        next = a;
        a -> prev = this;
    }
    dll * return_prev()
    {
        return prev;
    }
    dll * return_next()
    {
        return next;
    }
    char return_c()
    {
        return c;
    }
};

class editor{
private:
    dll * start;
    dll * end;
    dll * cursor;
public:
    void editor_start_setting()
    {
        start = new dll;
        end = new dll;
        start -> init();
        end -> init();
        start -> add_next(end);
        cursor = end;
    }
    void add_char(char c)
    {
        dll * p = new dll;
        p -> input(c);
        cursor -> return_prev() -> add_next(p);
        cursor -> add_prev(p);
    }
    void remove_char()
    {
        if(cursor -> return_prev() != start)
        {
            dll * p = cursor -> return_prev() -> return_prev();
            delete cursor -> return_prev();
            cursor -> add_prev(p);
        }
    }
    void prev_moving_cursor()
    {
        if(cursor -> return_prev() != start)
        {
            cursor = cursor -> return_prev();
        }
    }
    void next_moving_cursor()
    {
        if(cursor != end)
        {
            cursor = cursor -> return_next();
        }
    }
    void clean_editor()
    {
        dll * p = start -> return_next();
        while(p != end)
        {
            delete (p -> return_prev());
            p = p -> return_next();
        }
        delete (p -> return_prev());
        delete p;
    }
    void print_str()
    {
        dll * p = start -> return_next();
        while(p != end)
        {
            cout << (p -> return_c());
            p = p -> return_next();
        }
    }
};

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        editor ed;
        ed.editor_start_setting();
        string str;
        cin >> str;
        for(int i = 0; i < str.size(); i++)
        {
            switch (str[i]) {
                case '-':
                    ed.remove_char();
                    break;
                case '<':
                    ed.prev_moving_cursor();
                    break;
                case '>':
                    ed.next_moving_cursor();
                    break;
                default:
                    ed.add_char(str[i]);
                    break;
            }
        }
        ed.print_str();
        ed.clean_editor();
        cout<<endl;
    }
}
