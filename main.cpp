#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
struct node * head = NULL;

void basaEkle(int data)
{
    struct node * newnode = new node();
    newnode->data = data;
    if (head== NULL)
    {
        newnode->next = NULL;
        newnode->prev =NULL;
        head = newnode;
    }
    else
    {
        newnode->prev= NULL;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void sonaEkle(int data)
{
    struct node * newnode = new node();
    newnode->data = data;
    if(head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        struct node * temp = head;
        while(temp != NULL)
        {
            if (temp->next == NULL)
            {
                temp->next = newnode;
                newnode->prev = temp;
                newnode->next = NULL;
                return;
            }
            temp = temp->next;
        }
    }
}
void ArayaEkle(int data,int sira)
{
    struct node * newnode = new node();
    newnode->data = data;
    if(head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        struct node * temp = head;
        while(temp!=NULL)
        {
            if (temp->data == sira)
            {
                struct node * temp2 = temp->prev;
                struct node *temp3  = temp;
                temp2->next = newnode;
                newnode->prev = temp2;
                newnode->next =temp3;
                temp3->prev = newnode;
                break;
            }

            temp = temp->next;
        }


    }
}
void BastanSil()
{
    if (head == NULL)
    {
        cout<<"Liste bos oldugu icin silinemedi";
    }
    else
    {
        struct node * temp = head->next;
        temp->prev = NULL;
        delete head;
        head = temp;
    }
}


void SondanSil()
{
    if (head == NULL)
    {
        cout<<"Liste bos oldugu icin silinemedi";
    }
    else
    {
        struct node * temp = head;
        while(temp !=NULL)
        {
            if(temp->next->next ==NULL)
            {
                delete temp->next;
                temp->next = NULL;
                break;

            }
            temp = temp->next;
        }
    }

}


void AradanSil(int silinecekSayi)
{
    if (head == NULL)
    {
        cout<<"Liste bos oldugu icin silinemedi";

    }
    else
    {
        struct node * temp = head;
        while(temp != NULL)
        {
            if(temp->data == silinecekSayi)
            {
                struct node * temp2 = temp->prev;
                struct node * temp3 = temp->next;
                temp2->next = temp3;
                temp3->prev =temp2;
                delete temp;
                cout<<endl<<" Secilen sayi silindi";
                break;
            }
            temp = temp->next;
        }
    }


}


void Yazdir()
{
    if(head == NULL)
    {
        cout<<endl<<"Liste bos";

    }
    else
    {
        cout<<endl<<endl;
        struct node * temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }


    }
}

int main()
{
    int sayi ,sayi2, secim;
    while(1)
        {
            cout<<endl<<"1- Basa ekle"<<endl;
            cout<<"2- Sona ekle"<<endl;
            cout<<"3- Araya ekle"<<endl;
            cout<<"4- Bastan Sil"<<endl;
            cout<<"5- Sondan Sil"<<endl;
            cout<<"6- Aradan Sil"<<endl;
            cout<<"7- Yazdir"<<endl;
            cout<<"8- Cikis"<<endl;
            cin>>secim;
            switch(secim)
            {
            case 1:
                {
                    cout<<endl<<"Basa eklenecek sayiyi giriniz : " ;
                    cin>>sayi;
                    basaEkle(sayi);
                    break;
                }
            case 2:
                {
                    cout<<endl<<"Sona eklenecek sayiyi giriniz : " ;
                    cin>>sayi;
                    sonaEkle(sayi);
                    break;
                }
            case 3:
                {
                    cout<<endl<<"Araya eklenecek sayiyi giriniz : " ;
                    cin>>sayi;
                    cout<<endl<<"Hangi sayýdan önce eklenecek : " ;
                    cin>>sayi2;
                    ArayaEkle(sayi,sayi2);
                    break;
                }
            case 4:
                {
                    cout<<endl<<"Bastaki eleman silindi" ;
                    BastanSil();
                    break;
                }
            case 5:
                {
                    cout<<endl<<"Sondaki eleman silindi" ;
                    SondanSil();
                    break;
                }
            case 6:
                {
                    cout<<endl<<"Silinecek elemaný girin" ;
                    cin>>sayi;
                    AradanSil(sayi);
                    break;
                }
            case 7:
                {
                    Yazdir();
                    break;
                }
            case 8:
                {
                    return 0;
                }

            }
        }

    return 0;
}
