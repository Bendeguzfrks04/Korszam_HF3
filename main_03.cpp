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
    /*  // to check out and to try other n value
    cout << "Integral közelítése középpontos módszerrel: " << dx.midint<double>(500) << endl;
    cout << "Integral közelítése trapéz-szabállyal: " << dx.trapint<double>(700) << endl;
    cout << "Integral közelítése Simpson (1/3)-szabállyal: " << dx.simpint<double>(4) << endl;
     */

    ofstream ofile("sol_HF3.txt");
    /* Én Xcode-ban dolgozok és itt ide kellett irni a teljes path-ot ("/Users/Desktop/.../sol_HF3.txt"),
    de most csak a txt nevét hagyom benn. (ha esetleg nem tudná megnyitni a fájlt) */
    if(ofile.is_open())
    {
        ofile << "Integral közelítése középpontos módszerrel: " << dx.midint<double>(500) << ",\n";
        ofile << "Integral közelítése trapéz-szabállyal: " << dx.trapint<double>(700) << ",\n";
        ofile << "Integral közelítése Simpson (1/3)-szabállyal: " << dx.simpint<double>(4) ;
    }
    else
    {
        cout<<"Could not open input file\n";
    }
    
    ofile.close();

    return 0;
}

