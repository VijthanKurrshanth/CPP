#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct in_ord{

std::string c_ord_id,inst,ord_id;
int side, qty;
double price;

};

std::string intToHex(int number) {
    std::stringstream stream;
    stream << std::hex << number;  // Convert int to hexadecimal string
    return stream.str();  // Get the string representation
}

/// creates in_ord struct using the row in the input order
/// returns the in_ord struct pointer 
in_ord* record(std::vector<std::string> row, int order_no){
    in_ord* order = new in_ord;
    order->c_ord_id = row[0];
    order->inst = row[1];
    order->side = std::stoi(row[2]);
    order->price = std::stod(row[3]);
    order->qty = std::stoi(row[4]);
    order->ord_id = intToHex(order_no);

    return order;
}

int main(){
    std::vector<in_ord*> 
    blue_list_rose, pink_list_rose,
    blue_list_lavender, pink_list_lavender,
    blue_list_lotus, pink_list_lotus,
    blue_list_tulip, pink_list_tulip,
    blue_list_orchid, pink_list_orchid;

    // Creation of ifstream class object to read the file
    std::ifstream fin;

    fin.open("orders1.csv");

    int line_no = 1;
    int order_no = 1;
    std::string line, word;
    std::vector<std::string> row;
    while (std::getline(fin, line)) {
        
        if (line_no < 3){
            line_no += 1;
            continue;
        }

        row.clear();

        // used for breaking words
        std::stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (std::getline(s, word, ',')) {
  
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        
        in_ord* order = record(row, order_no);
        order_no += 1;

        if (order->inst == "Rose"){
            switch (order->side){
                case 1:
                blue_list_rose.push_back(order);
                break;
                case 2:
                pink_list_rose.push_back(order);
                break;
            }

        }
        else if (order->inst == "Lavender"){
            switch (order->side){
                case 1:
                blue_list_lavender.push_back(order);
                break;
                case 2:
                pink_list_lavender.push_back(order);
                break;
            }

        }
        else if (order->inst == "Lotus"){
            switch (order->side){
                case 1:
                blue_list_lotus.push_back(order);
                break;
                case 2:
                pink_list_lotus.push_back(order);
                break;
            }

        }
        else if (order->inst == "Tulip"){
            switch (order->side){
                case 1:
                blue_list_tulip.push_back(order);
                break;
                case 2:
                pink_list_tulip.push_back(order);
                break;
            }

        }
        else if (order->inst == "Orchid"){
            switch (order->side){
                case 1:
                blue_list_orchid.push_back(order);
                break;
                case 2:
                pink_list_orchid.push_back(order);
                break;
            }

        }
        else{

        }
        
        // Print line (read from file) in Console
        std::cout << line << std::endl;

        line_no += 1;

    }

    fin.close();
 
    return 0;

}