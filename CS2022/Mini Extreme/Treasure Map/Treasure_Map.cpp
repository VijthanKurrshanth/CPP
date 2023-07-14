#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct treasure{
    int id;
    int coins;
    int d;
    treasure* pi;
};

struct road{
    treasure* start_t;
    treasure* end_t;
    int cost;
};

void initialize_single_source(vector<treasure>& treasure_arr, treasure* s ,int no_treasure){
    treasure* temp;
    for (int i = 0; i < no_treasure; i++){
        temp = &treasure_arr[i];
        temp->d = numeric_limits<int>::max();
        temp->pi = nullptr;
    }
    s->d = 0;
}

void relax(road& edge){
    if (edge.end_t->d > edge.start_t->d + edge.cost){
        edge.end_t->d = edge.start_t->d + edge.cost;
        edge.end_t->pi = edge.start_t;
    }
    
    
}

int findMaxCoins(int no_treasure, vector<treasure>& treasure_arr, int no_road, vector<road>& road_arr, int start) {
    treasure* s;
    for (int i = 0; i < no_treasure; i++)
    {
        if (start == treasure_arr[i].id){
            s = &treasure_arr[i];
        }
    }
    initialize_single_source(treasure_arr, s, no_treasure);
    int min_d = treasure_arr[0].d;
    treasure* u = &treasure_arr[0];
    for (int count = 0; count < no_treasure; count++){
        vector<treasure> visited_arr;
        for (int i = 0; i < no_treasure; i++){
            bool check = false;
            for (auto x : visited_arr){
                if (treasure_arr[i].id == x.id){
                    check = true;
                }
            }
            if (treasure_arr[i].d < min_d && !check){
                u = &treasure_arr[i];
                visited_arr.push_back(*u);
            }
        }
        vector<road> adj_u;
        for (int i = 0; i < no_road; i++){
            if (road_arr[i].start_t == u){
                adj_u.push_back(road_arr[i]);
            }
        }
        for (auto x : adj_u){
            relax(x);
        }
    }
    int fin_d = 0;
    treasure* last_node;
    for (int count = 0; count < no_treasure; count++){
        if (treasure_arr[count].d > fin_d && treasure_arr[count].d <1000){
            fin_d = treasure_arr[count].d;
            last_node = &treasure_arr[count];
        }
    }
    int collected = 0;
    while (last_node->d != 0){
        collected += last_node->coins;
        last_node = last_node->pi;
    }

    int result = collected - fin_d;
    return result;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string no_treasure_temp;
    getline (cin, no_treasure_temp);
    int no_treasure = stoi(no_treasure_temp);

    vector<treasure> treasure_arr;
    for (int i; i < no_treasure; i++){
        treasure* temp = new treasure;

        string treasure_temp;
        getline (cin, treasure_temp);
        int len = treasure_temp.size();
        
        string id_str = "";
        int j = 0;
        while (treasure_temp[j] != ' '){
            id_str += treasure_temp[j];
            j++;
        }
        temp->id = stoi(id_str);
        j++;

        string coins_str = "";
        while (j < len){
            coins_str += treasure_temp[j];
            j++;
        }
        temp->coins = stoi(coins_str);

        treasure_arr.push_back(*temp);
    }

    string no_road_temp;
    getline (cin, no_road_temp);
    int no_road = stoi(no_road_temp);

    vector<road> road_arr;
    for (int i; i < no_road; i++){
        road* temp = new road;

        string road_temp;
        getline (cin, road_temp);
        int len = road_temp.size();

        string id_str = "";
        int j = 0;
        while (road_temp[j] != ' '){
            id_str += road_temp[j];
            j++;
        }
        int id = stoi(id_str);
        treasure* temp2;
        for (int l = 0; l < no_treasure; l++)
        {
            if (id == treasure_arr[l].id){
                temp2 = &treasure_arr[l];
            }
        }
        temp->start_t = temp2;
        j++;

        id_str = "";
        while (road_temp[j] != ' '){
            id_str += road_temp[j];
            j++;
        }
        id = stoi(id_str);
        for (int l = 0; l < no_treasure; l++)
        {
            if (id == treasure_arr[l].id){
                temp2 = &treasure_arr[l];
            }
        }
        temp->end_t = temp2;
        j++;

        string cost_str = "";
        while (j < len){
            cost_str += road_temp[j];
            j++;
        }
        temp->cost = stoi(cost_str);

        road_arr.push_back(*temp);
    }
    
    string start_temp;
    getline (cin, start_temp);
    int start = stoi(start_temp);

    int result = findMaxCoins(no_treasure, treasure_arr, no_road, road_arr, start);

    cout << result;
    return 0;
}
