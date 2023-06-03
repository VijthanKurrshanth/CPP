#include <iostream>
#include<list>
#include <string>
using namespace std;


struct vertex{
    int label = 0;
    list <vertex> neighbours{};
    int key =100;
    int pi =-1;

};


vertex extract_min(list <vertex>& Q){
    list<vertex>::iterator it = Q.begin();
    vertex min = *it;
    for (size_t i = 1; i < Q.size(); i++)
    {
        list<vertex>::iterator it = Q.begin();
        advance(it, i);
        if (it->key < min.key)
        {
            min = *it;
        }
        
    }
    return min;
}

bool find(list <vertex>& Q, vertex key){
    for (size_t i = 0; i < Q.size(); i++)
    {
        list<vertex>::iterator it = Q.begin();
        if (it->label == key.label)
        {
           return 1;
        }
        else{
            return 0;
        }
        
    }
    
}

void mst_prim(list <vertex>& vertices, int(* weight_matrix)[6]){
    
    for (size_t i = 0; i < vertices.size(); i++)
    {
        list<vertex>::iterator it = vertices.begin();
        advance(it, i);
        it->key = 100;
        it->pi = -1;
    }
    
    list <vertex> Q = vertices;
    while (Q.size() != 0){
        vertex u = extract_min(Q);
        Q.remove(u);
        for (size_t i = 0; i < u.neighbours.size(); i++)
        {
            list<vertex>::iterator it1 = u.neighbours.begin();
            advance(it1, i);
            int x =weight_matrix[it1->label][u.label];
            if ((find(Q, *it1) && weight_matrix[it1->label][u.label] < it1->key))
            {
                it1->pi = u.label;
                it1->key = weight_matrix[it1->label][u.label];
            }
            
        }
        
        
    }

    cout << "Edges of the MST are :"<< endl;
    for (size_t i = 0; i < vertices.size(); i++)
    {
        list<vertex>::iterator it = vertices.begin();
        advance(it, i);
        cout << it->label << "-" << it->pi<< endl;

    }
    
    
}

int main(){

    int weight_matrix[6][6] = {{0,3,0,0,0,1},{3,0,2,1,10,0},{0,2,0,3,0,5},{0,1,3,0,5,0},{0,10,0,5,0,4},{1,0,5,0,4,0}};
    int(* pointer)[6] = weight_matrix;

    list <vertex> vertices(6);

    for (size_t i = 0; i < 6; i++)
    {
        list<vertex>::iterator it = vertices.begin();
        advance(it, i);
        it->label = i;
    }

    for (size_t i = 0; i < 6; i++)
    {
        list<vertex>::iterator it = vertices.begin();
        advance(it, i);
        switch(i) {
        case 0:
        {
            auto temp = it;
            advance(it, 1);
            temp->neighbours.push_back(*it);
            advance(it, 4);
            temp->neighbours.push_back(*it);
            break;
        }

        case 1:
        {
            auto temp = it;
            advance(it, -1);
            temp->neighbours.push_back(*it);
            advance(it, 2);
            temp->neighbours.push_back(*it);
            advance(it, 1);
            temp->neighbours.push_back(*it);
            advance(it, 1);
            temp->neighbours.push_back(*it);
            break;
        }

        case 2:
        {
            auto temp = it;
            advance(it, -1);
            temp->neighbours.push_back(*it);
            advance(it, 2);
            temp->neighbours.push_back(*it);
            advance(it, 2);
            temp->neighbours.push_back(*it);
            break;
        }

        case 3:
        {
            auto temp = it;
            advance(it, -2);
            temp->neighbours.push_back(*it);
            advance(it, 1);
            temp->neighbours.push_back(*it);
            advance(it, 2);
            temp->neighbours.push_back(*it);
            break;
        }

        case 4:
        {
            auto temp = it;
            advance(it, -3);
            temp->neighbours.push_back(*it);
            advance(it, 2);
            temp->neighbours.push_back(*it);
            advance(it, 2);
            temp->neighbours.push_back(*it);
            break;
        }

        case 5:
        {
            auto temp = it;
            advance(it, -5);
            temp->neighbours.push_back(*it);
            advance(it, 2);
            temp->neighbours.push_back(*it);
            advance(it, 2);
            temp->neighbours.push_back(*it);
            break;
        }
        }
    }
    
    mst_prim(vertices, pointer);

    
}

