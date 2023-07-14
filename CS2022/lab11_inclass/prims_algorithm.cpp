#include <iostream>
#include<list>
#include <string>
using namespace std;

struct edge{
    string label = "0-0" ;
    int weight = 0;
};

struct vertex{
    int label = 0;
    list<edge> edges{};

};

mst_prim()

int main(){

    vertex* vertices[6];

    for (int i = 0; i < 6; i++)
    {
        vertices[i] = new vertex;

        switch(i) {
        case 0:
        {
            edge* zero_1 = new edge;
            zero_1->weight = 3;
            zero_1->label = "0-1";
            vertices[0]->edges.push_back(*zero_1);
            edge* zero_5 = new edge;
            zero_5->weight = 1;
            zero_5->label = "0-5";
            vertices[0]->edges.push_back(*zero_5);
            break;
        }

        case 1:
        {
            edge* one_0 = new edge;
            one_0->weight = 3;
            one_0->label = "0-1";
            vertices[1]->edges.push_back(*one_0);
            edge* one_2 = new edge;
            one_2->weight = 2;
            one_2->label = "1-2";
            vertices[1]->edges.push_back(*one_2);
            edge* one_3 = new edge;
            one_3->weight = 1;
            one_3->label = "1-3";
            vertices[1]->edges.push_back(*one_3);
            edge* one_4 = new edge;
            one_4->weight = 10;
            one_4->label = "1-4";
            vertices[1]->edges.push_back(*one_4);
            break;
        }

        case 2:
        {
            edge* two_1 = new edge;
            two_1->weight = 2;
            two_1->label = "1-2";
            vertices[2]->edges.push_back(*two_1);
            edge* two_3 = new edge;
            two_3->weight = 3;
            two_3->label = "2-3";
            vertices[2]->edges.push_back(*two_3);
            edge* two_5 = new edge;
            two_5->weight = 5;
            two_5->label = "2-5";
            vertices[2]->edges.push_back(*two_5);
            break;
        }

        case 3:
        {
            edge* three_1 = new edge;
            three_1->weight = 1;
            three_1->label = "1-3";
            vertices[3]->edges.push_back(*three_1);
            edge* three_2 = new edge;
            three_2->weight = 3;
            three_2->label = "2-3";
            vertices[3]->edges.push_back(*three_2);
            edge* three_4 = new edge;
            three_4->weight = 5;
            three_4->label = "3-4";
            vertices[3]->edges.push_back(*three_4);
            break;
        }

        case 4:
        {
            edge* four_1 = new edge;
            four_1->weight = 10;
            four_1->label = "1-4";
            vertices[4]->edges.push_back(*four_1);
            edge* four_3 = new edge;
            four_3->weight = 5;
            four_3->label = "3-4";
            vertices[4]->edges.push_back(*four_3);
            edge* four_5 = new edge;
            four_5->weight = 4;
            four_5->label = "4-5";
            vertices[4]->edges.push_back(*four_5);
            break;
        }

        case 5:
        {
            edge* five_0 = new edge;
            five_0->weight = 1;
            five_0->label = "0-5";
            vertices[5]->edges.push_back(*five_0);
            edge* five_2 = new edge;
            five_2->weight = 5;
            five_2->label = "2-5";
            vertices[5]->edges.push_back(*five_2);
            edge* five_4 = new edge;
            five_4->weight = 4;
            five_4->label = "4-5";
            vertices[5]->edges.push_back(*five_4);
            break;
        }
        }
    }


    
}

