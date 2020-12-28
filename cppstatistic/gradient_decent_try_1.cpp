
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>

template<class T=int >
class chart {

 std::string name;
public:
    std::vector<T> x;
    std::vector<T> y;
    chart(std::string _name) {
        name = _name;
    }
    
    void show() {
        std::cout << name<<" :\ny :\tx:";
        for (int i = 0; i < y.size(); i++)         std::cout << y[i] << "\t" << x[i] << "\n";
 }
    void json_parser(std::string file_adress) {
        std::ofstream myfile;
        myfile.open(file_adress);
        
        myfile << "{";
        myfile << "\"name\":";
        myfile << "\""<<name<< "\",";
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
};

int main()
{
    srand(time(NULL));
    std::clog << "hello world";
    chart<double> first_chart("errors");
    

    chart<double> second_chart("milion_test");
    for (int i = 0; i < 1000; i++) {
        second_chart.x.push_back( i);
        second_chart.y.push_back( (rand()%50+i)-25-(i/2));



    }
    second_chart.json_parser("data2.json");


        int x[] = { 1, 2, 3, 4, 5, 6};
        int y[] = { 1, 3, -3, 2, 5, 7};
        


        double overall_err = 0.0f;
        double a = 0.0f;
        double b = 0.0f;
        double miu = 0.01f;
        for (int i = 0; i < 25; i++) {
            int idx = i % 5;
            double p = a + b * x[idx];
            double err = p - y[idx];
            a= a - miu* err;
           b = b -miu * err * x[idx];
           overall_err += err;
           printf("a =\t%f b = \t%f err = \t%f\n", a, b, err);
           first_chart.y.push_back(err);
           first_chart.x.push_back(i);
        }
        printf("\n err in the end:%f", overall_err / 20);

        first_chart.json_parser("data.json");



    return 0;
}


