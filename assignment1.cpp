#include <iostream>
using namespace std;

class Sale {

    string Name;
    char Product;
    int Units;

    public:

        Sale(string name, char product, int units){
            Name = name;
            Product = product;
            Units = units;
        };
        

        int Total(){

            //assign each product a price
            int price;

           
            if(Product == 'X')
                price = 400;

            else if(Product == 'Y')
                price = 530;

            else if(Product == 'Z') 
                price = 390;
            
            // return the total
            return Units * price;
        }


        int Discount(){
            
            int discount = 0;

            if(Product == 'X' || Product == 'Z'){

                if(Total() > 15000)
                    discount = 0.1 * Total();
                else 
                    discount = 0.05 * Total();            
            }

            return discount;
        }

        int Payment(){
            
            int amount = Total() - Discount();

            int pay;

            if(Product == 'Z')
                pay = amount + (.18 * amount);
            else if(Product == 'X' || Product == 'Y')
                pay = amount;
            
            return pay;
        }

        void Receipt(){
            cout << " " << endl << endl;
            cout << "..........RECEIPT........." << endl << endl;
            cout << "Customer name = " << Name << endl;
            cout << "Payment = Kshs. " << Payment() << endl << endl;
            cout << "..........................." << endl << endl;
            cout << "Thanks for shopping with us" << endl << endl;
            cout << "Bye!" << endl;
        }

};



void ProductChoice(){

    cout << "Choose a product: " << endl;

    cout << "X ";
    cout << "Y ";
    cout << "Z" << endl;

    cout << "..............." << endl;

}

int main() {

    string name;
    char product;
    int units;

    //Collect customer inputs
    cout << "Enter name: " << endl;
    cin >> name;

    int trials = 0;

    do
    {
        ProductChoice();
        cin >> product;

        trials++;

    } while (trials < 5 && !(product == 'X' || product == 'Y' || product == 'Z'));

    if(!(product == 'X' || product == 'Y' || product == 'Z'))
        system("exit");
    else
        cout << "Enter units: " << endl;
        cin >> units;

    //instantiate a sale
    Sale sale(name, product, units);
    
    //give receipt
    sale.Receipt();

    cin.get();

}