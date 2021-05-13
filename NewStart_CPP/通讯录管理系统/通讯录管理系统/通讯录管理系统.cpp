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
    cout << "***** 1.�����ϵ�� *****" << endl;
    cout << "***** 2.��ʾ��ϵ�� *****" << endl;
    cout << "***** 3.ɾ����ϵ�� *****" << endl;
    cout << "***** 4.������ϵ�� *****" << endl;
    cout << "***** 5.�޸���ϵ�� *****" << endl;
    cout << "***** 6.�����ϵ�� *****" << endl;
    cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
    cout << "************************" << endl;
}


void addPerson(struct Addressbooks *abs)
{
    if (abs->m_size >= 1000) 
    {
        cout << "�洢����" << endl;
        return;
    }
    string name = "";
    cout << "����������" << endl;
    cin >> name;
    abs->personArray[abs->m_size].name = name;

    int  sex = -1;
    cout << "�������Ա�" << endl;
    while (1)
    {
        cout << "1----��" << endl;
        cout << "0----Ů" << endl;
        cin >> sex;
        if (sex == 1 || sex == 0)
        {
            abs->personArray[abs->m_size].sex = sex;
            break;
        }
        cout << "��������" << endl;
    }

    int  age = -1;
    cout << "����������" << endl;
    while (1)
    {
        cin >> age;
        if (age >0  || age < 150)
        {
            abs->personArray[abs->m_size].age = age;
            break;
        }
        cout << "��������" << endl;
    }
    
    string addres = "";
    cout << "�������ַ" << endl;
    cin >> addres;
    abs->personArray[abs->m_size].addres = addres;
    abs->m_size++;
    cout << "��ӳɹ�" << endl;
    system("pause");
    system("cls");
    return;
}


void showPerson(struct Addressbooks* abs)
{
    if (abs->m_size <= 0)
    {
        cout << "Ϊ��" << endl;
        return;
    }
    for (int i = 0; i< abs->m_size; i++)
    {
        cout << "������" << abs->personArray[i].name << " �Ա�" << (abs->personArray[i].sex == 1 ? "��": "Ů") << " ���䣺" << abs->personArray[i].age << " סַ��" << abs->personArray[i].addres << endl;
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
    cout << "������" << endl;
    string name = "";
    cin >> name;
    int ret = -1;
    ret = isExist(abs, name);
    if (ret == -1)
    {
        cout << "���޴���" << endl;
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
            case 1: //1.�����ϵ��
                addPerson(&abs);
                break;
            case 2: //2.��ʾ��ϵ��
                showPerson(&abs);
                break;
            case 3://3.ɾ����ϵ��
            {
                int res = deletenode(&abs);
                break;
            }
            case 4://4.������ϵ��
                break;
            case 5://5.�޸���ϵ��
                break;
            case 6://6.�����ϵ��
                break;
            case 0://0.�˳�ͨѶ¼
            {
                cout << "��ӭ�´�ʹ��" << endl;
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