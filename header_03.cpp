//
//  heörmeör.hpp
//  korszám_HF3
//
//  Created on 2021. 04. 15..

#ifndef heormeor_hpp
#define heormeor_hpp

#include <stdio.h>
#include <math.h>


using namespace std;

class NumDiff
{
private:
    
    const int a = 200;
    const int F = 900;
    const double q = 1.8;
    const int y_shift = 35;
    
public:
    //main (hiperbolic) function
    double fun(double x){return F/q * (cosh(q/F *x) - cosh((q*a)/(2*F)))+y_shift;}
    
    // Richardson_2th
    template<typename T>
    T Dfun(T x, double h){ return ( (fun(x+h)-fun(x-h)) / (2*h));}
    
    // Richardson_4th
    template<typename T>
    T Sfun(double h, T x){ return ( (4* Dfun(x, h) - Dfun(x, 2*h) ) /3 );}
    
    // Richardson_6th
    template<typename T>
    T Hfun(double h, T x){ return ( (16*Sfun(h,x) - Sfun(2*h, x) ) /15 );}
    
    //Arc lenght
    double len(double x){
        auto diff = Hfun(1,x);
        return sqrt(1 + (diff*diff));
    }

};


class NumInt
{
private:
    const double a =0.0;
    const double b = 200.0;
    NumDiff dfd;
    
public:
    
    //Kozeppontos-rule
    template<typename T>
    T midint(int n)
    {
      double dx = (b-a)/n;
      T Msol = (dfd.len(a) + dfd.len(b));
      for(int i=1; i<n+1; i++){
          Msol += dfd.len(a + (i+0.5)*dx);
        }
      return  Msol*dx;
    }
    
    //Trapez rule
    template<typename T>
    T trapint(int n)
    {
        double dx = (b-a)/n;
        T sum0 = (dfd.len(a) + dfd.len(b))/2;
        for(int i=1; i<n+1; i++){
            sum0 += dfd.len(a + i*dx);
          }
        return  sum0*(dx);
    }
    
    //Simpson (1/3)-rule
    template<typename T>
    T simpint(int n)
    {
        double dx = (b-a)/n;
        auto sum_i =0;
        auto sum_j =0;
        
        // paros iteracio
        for(int i=1; i<n; i++){
            sum_i += dfd.len(a + 2*i*dx);
          }
        
        //paratlan iteracio
        for(int j=2; j<n-1; j++){
            sum_j += dfd.len(a + (2*j-1)*dx);
          }
        
        T susol = (dx/3)*(dfd.len(a) + 2*sum_i + 4*sum_j + dfd.len(b));
        return  susol;
    }
    
};

#endif /* heormeor_hpp */
