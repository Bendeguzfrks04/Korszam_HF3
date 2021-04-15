//
//  main.cpp
//  korszám_HF3
//
//  Created by Farkas Bende on 2021. 04. 15..
//

#include <iostream>
#include <fstream>
#include <math.h>
#include "heormeor.hpp"

using namespace std;

int main()
{
    NumInt dx;
    ofstream ofile("/Users/farkasbende/Desktop/Korszám 1/korszám_HF3/korszám_HF3/sol_HF3.txt");
    if(ofile.is_open())
    {
        ofile << "Integral közelítése középpontos módszerrel: " << dx.midint<double>(500) << ",\n";
        ofile << "Integral közelítése trapéz-szabállyal: " << dx.trapint<double>(700) << ",\n";
        ofile << "Integral közelítése Simpson (1/3)-szabállyal: " << dx.simpint<double>(4) ;
        ofile.close();
    }
    else
    {
        cout<<"Could not open input file\n";
    }
    
    return 0;
}

