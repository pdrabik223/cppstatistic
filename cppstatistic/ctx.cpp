#include "ctx.h"

template<class X, class Y>
void ctx<X, Y>::addset(X x, Y y)
{
    this->x.push_back(x);
    this->y.push_back(y);

}

template <class X,class Y>
void ctx<X,Y>::json_parser(std::string file_adress) {
    std::ofstream myfile;
    myfile.open(file_adress, std::ios::in);

    myfile << "{";
    myfile << "\"name\":";
    myfile << "\"" << this->name << "\",";
    myfile << "\"data\":{";

    myfile << "\"x\":[";
    for (int i = 0; i < x.size(); i++) {

        myfile << x[i];
        if (i != x.size() - 1) myfile << ",";
    }
    myfile << "],";


    myfile << "\"y\":[";
    for (int i = 0; i < y.size(); i++) {

        myfile << y[i];
        if (i != y.size() - 1) myfile << ",";
    }
    myfile << "]}}";
    myfile.close();
}