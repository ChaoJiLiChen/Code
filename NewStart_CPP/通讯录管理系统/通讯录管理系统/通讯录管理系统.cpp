#include <iostream>
#include <string>

using namespace std;

#define MAX 1000

struct Person
{
    string name;
    int sex;
    int age;
    string phhonenumber;
    string addres;
};

struct Addressbooks
{
    struct Person personArray[MAX];
    int m_size;
};
void showMenu()
{
    cout << "************************" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "************************" << endl;
}


void addPerson(struct Addressbooks *abs)
{
    if (abs->m_size >= 1000) 
    {
        cout << "存储已满" << endl;
        return;
    }
    string name = "";
    cout << "请输入姓名" << endl;
    cin >> name;
    abs->personArray[abs->m_size].name = name;

    int  sex = -1;
    cout << "请输入性别" << endl;
    while (1)
    {
        cout << "1----男" << endl;
        cout << "0----女" << endl;
        cin >> sex;
        if (sex == 1 || sex == 0)
        {
            abs->personArray[abs->m_size].sex = sex;
            break;
        }
        cout << "输入有误" << endl;
    }

    int  age = -1;
    cout << "请输入年龄" << endl;
    while (1)
    {
        cin >> age;
        if (age >0  || age < 150)
        {
            abs->personArray[abs->m_size].age = age;
            break;
        }
        cout << "输入有误" << endl;
    }
    
    string addres = "";
    cout << "请输入地址" << endl;
    cin >> addres;
    abs->personArray[abs->m_size].addres = addres;
    abs->m_size++;
    cout << "添加成功" << endl;
    system("pause");
    system("cls");
    return;
}


void showPerson(struct Addressbooks* abs)
{
    if (abs->m_size <= 0)
    {
        cout << "为空" << endl;
        return;
    }
    for (int i = 0; i< abs->m_size; i++)
    {
        cout << "姓名：" << abs->personArray[i].name << " 性别：" << (abs->personArray[i].sex == 1 ? "男": "女") << " 年龄：" << abs->personArray[i].age << " 住址：" << abs->personArray[i].addres << endl;
    }
    system("pause");
    system("cls");
    return;
}

int isExist(struct Addressbooks* abs, string name)
{
    for (int i = 0; i< abs->m_size; i++)
    {
        if (name == abs->personArray[i].name) return i;
    }
    return -1;
}

int deletenode(struct Addressbooks* abs)
{
    cout << "姓名：" << endl;
    string name = "";
    cin >> name;
    int ret = -1;
    ret = isExist(abs, name);
    if (ret == -1)
    {
        cout << "查无此人" << endl;
        return -1;
    }
    for (int i = ret; i < abs->m_size; i++)
    {
        abs->personArray[i] = abs->personArray[i + 1];
    }
    abs->m_size--;
    system("pause");
    system("cls");
    return 0;
}
int main(int argc, char *agrv[])
{
    int selectnum = -1;
    struct Addressbooks abs;
    abs.m_size = 0;
    while (1)
    {
        showMenu();
        cin >> selectnum;
        switch (selectnum)
        {
            case 1: //1.添加联系人
                addPerson(&abs);
                break;
            case 2: //2.显示联系人
                showPerson(&abs);
                break;
            case 3://3.删除联系人
            {
                int res = deletenode(&abs);
                break;
            }
            case 4://4.查找联系人
                break;
            case 5://5.修改联系人
                break;
            case 6://6.清空联系人
                break;
            case 0://0.退出通讯录
            {
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
            }
            default:
                break;
        }
    }
    
    system("pause");
    return 0;
}