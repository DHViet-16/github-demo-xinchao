#include <iostream>
#include <fstream>
using namespace std;

struct node
{
    int data;
    node *next;
};
typedef node *List;
void create_List(List &l)
{
    l = NULL;
}
node *create_Node(int x)
{
    node *p = new node;
    if (p == NULL)
        return NULL;
    p->data = x;
    p->next = NULL;
    return p;
}
// Tính chiều dài của list
int list_Len(List &l)
{
    node *p = l;
    int len;
    while (p->next != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}
// Tìm kiếm vị trí x trong list
int pos_x(List l, int x)
{
    int i = 1;
    node *p = l;
    while (p->next != NULL && p->data != x)
    {
        i++;
        p = p->next;
    }
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return i;
    }
}
// Thêm một nút mới vào đầu danh sách
void add_head(List &l, int x)
{
    node *p = create_Node(x);
    if (l == NULL)
        l = p;
    else
    {
        p->next = l;
        l = p;
    }
}
// Thêm một nút mới vào cuối danh sách
void add_tail(List &l, int x)
{
    node *p = create_Node(x);
    if (l == NULL)
        l = p;
    else
    {
        node *Q = l;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = p;
    }
}

void add_At(List &l, int k, int x)
{
    int n = list_Len(l);
    if (k == 0)
    {
        add_head(l, x);
    }
    if (k == n)
    {
        add_tail(l, x);
    }
    else
    {
        node *p = l;
        for (int i = 0; i < k - 1; i++)
        {
            p = p->next;
        }
        node *temp = create_Node(x);
        temp->next = p->next;
        p->next = temp;
    }
}
// xóa
void delete_head(List &l)
{
    if (l == NULL)
        return;
    node *p = l;
    l = l->next;
    delete (p);
}
void delete_tail(List &l)
{
    if (l == NULL)
    {
        return;
    }
    if (l->next == NULL)
    {
        node *p = l;
        l = NULL;
        delete (p);
    }
    else
    {
        node *p = l;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        delete (p->next);
        p->next = NULL;
    }
}
void delete_At(List &l, int k)
{
    int n = list_Len(l);
    if (l == NULL)
    {
        return;
    }
    if (k == 0)
    {
        delete_head(l);
    }
    if (k == n)
    {
        delete_tail(l);
    }
    else
    {
        node *p = l;
        for (int i = 0; i < k - 1; i++)
        {
            p = p->next;
        }
        node *temp = p->next;
        p->next = p->next->next;
        delete (temp);
    }
}
// sắp xếp
void sort(List l)
{
    for (node *Q = l; Q->next != NULL; Q = Q->next)
    {
        for (node *P = Q->next; P != NULL; P = P->next)
        {
            if (Q->data > P->data)
            {
                swap(Q->data, P->data);
            }
        }
    }
}
// Ghi file
void write_file(fstream &f, List l)
{
    /*string path;
    cout << "Enter path file name: ";
    getline(cin, path);*/
    f.open("nhap.in", ios::out);
    node *p = l;
    while (p != NULL)
    {
        f << p->data << " ";
        p = p->next;
    }
    f.close();
}
// Đọc file
void read_file(fstream &f, List &l)
{
    /*string path;
    cout << "Enter path file name: ";
    getline(cin, path);*/
    f.open("nhap.in", ios::in);
    node *p = l;
    int x;
    f >> x;
    add_tail(l, x);
    while (p->next != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    f.close();
}
// Tìm mAX trong list
int max_list(List &l)
{
    int max = 0;
    node *p = l;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}
// Ghi ra file danh sách các phần tử có giá trị lớn nhất
void write_list_file(fstream &f, List l)
{
    /* string path;
     cout << "Enter path file name: ";
     getline(cin, path);*/
    f.open("nhap.in", ios::out);
    node *p = l;
    while (p != NULL)
    {
        if (max_list(l) == p->data)
        {
            f << p->data << " ";
        }
        p = p->next;
    }
    f.close();
}
void input_list(List &l)
{
    int x;
    cout << "x= ";
    cin >> x;
    while (x != 0)
    {
        add_tail(l, x);
        cout << "x= ";
        cin >> x;
    }
}
void output_list(List l)
{
    node *Q = l;
    while (Q != NULL)
    {
        cout << Q->data << " ";
        Q = Q->next;
    }
}
int main()
{
    List l;
    fstream f;
    create_List(l);
    // input_list(l);
    // output_list(l);
    // cout << endl;
    /* int x;
     cin >> x;
     cout <<pos_x(l, x);*/
    // Thêm một nút mới vào đầu danh sách
    // int x = 10;
    // add_head(l, x);
    // output_list(l);
    // cout << endl;
    // Thêm một nút mới vào cuối danh sách
    // add_tail(l,x);
    // output_list(l);
    // Thêm một nút mới vào vị trí k  danh sách
    // cout << endl;
    // int k;
    // cout << "K= ";
    // cin >> k;
    // add_At(l, k, x);
    // delete_head(l);
    // delete_tail(l);
    // delete_At(l, k);
    // output_list(l);
    // write_file(f,l);
    // cout <<max_list(l);
    // write_list_file(f,l);
    read_file(f, l);
    return 0;
}