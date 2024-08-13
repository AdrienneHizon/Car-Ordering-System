#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>

using std::string;

void input_reset(){

    char input;
    std::cout << "Enter any key to continue: ";
    std::cin >> input;
    input = '\0';
}

class Vehicle{

    private:

        string model, fuel_eff;
        int seat_cap, quantity, keypoint;
        double orig_price, taxed_price;

    public:

        Vehicle(string name, double p, string fuel, int seat, int key): model(name), orig_price(p), fuel_eff(fuel), seat_cap(seat), keypoint(key){

            taxed_price = orig_price + (0.08*orig_price);
        }

        string get_model(){

            return model;
        }

        string get_fuel(){

            return fuel_eff;
        }

        int get_seat(){

            return seat_cap;
        }

        double get_price_orig(){

            return orig_price;
        }

        double get_price_taxed(){

            return taxed_price;
        }

        int get_count(){

            return quantity;
        }

        void set_count(int count){

            quantity = count;
        }

        int get_keyid(){

            return keypoint;
        }

        void get_info(){

        std::cout <<   "Model: " << model << "\n"
                    <<   "Price : " << orig_price << "\n"
                    <<   "Fuel Efficiency: " << fuel_eff << "\n"
                    <<   "Seat Capacity: " << seat_cap << "\n"
                    <<   "Quantity: " << quantity << "\n"
                    <<   "Total Price (with 8% tax applied): $" << quantity*taxed_price << "\n\n"; 
        }

        double taxed_price_with_quantity(){

            return taxed_price*quantity;
        }
        
};

Vehicle Car[] = {

    Vehicle("Toyota Camry", 25000, "28 mpg", 5, 1),
    Vehicle("Honda Civic", 22000, "32 mpg", 5, 2),
    Vehicle("Ford F-150", 35000, "20 mpg", 6, 3),
    Vehicle("Tesla Model S", 70000, "Electric", 5, 4),
    Vehicle("BMW 3 Series", 40000, "26 mpg", 5, 5),
    Vehicle("Audi Q5", 45000, "24 mpg", 5, 6),
    Vehicle("Chevrolet Silverado", 40000, "18 mpg", 6, 7),
    Vehicle("Mercedes-Benz C-Class", 45000, "25 mpg", 5, 8),
    Vehicle("Subaru Outback", 30000, "29 mpg", 5, 9),
    Vehicle("Volkswagen Golf", 20000, "34 mpg", 5, 10)

};



int Cart[10];



class Shop{

    public:

        void View_Cars(){

            std::cout << "===================================================================" << "\n"
                    <<   "||      These are the automobiles available in the Garage!       ||" << "\n"
                    <<   "===================================================================" << std::endl;

            for (int i = 0; i < 10; i++){
                
                std::cout << "===================================================================" << "\n";
                std::cout << "Vehicle " << i+1 << "\n"
                        <<   "Model: " << Car[i].get_model() << "\n"
                        <<   "Price: $" << Car[i].get_price_orig() << "\n"
                        <<   "Fuel Efficiency: " << Car[i].get_fuel() << "\n"
                        <<   "Seat Capacity: " << Car[i].get_seat() << "\n\n";
            }
            std::cout << "===================================================================" << std::endl;
            input_reset();
            system("cls");
        }

        void Add_Cart(){

            int vehicle_num, quantity;
            bool slot_check = false;

            std::cout << "======================================================" << "\n"
                    <<   "||  Select the vehicle you want to add in the cart  ||" << "\n"
                    <<   "======================================================" << std::endl;
            
            std::cout << "Vehicle Number: ";
            std::cin >> vehicle_num;

            if (vehicle_num < 1 || vehicle_num > 10){

                system("cls");
                std::cout << " There's no such thing as Vehicle " << vehicle_num << std::endl;
                return;
            }


            for (int i = 0; i < 10; i++){
                
                if (Cart[i] == vehicle_num){
                    slot_check = true;
                    break;
                }
            }

            if (slot_check == false){


                for(int j = 0; j < 10; j++){
                    
                    if (Cart[j] == 0){
                        Cart[j] = vehicle_num;
                        slot_check = true;
                        break;
                    }
                }
            }



            std::cout << "Enter the quantity of your desired order: ";
            std::cin >> quantity;
            quantity += Car[vehicle_num-1].get_count();
            Car[vehicle_num-1].set_count(quantity);

            std::cout << "======================================================" << "\n"
                    <<   "Successfully added in your cart!" << std::endl;
                    input_reset();
                    system("cls");
        }

