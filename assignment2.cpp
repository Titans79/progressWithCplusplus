#include <iostream>
using namespace std;

class Salesperson {

    private:    
        string Name;
        char Region;
        int Units;

    public:
        Salesperson(string name, char region, int units){
            Name = name;
            Region = region;
            Units = units;

        };

        int SalesValue(){
            return Units * 1200;
        }
        int SalesCommissionForRegionV(){
            if (Region == 'V')
                return Units * 1200; 
        }
        int SalesCommissionForRegionS(){
            if (Region == 'S')
                return Units * 1200;
        }

        int SalesCommissionPerIndividual(){
            if (Region == 'V')
                return .16 * SalesCommissionForRegionV();
            else if (Region == 'S')
                return .17 * SalesCommissionForRegionS();
            else
                cout << "Invalid region!" << endl;
            
        }

        int Tax() {
            int tax = 0;
    
            SalesCommissionPerIndividual() > 25000 ? tax = (.15 * SalesCommissionPerIndividual()) : tax = 0;

            return tax;
        }

        int NetSalesCommissionPerIndividual() {
            return SalesCommissionPerIndividual() - Tax();
        }
        
        void Summary(){
            cout << ".................." << endl << endl;
            cout << "Name: " << Name << endl;
            cout << "Region: " << Region << endl;
            cout << "Sales Value: " << SalesValue() << endl;
            cout << ".................." << endl << endl;
        }
        
};

char ChooseRegion(){

    char region;
    int trials = 0;

    do
    {
        cout << "Choose a region: " << endl;
        cout << "V ";
        cout << "S " << endl;
        cout << "..............." << endl;
        cin >> region;

        trials++;

    } while (trials < 10 && !(region == 'V' || region == 'S'));
    
    if (!(region == 'V' || region == 'S'))
        return region;
    else
        system("exit");
    
    return region;
}

int main() {

    string name;
    int units;

    //Collect salesperson inputs
    cout << "Enter name: " << endl;
    cin >> name;
    char region = ChooseRegion();
    
    cout << "Enter units sold: " << endl;
    cin >> units;

    //instantiate a salesperson
    Salesperson salesperson(name, region, units);

    salesperson.Summary();

    cin.get();

}