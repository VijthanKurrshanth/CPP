#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct in_ord{

std::string c_ord_id ;
std::string inst ;
int side, qty;
double price;

};

/// creates in_ord struct using the row in the input order
/// returns the in_ord struct pointer 
in_ord* record(std::vector<std::string> row){
    in_ord* order = new in_ord;
    order->c_ord_id = row[0];
    order->inst = row[1];
    order->side = std::stoi(row[2]);
    order->price = std::stod(row[3]);
    order->qty = std::stoi(row[4]);

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

        // Print line (read from file) in Console
        std::cout << line << std::endl;

        line_no += 1;

    }

    fin.close();
 
    return 0;

}