        void Remove_Cart(){

            int vehicle_num, key = 0;

            std::cout << "=======================================================" << "\n"
                    <<   "|| Select the vehicle you want to remove in the cart ||" << "\n"
                    <<   "=======================================================" << std::endl;

            std::cout << "Vehicle Number: ";
            std::cin >> vehicle_num;

            for (int i = 0; i < 10; i++){

                if (Cart[i] == vehicle_num){
                    Car[vehicle_num-1].set_count(0);
                    Cart[i] = 0;
                    break;
                }
                
                ++key;
            }
            
            if (key == 10){
                system("cls");
                std::cout << "The selected vehicle was not found in your cart!" << std::endl;
                return;
            }

            std::cout << "======================================================" << "\n"
                    <<   "Successfully removed in your cart!" << std::endl;
                    input_reset();
                    system("cls");
        }

        void View_Cart(){
            
            int slot;

            std::cout << "===================================================================" << "\n"
                    <<   "||         These are the automobiles stored in your cart!        ||" << "\n"
                    <<   "===================================================================" << std::endl;

            for (int i = 0; i < 10; i++){

                slot = Cart[i];

                if (slot == 0){

                    std::cout << "Cart " << i+1 << " is vacant!" << "\n";
                }
                else if(slot != 0){
                    
                    Car[slot-1].get_info();
                }

                std::cout << "===================================================================" << std::endl;
            }
        }

        void Clear_Cart(){
            
            for (int i = 0; i < 10; i++){
                
                Cart[i] = 0;
                Car[i].set_count(0);
            }
        }
};

Shop Store;

void Proceed_to_Cart(){

    int option_pick, keyid;
    double total_price = 0;

    Store.View_Cart();

    do{
                    
        std::cout << "*******************************************************************" << "\n"
                <<   "#                     What would you like to do?                  #" << "\n"
                <<   "*******************************************************************" << "\n"
                <<   "# [1] Add more vehicle                                            #" << "\n"
                <<   "# [2] Remove a vehicle                                            #" << "\n"
                <<   "# [3] Checkout cart                                               #" << "\n"
                <<   "# [4] Clear cart                                                  #" << "\n"
                <<   "# [5] Continue shopping                                           #" << "\n"
                <<   "*******************************************************************" << "\n";
        
        std::cout << "Selected option: ";
        std::cin >> option_pick;
    
        switch(option_pick){

            case 1:

                std::cout << "\n\n";
                Store.Add_Cart();
                break;

            case 2:

                std::cout << "\n\n";
                Store.Remove_Cart();
                break;

            case 3:

                std::cout << "total price at " << total_price << std::endl;

                for (int i = 0; i < 10; i++){

                    keyid = Cart[i];

                    if (Cart[i] == 0){
                    	
                        continue;

                    }else{
						
                        total_price += Car[keyid-1].taxed_price_with_quantity();
                    }
                }

                Store.Clear_Cart();

                std::cout << "======================================================" << "\n"
                    <<   "Successfully checked out with a total of $" << total_price << std::endl;
                input_reset();
                system("cls");
                return;
                break;
            
            case 4:

                Store.Clear_Cart();
                std::cout << "======================================================" << "\n"
                    <<   "Successfully cleared the cart!"<< std::endl;
                input_reset();
                system("cls");
                return;
                break;

            case 5:

                system("cls");
                return;
                break;

            default:

				system("cls");
                std::cout << "Invalid input! Please try again!" << std::endl;
                break;
        }

        Store.View_Cart();

    }while(option_pick != 5);
}


void Main_menu(){
    
    int option_pick;

    do{
        std::cout << "============================================" << "\n"
                <<   "||     Welcome to Automobile Industry!    ||" << "\n"
                <<   "============================================" << "\n"
                <<   "||  Please choose an option (between 1-5) ||" << "\n"
                <<   "============================================" << "\n"
                <<   "|| [1] View the list of vehicles          ||" << "\n"
                <<   "|| [2] Add a vehicle to cart              ||" << "\n"
                <<   "|| [3] Remove a vehicle to cart           ||" << "\n"
                <<   "|| [4] Proceed to Cart                    ||" << "\n"
                <<   "|| [5] Quit Program                       ||" << "\n"
                <<   "============================================" << "\n";


        std::cout <<   "Selected option: ";
        std::cin >> option_pick;

        switch(option_pick){

            case 1:

                system("cls");
                Store.View_Cars();
                break;

            case 2:

                system("cls");
                Store.Add_Cart();
                break;

            case 3:

                system("cls");
                Store.Remove_Cart();
                break;
            
            case 4:

                system("cls");
                Proceed_to_Cart();
                break;

            case 5:

                system("cls");
                exit(0);
                break;

            default:

				system("cls");
                std::cout << "Invalid input! Please try again!" << std::endl;
                break;
        }
    }while(option_pick != 5);
}



int main(){

    
    Main_menu();


    return 0;
}
