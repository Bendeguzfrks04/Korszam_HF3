//
//  main.cpp
//  Korszam_HF4
//
//  Created by Farkas Bende on 2021. 04. 18..
//

#include <iostream>
#include <math.h>
#include "header.hpp"
# include <fstream>


using  namespace std;


int main()
{
    double y0 = 0;
    double h = 5e-4;
    double t0 = 0;
    double t1 = 1;
    
    auto NeM = Newton(y0, t0, t1, h, fun);
    auto RK4 = solve_rk4(y0, t0, t1, h, fun);
    auto analytic = tan(t1);
    
  
    ofstream ofile("/Users/farkasbende/Desktop/Korszám 1/Korszam_HF4/Korszam_HF4/sol_HF4.txt");
    if(ofile.is_open())
    {
        ofile << "Method:\t\t Newton\t\t\t RungeKutta_4th\t\t\t Analytic" << endl;
        ofile << "Solution:\t "<< NeM << "\t\t\t\t" << RK4 << "\t\t\t" << analytic << endl;
    }
    else
    {
        cout<<"Could not open input file\n";
    }
    
    ofile.close();
    

    return 0;
}
