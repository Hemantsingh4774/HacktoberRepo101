//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ processing a shopping list@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
#include <iostream>
using namespace std;

const int m = 50;
class items
{
private:
    int itemcode[m];
    float itemprice[m];
    int count;

public:
    items()
    {
        count = 0;
    } // initialises count to zero using constructors
    void add_item();
    void display_sum();
    void remove_item();
    void display_items();
    void set_discount();
    void exit_store();
};
//*************adding items to the list***************//
void items::add_item()
{
    cout << "enter item code: ";
    cin >> itemcode[count];
    cout << "enter item price: ";
    cin >> itemprice[count];
    count++;
}
//**************displaying sum****************//
void items::display_sum()
{
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum = sum + itemprice[i];
    }
    cout << "total tax = " << (sum / 100) * 18 << endl;
    cout << "total value = " << sum + (sum / 100) * 18 << endl;
}
//***********removing a specified  item from cart***********//
void items::remove_item()
{
    int r;
    cout << "enter item code: ";
    cin >> r;
    for (int i = 0; i < count; i++)
    {
        if (itemcode[i] == r)
        {
            itemprice[i] = 0;
        }
    }
}
//************displaying all items in the cart************//
void items::display_items()
{
    cout << "\ncode price\n";
    for (int i = 0; i < count; i++)
    {
        cout << "\n"
             << itemcode[i] << " " << itemprice[i];
    }
    cout << "\n";
}
//************calculating discount***************//
void items::set_discount()
{
    for (int i = 0; i < count; i++)
    {
        itemprice[i] = itemprice[i] - 4;
    }
    cout << "discounted price is: ";
    display_sum();
}
//*************exiting the programme***************//
void items::exit_store()
{
    exit(0);
}

int main()
{
    items order;
    int x, dis;
    do // do while loop
    {
        cout << "you can do the following ; \n";
        cout << "1: add an item to the cart";
        cout << "\n2: Display toatal value";
        cout << "\n3: Delete an item from the cart";
        cout << "\n4: Display all items";
        cout << "\n5: check for discount";
        cout << "\n6: leave the store";
        cout << "\nEnter the appropriate option: ";
        cin >> x;
        switch (x)
        {
        case 1:
            order.add_item();
            break;
        case 2:
            order.display_sum();
            break;
        case 3:
            order.remove_item();
            break;
        case 4:
            order.display_items();
            break;
        case 5:
            order.set_discount();
            break;
        case 6:
            order.exit_store();
            break;
        default:
            cout << "error in input; please try again\n\a";
            break;
        }
    } while (x != 6);
    return 0;
}