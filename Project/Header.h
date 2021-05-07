//
//  Header.h
//  BULAJ
//
//  Created by Farkas Bende on 2021. 05. 05..
//

#ifndef Header_h
#define Header_h

using namespace std;

template<typename MassDim, typename LenDim, typename TimDim, typename ElecDim, typename TempDim, typename MolDim, typename LumDim>
class RQuantity{
private:
    double value;

public:
    constexpr RQuantity() : value(0.0) {} // constructors
    constexpr RQuantity(double val) : value(val) {}
    constexpr RQuantity(long double val) : value(static_cast<double>(val)) {}
    
    // The intrinsic operations for a quantity with a unit is addition and subtraction
    constexpr RQuantity const& operator+=(const RQuantity& rhs)
    {
        value += rhs.value;
        return  *this;
    }
    constexpr RQuantity const& operator-=(const RQuantity& rhs)
    {
        value -= rhs.value;
        return  *this;
    }
    
    // Returns the value of the quantity in multiples of the specified unit
    constexpr double Convert(const RQuantity& rhs) const
    {
        return value / rhs.value;
    }
    
    // returns the raw value of the quantity (should not be used)
    constexpr double getvalue() const
    {
        return value;
    }
    //char operation;
    //string pref1, pref2;
   // double number1, number2;
    friend ostream& operator<<(ostream& out, RQuantity& rhs);
    friend istream& operator>>(istream& in, RQuantity& rhs);

};

// Predefined (physical unit) quantity types:
typedef RQuantity<ratio<1>, ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>> QMass;
typedef RQuantity<ratio<2>, ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>> SqMass;
typedef RQuantity<ratio<0>, ratio<1>, ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>> QLen;
typedef RQuantity<ratio<0>, ratio<2>, ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>> QArea;
typedef RQuantity<ratio<0>, ratio<0>, ratio<1>, ratio<0>, ratio<0>, ratio<0>, ratio<0>> QTime;
typedef RQuantity<ratio<0>, ratio<0>, ratio<2>, ratio<0>, ratio<0>, ratio<0>, ratio<0>> SqTime;
typedef RQuantity<ratio<0>, ratio<1>, ratio<-1>,ratio<0>, ratio<0>, ratio<0>, ratio<0>> QVelocity;
typedef RQuantity<ratio<0>, ratio<2>, ratio<-2>,ratio<0>, ratio<0>, ratio<0>, ratio<0>> SqVelocity;
typedef RQuantity<ratio<0>, ratio<1>, ratio<-2>,ratio<0>, ratio<0>, ratio<0>, ratio<0>> QAcceleration;
typedef RQuantity<ratio<0>, ratio<2>, ratio<-4>,ratio<0>, ratio<0>, ratio<0>, ratio<0>> SqAcceleration;
typedef RQuantity<ratio<1>, ratio<1>, ratio<-2>,ratio<0>, ratio<0>, ratio<0>, ratio<0>> QForce;
typedef RQuantity<ratio<2>, ratio<2>, ratio<-4>,ratio<0>, ratio<0>, ratio<0>, ratio<0>> SqForce;
typedef RQuantity<ratio<1>, ratio<-1>,ratio<-2>,ratio<0>, ratio<0>, ratio<0>, ratio<0>> QPressure;
typedef RQuantity<ratio<2>, ratio<-2>,ratio<-4>,ratio<0>, ratio<0>, ratio<0>, ratio<0>> SqPressure;

typedef RQuantity<ratio<0>, ratio<0>, ratio<0>, ratio<1>, ratio<0>, ratio<0>, ratio<0>> QElec;
typedef RQuantity<ratio<0>, ratio<0>, ratio<0>, ratio<2>, ratio<0>, ratio<0>, ratio<0>> SqElec;
typedef RQuantity<ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<1>, ratio<0>, ratio<0>> QTemp;
typedef RQuantity<ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<2>, ratio<0>, ratio<0>> SqTemp;
typedef RQuantity<ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<1>, ratio<0>> QMol;
typedef RQuantity<ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<2>, ratio<0>> SqMol;
typedef RQuantity<ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<1>> QLum;
typedef RQuantity<ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<2>> SqLum;
// Replacement of "double" type
typedef RQuantity<ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>, ratio<0>> QNumber;


//*************************************
// Basic arithmetic operators
//*************************************

//Addition operater
template< typename M, typename L, typename t, typename I, typename T, typename n, typename Iv>
constexpr RQuantity<M, L, t, I, T, n, Iv> operator+(const RQuantity<M, L, t, I, T, n, Iv>& lhs,
                                                    const RQuantity<M, L, t, I, T, n, Iv>& rhs){
    return  RQuantity<M, L, t, I, T, n, Iv>(lhs.getvalue() + rhs.getvalue());
}

//Subtraction  operater
template< typename M, typename L, typename t, typename I, typename T, typename n, typename Iv>
constexpr RQuantity<M, L, t, I, T, n, Iv> operator-(const RQuantity<M, L, t, I, T, n, Iv>& lhs,
                                       const RQuantity<M, L, t, I, T, n, Iv>& rhs){
    return  RQuantity<M, L, t, I, T, n, Iv>(lhs.getvalue() - rhs.getvalue());
}

//Multiplication operater
template< typename M1, typename L1, typename t1,  typename I1, typename T1, typename n1, typename Iv1, typename M2, typename L2, typename t2, typename I2, typename T2, typename n2, typename Iv2>
constexpr RQuantity<ratio_add<M1, M2>, ratio_add<L1, L2>, ratio_add<t1,t2>, ratio_add<I1,I2>, ratio_add<T1,T2>, ratio_add<n1,n2>, ratio_add<Iv1,Iv2>>
operator*(const RQuantity<M1, L1, t1, I1, T1, n1, Iv1>& lhs,
          const RQuantity<M2, L2, t2, I2, T2, n2, Iv2>& rhs){
    return  RQuantity<ratio_add<M1, M2>, ratio_add<L1, L2>, ratio_add<t1,t2>, ratio_add<I1,I2>, ratio_add<T1,T2>, ratio_add<n1,n2>, ratio_add<Iv1,Iv2>>
    (lhs.getvalue() * rhs.getvalue());
}
template< typename M, typename L, typename t, typename I, typename T, typename n, typename Iv>
constexpr RQuantity<M, L, t, I, T, n, Iv> operator*(const double& lhs, const RQuantity<M, L, t, I, T, n, Iv>& rhs)
{
    return RQuantity<M, L, t, I, T, n, Iv>(lhs*rhs.getvalue());
}


//Division  operater
template< typename M1, typename L1, typename t1,  typename I1, typename T1, typename n1, typename Iv1, typename M2, typename L2, typename t2, typename I2, typename T2, typename n2, typename Iv2>
constexpr RQuantity<ratio_subtract<M1, M2>, ratio_subtract<L1, L2>, ratio_subtract<t1,t2>, ratio_subtract<I1,I2>, ratio_subtract<T1,T2>, ratio_subtract<n1,n2>, ratio_subtract<Iv1,Iv2>>
operator/(const RQuantity<M1, L1, t1, I1, T1, n1, Iv1>& lhs,
          const RQuantity<M2, L2, t2, I2, T2, n2, Iv2>& rhs){
    return RQuantity<ratio_subtract<M1, M2>, ratio_subtract<L1, L2>, ratio_subtract<t1,t2>, ratio_subtract<I1,I2>, ratio_subtract<T1,T2>, ratio_subtract<n1,n2>, ratio_subtract<Iv1,Iv2>>
    (lhs.getvalue() / rhs.getvalue());
}

template< typename M, typename L, typename t, typename I, typename T, typename n, typename Iv>
constexpr RQuantity<ratio_subtract<ratio<0>, M>, ratio_subtract<ratio<0>, L>,
                    ratio_subtract<ratio<0>, t>, ratio_subtract<ratio<0>, I>, ratio_subtract<ratio<0>, T>, ratio_subtract<ratio<0>, n>, ratio_subtract<ratio<0>, Iv>>
    operator/(double x, const RQuantity<M, L, t, I, T, n, Iv>& rhs)
{
    return RQuantity<ratio_subtract<ratio<0>, M>, ratio_subtract<ratio<0>, L>,
                     ratio_subtract<ratio<0>, t>, ratio_subtract<ratio<0>, I>, ratio_subtract<ratio<0>, T>, ratio_subtract<ratio<0>, n>, ratio_subtract<ratio<0>, Iv>>
                    (x / rhs.getValue());
}
template< typename M, typename L, typename t, typename I, typename T, typename n, typename Iv>
constexpr RQuantity<M, L, t, I, T, n, Iv>
    operator/(const RQuantity<M, L, t, I, T, n, Iv>& rhs, double x)
{
    return RQuantity<M, L, t, I, T, n, Iv>(rhs.getvalue() / x);
}


// Comparison operators for quantities:
template< typename M, typename L, typename t, typename I, typename T, typename n, typename Iv>
constexpr bool operator==(const RQuantity<M, L, t, I, T, n, Iv>& lhs, const RQuantity<M, L, t, I, T, n, Iv>& rhs)
{
    return (lhs.getvalue() == rhs.getvalue());
}

template< typename M, typename L, typename t, typename I, typename T, typename n, typename Iv>
constexpr bool operator!=(const RQuantity<M, L, t, I, T, n, Iv>& lhs, const RQuantity<M, L, t, I, T, n, Iv>& rhs)
{
    return (lhs.getvalue() != rhs.getvalue());
}

template< typename M, typename L, typename t, typename I, typename T, typename n, typename Iv>
constexpr bool operator<=(const RQuantity<M, L, t, I, T, n, Iv>& lhs, const RQuantity<M, L, t, I, T, n, Iv>& rhs)
{
    return (lhs.getvalue() <= rhs.getvalue());
}

template< typename M, typename L, typename t, typename I, typename T, typename n, typename Iv>
constexpr bool operator>=(const RQuantity<M, L, t, I, T, n, Iv>& lhs, const RQuantity<M, L, t, I, T, n, Iv>& rhs)
{
    return (lhs.getvalue() >= rhs.getvalue());
}

template< typename M, typename L, typename t, typename I, typename T, typename n, typename Iv>
constexpr bool operator<(const RQuantity<M, L, t, I, T, n, Iv>& lhs, const RQuantity<M, L, t, I, T, n, Iv>& rhs)
{
    return (lhs.getvalue() < rhs.getvalue());
}

template< typename M, typename L, typename t, typename I, typename T, typename n, typename Iv>
constexpr bool operator>(const RQuantity<M, L, t, I, T, n, Iv>& lhs, const RQuantity<M, L, t, I, T, n, Iv>& rhs)
{
    return (lhs.getvalue() > rhs.getvalue());
}


//*****************
// Predefined units:
//*****************


// Predefined mass units:
constexpr QMass kg(1.0);
constexpr QMass gramme = 0.001 * kg;
constexpr QMass tonne = 1000 * kg;
constexpr QMass dkg = 0.01 * kg;

constexpr SqMass kg2 = kg*kg;
constexpr SqMass gramme2 = gramme*gramme;
constexpr SqMass tonne2 = tonne*tonne;
constexpr SqMass dkg2 = dkg*dkg;

constexpr QNumber kgp = kg/kg;
constexpr QNumber grammep = gramme/gramme;
constexpr QNumber tonnep = tonne/tonne;
constexpr QNumber dkgp = dkg/dkg;

constexpr QLen metre(1.0);
constexpr QLen dm = 0.1 * metre;
constexpr QLen cm = 0.01 * metre;
constexpr QLen mm = 0.001 * metre;
constexpr QLen km = 1000 * metre;

constexpr QArea km2 = km*km;
constexpr QArea metre2 = metre*metre;
constexpr QArea dm2 = dm*dm;
constexpr QArea cm2 = cm*cm;
constexpr QArea mm2 = mm * mm;

constexpr QNumber kmp = km/km;
constexpr QNumber metrep = metre/metre;
constexpr QNumber dmp = dm/dm;
constexpr QNumber cmp = cm/cm;
constexpr QNumber mmp = mm / mm;


// Predefined time units:
constexpr QTime second(1.0);
constexpr QTime minute = 60 * second;
constexpr QTime hour = 60 * minute;
constexpr QTime day = 24 * hour;

constexpr SqTime second2 = second*second;
constexpr SqTime minute2 = minute*minute;
constexpr SqTime hour2 = hour*hour;
constexpr SqTime day2 = day*day;

constexpr QNumber secondp = second/second;
constexpr QNumber minutep = minute/minute;
constexpr QNumber hourp = hour/hour;
constexpr QNumber dayp = day/day;

constexpr QElec amper(1.0);
constexpr QElec mA = 0.001 * amper;
constexpr SqElec amper2 = amper * amper;
constexpr SqElec mA2 = mA * mA;
constexpr QNumber amperp = amper / amper;
constexpr QNumber mAp = mA / mA;

constexpr QTemp Kelvin(1.0);
constexpr SqTemp kelvin2 = Kelvin * Kelvin;
constexpr QNumber kelvinp = Kelvin / Kelvin;

constexpr QMol mol(1.0);
constexpr SqMol mol2 = mol * mol;
constexpr QNumber molp = mol / mol;

constexpr QLum cd(1.0);
constexpr SqLum cd2 = cd * cd;
constexpr QNumber cdp = cd / cd;


// Predefined mixed units:
constexpr QAcceleration a =  metre / (second*second);
constexpr SqAcceleration a2 =  (metre / (second*second)) * (metre / (second*second));
constexpr QNumber accp = a/a;

constexpr QVelocity mps = (metre/second);
constexpr QVelocity kmh = 3.6 *  mps;
constexpr SqVelocity mps2 = mps* mps;
constexpr SqVelocity kmh2 = kmh * kmh;
constexpr QNumber mpsp = mps/ mps;
constexpr QNumber kmhp = kmh / kmh;

constexpr QForce Newton(1.0);
constexpr QForce kilopond = kg*a;
constexpr QForce si_ero = kg*metre / (second*second);
constexpr SqForce Newton2 = Newton * Newton;
constexpr QNumber Newtonp = Newton / Newton;

constexpr QPressure Pascal(1.0);
constexpr QPressure bar = 100000 * Pascal;
constexpr QPressure si_pres = kg / (metre*(second*second));
constexpr SqPressure Pascal2 = Pascal * Pascal;
constexpr SqPressure bar2 = bar * bar;
constexpr QNumber barp = bar / bar;
constexpr QNumber Pascalp = Pascal / Pascal;

//***********************
// Physical unit literals:
//***********************

// literals for length units
constexpr QLen operator"" _mm(long double x) { return static_cast<double>(x)*mm; }
constexpr QLen operator"" _cm(long double x) { return static_cast<double>(x)*cm; }
constexpr QLen operator"" _m(long double x) { return static_cast<double>(x)*metre; }
constexpr QLen operator"" _km(long double x) { return static_cast<double>(x)*km; }
constexpr QLen operator"" _mm(unsigned long long int x) { return static_cast<double>(x)*mm; }
constexpr QLen operator"" _cm(unsigned long long int  x) { return static_cast<double>(x)*cm; }
constexpr QLen operator"" _m(unsigned long long int  x) { return static_cast<double>(x)*metre; }
constexpr QLen operator"" _km(unsigned long long int  x) { return static_cast<double>(x)*km; }

// literals for speed units
constexpr QVelocity operator"" _mps(long double x) { return QVelocity(x); };
constexpr QVelocity operator"" _kmph(long double x) { return static_cast<double>(x)* (km/hour); };
constexpr QVelocity operator"" _mps(unsigned long long int x)
{ return QVelocity(static_cast<long double>(x)); };
constexpr QVelocity operator"" _kmph(unsigned long long int x)
{return static_cast<double>(x)* (km/hour); };

// literals for time units
constexpr QTime operator"" _s(long double x) { return QTime(x); };
constexpr QTime operator"" _min(long double x) { return static_cast<double>(x)*minute; };
constexpr QTime operator"" _h(long double x) { return static_cast<double>(x)*hour; };
constexpr QTime operator"" _day(long double x) { return static_cast<double>(x)*day; };
constexpr QTime operator"" _s(unsigned long long int x) { return QTime(static_cast<double>(x)); };
constexpr QTime operator"" _min(unsigned long long int x) { return static_cast<double>(x)*minute; };
constexpr QTime operator"" _h(unsigned long long int x) { return static_cast<double>(x)*hour; };
constexpr QTime operator"" _day(unsigned long long int x) { return static_cast<double>(x)*day; };

// literals for mass units
constexpr QMass operator"" _kg(long double x) { return QMass(x); };
constexpr QMass operator"" _g(long double x) { return static_cast<double>(x)*gramme; };
constexpr QMass operator"" _t(long double x) { return static_cast<double>(x)*tonne; };
constexpr QMass operator"" _kg(unsigned long long int x) { return QMass(static_cast<double>(x)); };
constexpr QMass operator"" _g(unsigned long long int x) { return static_cast<double>(x)*gramme; };
constexpr QMass operator"" _t(unsigned long long int x) { return static_cast<double>(x)*tonne; };

// literals for elec units
constexpr QElec operator"" _amper(long double x) { return static_cast<double>(x)*amper; }
constexpr QElec operator"" _mA(long double x) { return static_cast<double>(x)*mA; }
constexpr QElec operator"" _amper(unsigned long long int x) { return static_cast<double>(x)*amper; }
constexpr QElec operator"" _mA(unsigned long long int  x) { return static_cast<double>(x)*mA; }

// literals for temp units
constexpr QTemp operator"" _kelvin(long double x) { return static_cast<double>(x)*Kelvin; }
constexpr QTemp operator"" _kelvin(unsigned long long int x) { return static_cast<double>(x)*Kelvin; }

// literals for elec units
constexpr QMol operator"" _mol(long double x) { return static_cast<double>(x)*mol; }
constexpr QMol operator"" _mol(unsigned long long int x) { return static_cast<double>(x)*mol; }

// literals for lum units
constexpr QLum operator"" _lum(long double x) { return static_cast<double>(x)*cd; }
constexpr QLum operator"" _lum(unsigned long long int x) { return static_cast<double>(x)*cd; }


// literals for acceleration units
constexpr QAcceleration operator"" _mps2(long double x) { return QAcceleration(x); };
constexpr QAcceleration operator"" _mps2(unsigned long long int x)
                                        { return QAcceleration(static_cast<double>(x)); };
constexpr QAcceleration operator"" _G(long double x) { return static_cast<double>(x)*a; };
constexpr QAcceleration operator"" _G(unsigned long long int x) { return static_cast<double>(x)*a; }

// literals for force units
constexpr QForce operator"" _N(long double x) { return QForce(x); };
constexpr QForce operator"" _N(unsigned long long int x) { return QForce(static_cast<double>(x)); };
constexpr QForce operator"" _kp(long double x) { return static_cast<double>(x)*kilopond; };
constexpr QForce operator"" _kp(unsigned long long int x) { return static_cast<double>(x)*kilopond; };
constexpr QForce operator"" _si_ero(long double x) { return static_cast<double>(x)*si_ero; };
constexpr QForce operator"" _si_ero(unsigned long long int x) { return static_cast<double>(x)*si_ero; };

// literals for pressure units
constexpr QPressure operator"" _Pa(long double x) { return QPressure(x); };
constexpr QPressure operator"" _Pa(unsigned long long int x)
{ return QPressure(static_cast<double>(x)); };
constexpr QPressure operator"" _bar(long double x) { return static_cast<double>(x)*bar; };
constexpr QPressure operator"" _bar(unsigned long long int x) { return static_cast<double>(x)*bar; };
constexpr QPressure operator"" _si_pres(long double x) { return static_cast<double>(x)*si_pres; };
constexpr QPressure operator"" _si_pres(unsigned long long int x) { return static_cast<double>(x)*si_pres; };
// Conversion macro, which utilizes the string literals
#define ConvertTo(_x, _y) (_x).Convert(1.0_##_y)



// Read
template< typename M, typename L, typename t, typename I, typename T, typename n, typename Iv>
istream& operator>>( istream& in, RQuantity<M, L, t, I, T, n, Iv>& rhs)
{
    in >> rhs;
    return in;
}

void kiiras(char &op,string &p1, string &p2, QMass &sol1, QMass &sol2, QLen &soll1, QLen &soll2, QTime &solt1, QTime &solt2, QVelocity &solv1, QVelocity &solv2, QElec &sole1, QElec &sole2, QTemp &solT1, QTemp &solT2, QMol &solm1, QMol &solm2, QLum &solL1, QLum &solL2, QAcceleration &solgy1, QAcceleration &solgy2, QForce &solF1, QForce &solF2, QPressure &soln1, QPressure &soln2, double &num1, double &num2, string &rhs)
{
    
    if(p1 == "kg"){
          sol1 = num1 * kg;
    }
    else if(p1 == "t"){
          sol1 = num1 * tonne;
    }
    else if(p1 == "g"){
         sol1 = num1 * gramme;
    }
    else if(p1 == "dkg"){
         sol1 = num1 * dkg;
    }
    
    else if(p1 == "m"){
        soll1 = num1 * metre;
    }
    else if(p1 == "km"){
            soll1 = num1 * km;
    }
    else if(p1 == "cm"){
        soll1 = num1 * cm;
    }
    else if(p1 == "dm"){
            soll1 = num1 * dm;
       }
    else if(p1 == "mm"){
            soll1 = num1 * mm;
    }
    
    else if(p1 == "s"){
          solt1 = num1 * second;
    }
    else if(p1 == "h"){
          solt1 = num1 * hour;
    }
    else if(p1 == "min"){
          solt1 = num1 * minute;
    }
    else if(p1 == "d"){
          solt1 = num1 * day;
    }
    
    else if(p1 == "mps"){
        solv1 = num1 * mps;
    }
    else if(p1 == "kmph"){
        solv1 = num1 * kmh;
    }
       
    else if(p1 == "mps"){
        solv1 = num1 * mps;
    }
    else if(p1 == "kmph"){
        solv1 = num1 * kmh;
    }
    else if(p1 == "A"){
        sole1 = num1 * amper;
    }
    else if(p1 == "mA"){
        sole1 = num1 * mA;
    }
    else if(p1 == "mol"){
        solm1 = num1 * mol;
    }
    else if(p1 == "K"){
        solT1 = num1 * Kelvin;
    }
    else if(p1 == "cd"){
        solL1 = num1 * cd;
    }
    else if(p1 == "mps2"){
        solgy1 = num1 * a;
    }
    else if(p1 == "N"){
        solF1 = num1 * Newton;
    }
    else if(p1 == "kga"){
        solF1 = num1 * Newton;
    }
    else if(p1 == "kgmps2"){
        solF1 = num1 * Newton;
    }
    else if(p1 == "Pa"){
        soln1 = num1 * Pascal;
    }
    else if(p1 == "bar"){
        soln1 = num1 * bar;
    }
    
    if(p2 == "kg"){
          sol2 = num2 * kg;
    }
    else if(p2 == "t"){
        sol2 = num2 * tonne;
    }
    else if(p2 == "g"){
            sol2 = num2 * gramme;
    }
    else if(p2 == "dkg"){
            sol2 = num2 * dkg;
    }
    
    else if(p2 == "m"){
          soll2 = num2 * metre;
    }
    else if(p2 == "km"){
            soll2 = num2 * km;
    }
    else if(p2 == "cm"){
            soll2 = num2 * cm;
    }
    else if(p2 == "dm"){
            soll2 = num2 * dm;
    }
    else if(p2 == "mm"){
            soll2 = num2 * mm;
    }
    
    else if(p2 == "s"){
          solt2 = num2 * second;
    }
    else if(p2 == "h"){
            solt2 = num2 * hour;
    }
    else if(p2 == "min"){
            solt2 = num2 * minute;
    }
    else if(p2 == "d"){
            solt2 = num2 * day;
    }
    
    else if(p2 == "mps"){
          solv2 = num2 * mps;
    }
    else if(p2 == "kmph"){
            solv2 = num2 * kmh;
    }
    else if(p2 == "A"){
        sole1 = num1 * amper;
    }
    else if(p2 == "mA"){
        sole2 = num2 * mA;
    }
    else if(p2 == "mol"){
        solm2 = num2 * mol;
    }
    else if(p2 == "K"){
        solT2 = num2 * Kelvin;
    }
    else if(p2 == "cd"){
        solL2 = num2 * cd;
    }
    else if(p2 == "mps2"){
        solgy2 = num2 * a;
    }
    else if(p2 == "N"){
        solF2 = num2 * Newton;
    }
    else if(p2 == "kga"){
        solF2 = num2 * Newton;
    }
    else if(p2 == "kgmps2"){
        solF2 = num2 * Newton;
    }
    else if(p2 == "Pa"){
        soln2 = num2 * Pascal;
    }
    else if(p2 == "bar"){
        soln2 = num2 * bar;
    }

    
    switch(op)
    {
        case '+':
            if(rhs == "kg"){
            QMass megoldas = sol1 + sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(kg)<<" "<< rhs << endl;
            }
            else if(rhs == "g"){
            QMass megoldas = sol1 + sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(gramme)<<" "<< rhs << endl;
            }
            else if(rhs == "dkg"){
            QMass megoldas = sol1 + sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(dkg)<<" "<< rhs << endl;
            }
            else if(rhs == "t"){
            QMass megoldas = sol1 + sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(tonne)<<" "<< rhs << endl;
            }
            if(rhs == "km"){
            QLen megolldas = soll1 + soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(km)<<" "<< rhs << endl;
            }
            else if(rhs == "m"){
            QLen megolldas = soll1 + soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(metre)<<" "<< rhs << endl;
            }
            else if(rhs == "mm"){
            QLen megolldas = soll1 + soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(mm)<<" "<< rhs << endl;
            }
            else if(rhs == "dm"){
            QLen megolldas = soll1 + soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(dm)<<" "<< rhs << endl;
            }
            else if(rhs == "cm"){
            QLen megolldas = soll1 + soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(cm)<<" "<< rhs << endl;
            }
            if(rhs == "s"){
            QTime megoldast = solt1 + solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(second)<<" "<< rhs << endl;
            }
            else if(rhs == "min"){
            QTime megoldast = solt1 + solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(minute)<<" "<< rhs << endl;
            }
            else if(rhs == "h"){
            QTime megoldast = solt1 + solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(hour)<<" "<< rhs << endl;
            }
            else if(rhs == "d"){
            QTime megoldast = solt1 + solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(day)<<" "<< rhs << endl;
            }
            if(rhs == "mps"){
            QVelocity megoldasv = solv1 + solv2;
            cout << "The solution is: " << endl;
            cout << megoldasv.Convert(mps)<<" "<< rhs << endl;
            }
            else if(rhs == "kmph"){
            QVelocity megoldasv = solv1 + solv2;
            cout << "The solution is: " << endl;
            cout << megoldasv.Convert(kmh)<<" "<< rhs << endl;
            }
            else if(rhs == "A"){
            QElec megoldase = sole1 + sole2;
            cout << "The solution is: " << endl;
            cout << megoldase.Convert(amper)<<" "<< rhs << endl;
            }
            else if(rhs == "mA"){
            QElec megoldase = sole1 + sole2;
            cout << "The solution is: " << endl;
            cout << megoldase.Convert(mA)<<" "<< rhs << endl;
            }
            else if(rhs == "K"){
            QTemp megoldasT = solT1 + solT2;
            cout << "The solution is: " << endl;
            cout << megoldasT.Convert(Kelvin)<<" "<< rhs << endl;
            }
            else if(rhs == "mol"){
            QMol megoldasm = solm1 + solm2;
            cout << "The solution is: " << endl;
            cout << megoldasm.Convert(mol)<<" "<< rhs << endl;
            }
            else if(rhs == "cd"){
            QLum megoldasv = solL1 + solL2;
            cout << "The solution is: " << endl;
            cout << megoldasv.Convert(cd)<<" "<< rhs << endl;
            }
            else if(rhs == "Pa"){
            QPressure megoldasp = soln1 + soln2;
            cout << "The solution is: " << endl;
            cout << megoldasp.Convert(Pascal)<<" "<< rhs << endl;
            }
            else if(rhs == "bar"){
            QPressure megoldasp = soln1 + soln2;
            cout << "The solution is: " << endl;
            cout << megoldasp.Convert(bar)<<" "<< rhs << endl;
            }
            else if(rhs == "N" or "kga" or "akg" or "kgmps2" or "mps2kg"){
            QForce megoldasF = solF1 + solF2;
            cout << "The solution is: " << endl;
            cout << megoldasF.Convert(Newton)<<" "<< rhs << endl;
            }
            else if(rhs == "mps2"){
            QAcceleration megoldasgy = solgy1 + solgy2;
            cout << "The solution is: " << endl;
            cout << megoldasgy.Convert(a) <<" "<< rhs << endl;
            }
           
            break;

        case '-':
            if(rhs == "kg"){
            QMass megoldas = sol1 - sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(kg)<<" "<< rhs << endl;
            }
            else if(rhs == "g"){
            QMass megoldas = sol1 - sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(gramme)<<" "<< rhs << endl;
            }
            else if(rhs == "dkg"){
            QMass megoldas = sol1 - sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(dkg)<<" "<< rhs << endl;
            }
            else if(rhs == "t"){
            QMass megoldas = sol1 - sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(tonne)<<" "<< rhs << endl;
            }
            if(rhs == "km"){
            QLen megolldas = soll1 - soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(km)<<" "<< rhs << endl;
            }
            else if(rhs == "m"){
            QLen megolldas = soll1 - soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(metre)<<" "<< rhs << endl;
            }
            else if(rhs == "mm"){
            QLen megolldas = soll1 - soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(mm)<<" "<< rhs << endl;
            }
            else if(rhs == "dm"){
            QLen megolldas = soll1 - soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(dm)<<" "<< rhs << endl;
            }
            else if(rhs == "cm"){
            QLen megolldas = soll1 - soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(cm)<<" "<< rhs << endl;
            }
            if(rhs == "s"){
            QTime megoldast = solt1 - solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(second)<<" "<< rhs << endl;
            }
            else if(rhs == "min"){
            QTime megoldast = solt1 - solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(minute)<<" "<< rhs << endl;
            }
            else if(rhs == "h"){
            QTime megoldast = solt1 - solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(hour)<<" "<< rhs << endl;
            }
            else if(rhs == "d"){
            QTime megoldast = solt1 - solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(day)<<" "<< rhs << endl;
            }
            if(rhs == "mps"){
            QVelocity megoldasv = solv1 - solv2;
            cout << "The solution is: " << endl;
            cout << megoldasv.Convert(mps)<<" "<< rhs << endl;
            }
            else if(rhs == "kmph"){
            QVelocity megoldasv = solv1 - solv2;
            cout << "The solution is: " << endl;
            cout << megoldasv.Convert(kmh)<<" "<< rhs << endl;
            }
            else if(rhs == "A"){
            QElec megoldase = sole1 - sole2;
            cout << "The solution is: " << endl;
            cout << megoldase.Convert(amper)<<" "<< rhs << endl;
            }
            else if(rhs == "mA"){
            QElec megoldase = sole1 - sole2;
            cout << "The solution is: " << endl;
            cout << megoldase.Convert(mA)<<" "<< rhs << endl;
            }
            else if(rhs == "K"){
            QTemp megoldasT = solT1 - solT2;
            cout << "The solution is: " << endl;
            cout << megoldasT.Convert(Kelvin)<<" "<< rhs << endl;
            }
            else if(rhs == "mol"){
            QMol megoldasm = solm1 - solm2;
            cout << "The solution is: " << endl;
            cout << megoldasm.Convert(mol)<<" "<< rhs << endl;
            }
            else if(rhs == "cd"){
            QLum megoldasv = solL1 - solL2;
            cout << "The solution is: " << endl;
            cout << megoldasv.Convert(cd)<<" "<< rhs << endl;
            }
            else if(rhs == "Pa"){
            QPressure megoldasp = soln1 - soln2;
            cout << "The solution is: " << endl;
            cout << megoldasp.Convert(Pascal)<<" "<< rhs << endl;
            }
            else if(rhs == "bar"){
            QPressure megoldasp = soln1 - soln2;
            cout << "The solution is: " << endl;
            cout << megoldasp.Convert(bar)<<" "<< rhs << endl;
            }
            else if(rhs == "N" or "kga" or "akg" or "kgmps2" or "mps2kg"){
            QForce megoldasF = solF1 - solF2;
            cout << "The solution is: " << endl;
            cout << megoldasF.Convert(Newton)<<" "<< rhs << endl;
            }
            else if(rhs == "mps2"){
            QAcceleration megoldasgy = solgy1 - solgy2;
            cout << "The solution is: " << endl;
            cout << megoldasgy.Convert(a) <<" "<< rhs << endl;
            }
            break;

            
        case '*':
            if(rhs == "kg"){
            SqMass megoldas = sol1 * sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(kg2)<<" "<< rhs << endl;
            }
            else if(rhs == "g"){
            SqMass megoldas = sol1 * sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(gramme2)<<" "<< rhs << endl;
            }
            else if(rhs == "dkg"){
            SqMass megoldas = sol1 * sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(dkg2)<<" "<< rhs << endl;
            }
            else if(rhs == "t"){
            SqMass megoldas = sol1 * sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(tonne2)<<" "<< rhs << endl;
            }
            if(rhs == "km"){
            QArea megolldas = soll1 * soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(km2)<<" "<< rhs << endl;
            }
            else if(rhs == "m"){
            QArea megolldas = soll1 * soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(metre2)<<" "<< rhs << endl;
            }
            else if(rhs == "mm"){
            QArea megolldas = soll1 * soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(mm2)<<" "<< rhs << endl;
            }
            else if(rhs == "dm"){
            QArea megolldas = soll1 * soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(dm2)<<" "<< rhs << endl;
            }
            else if(rhs == "cm"){
            QArea megolldas = soll1 * soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(cm2)<<" "<< rhs << endl;
            }
            if(rhs == "s"){
            SqTime megoldast = solt1 * solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(second2)<<" "<< rhs << endl;
            }
            else if(rhs == "min"){
            SqTime megoldast = solt1 * solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(minute2)<<" "<< rhs << endl;
            }
            else if(rhs == "h"){
            SqTime megoldast = solt1 * solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(hour2)<<" "<< rhs << endl;
            }
            else if(rhs == "d"){
            SqTime megoldast = solt1 * solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(day2)<<" "<< rhs << endl;
            }
            if(rhs == "mps"){
            SqVelocity megoldasv = solv1 * solv2;
            cout << "The solution is: " << endl;
            cout << megoldasv.Convert(mps2)<<" "<< rhs << endl;
            }
            else if(rhs == "kmph"){
            SqVelocity megoldasv = solv1 * solv2;
            cout << "The solution is: " << endl;
            cout << megoldasv.Convert(kmh2)<<" "<< rhs << endl;
            }
            else if(rhs == "A"){
            SqElec megoldase2 = sole1 * sole2;
            cout << "The solution is: " << endl;
            cout << megoldase2.Convert(amper2)<<" "<< rhs << endl;
            }
            else if(rhs == "mA"){
            SqElec megoldase = sole1 * sole2;
            cout << "The solution is: " << endl;
            cout << megoldase.Convert(mA2)<<" "<< rhs << endl;
            }
            else if(rhs == "K"){
            SqTemp megoldasT = solT1 * solT2;
            cout << "The solution is: " << endl;
            cout << megoldasT.Convert(kelvin2)<<" "<< rhs << endl;
            }
            else if(rhs == "mol"){
            SqMol megoldasm = solm1 * solm2;
            cout << "The solution is: " << endl;
            cout << megoldasm.Convert(mol2)<<" "<< rhs << endl;
            }
            else if(rhs == "cd"){
            SqLum megoldasv = solL1 * solL2;
            cout << "The solution is: " << endl;
            cout << megoldasv.Convert(cd2)<<" "<< rhs << endl;
            }
            else if(rhs == "Pa"){
            SqPressure megoldasp = soln1 * soln2;
            cout << "The solution is: " << endl;
            cout << megoldasp.Convert(Pascal2)<<" "<< rhs << endl;
            }
            else if(rhs == "bar"){
            SqPressure megoldasp = soln1 * soln2;
            cout << "The solution is: " << endl;
            cout << megoldasp.Convert(bar2)<<" "<< rhs << endl;
            }
            else if(rhs == "N" or "kga" or "akg" or "kgmps2" or "mps2kg"){
            SqForce megoldasF = solF1 * solF2;
            cout << "The solution is: " << endl;
            cout << megoldasF.Convert(Newton2)<<" "<< rhs << endl;
            }
            else if(rhs == "mps2"){
            SqAcceleration megoldasgy = solgy1 * solgy2;
            cout << "The solution is: " << endl;
            cout << megoldasgy.Convert(a2) <<" "<< rhs << endl;
            }
            break;

            
        case '/':
            if(rhs == "kg"){
            QNumber megoldas = sol1 / sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(kgp)<<" "<< rhs << endl;
            }
            else if(rhs == "g"){
            QNumber megoldas = sol1 / sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(grammep)<<" "<< rhs << endl;
            }
            else if(rhs == "dkg"){
            QNumber megoldas = sol1 / sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(dkgp)<<" "<< rhs << endl;
            }
            else if(rhs == "t"){
            QNumber megoldas = sol1 / sol2;
            cout << "The solution is: " << endl;
            cout << megoldas.Convert(tonnep)<<" "<< rhs << endl;
            }
            if(rhs == "km"){
            QNumber megolldas = soll1 / soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(kmp)<<" "<< rhs << endl;
            }
            else if(rhs == "m"){
            QNumber megolldas = soll1 / soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(metrep)<<" "<< rhs << endl;
            }
            else if(rhs == "mm"){
            QNumber megolldas = soll1 / soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(mmp)<<" "<< rhs << endl;
            }
            else if(rhs == "dm"){
            QNumber megolldas = soll1 / soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(dmp) <<" "<< rhs << endl;
            }
            else if(rhs == "cm"){
            QNumber megolldas = soll1 / soll2;
            cout << "The solution is: " << endl;
            cout << megolldas.Convert(cmp)<<" "<< rhs << endl;
            }
            if(rhs == "s"){
            QNumber megoldast = solt1 / solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(secondp)<<" "<< rhs << endl;
            }
            else if(rhs == "min"){
            QNumber megoldast = solt1 / solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(minutep)<<" "<< rhs << endl;
            }
            else if(rhs == "h"){
            QNumber megoldast = solt1 / solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(hourp)<<" "<< rhs << endl;
            }
            else if(rhs == "d"){
            QNumber megoldast = solt1 / solt2;
            cout << "The solution is: " << endl;
            cout << megoldast.Convert(dayp) <<" "<< rhs << endl;
            }
            if(rhs == "mps"){
            QNumber  megoldasv = solv1 / solv2;
            cout << "The solution is: " << endl;
            cout << megoldasv.Convert(mpsp) <<" "<< rhs << endl;
            }
            else if(rhs == "kmph"){
            QNumber  megoldasv = solv1 / solv2;
            cout << "The solution is: " << endl;
            cout << megoldasv.Convert(kmhp) <<" "<< rhs << endl;
            }
            else if(rhs == "A"){
            QNumber megoldase2 = sole1 / sole2;
            cout << "The solution is: " << endl;
            cout << megoldase2.Convert(amperp)<<" "<< rhs << endl;
            }
            else if(rhs == "mA"){
            QNumber megoldase = sole1 / sole2;
            cout << "The solution is: " << endl;
            cout << megoldase.Convert(mAp)<<" "<< rhs << endl;
            }
            else if(rhs == "K"){
            QNumber megoldasT = solT1 / solT2;
            cout << "The solution is: " << endl;
            cout << megoldasT.Convert(kelvinp)<<" "<< rhs << endl;
            }
            else if(rhs == "mol"){
            QNumber megoldasm = solm1 / solm2;
            cout << "The solution is: " << endl;
            cout << megoldasm.Convert(molp)<<" "<< rhs << endl;
            }
            else if(rhs == "cd"){
            QNumber megoldasv = solL1 / solL2;
            cout << "The solution is: " << endl;
            cout << megoldasv.Convert(cdp)<<" "<< rhs << endl;
            }
            else if(rhs == "Pa"){
            QNumber megoldasp = soln1 / soln2;
            cout << "The solution is: " << endl;
            cout << megoldasp.Convert(Pascalp)<<" "<< rhs << endl;
            }
            else if(rhs == "bar"){
            QNumber megoldasp = soln1 / soln2;
            cout << "The solution is: " << endl;
            cout << megoldasp.Convert(barp)<<" "<< rhs << endl;
            }
            else if(rhs == "N" or "kga" or "akg" or "kgmps2" or "mps2kg"){
            QNumber megoldasF = solF1 / solF2;
            cout << "The solution is: " << endl;
            cout << megoldasF.Convert(Newtonp)<<" "<< rhs << endl;
            }
            else if(rhs == "mps2"){
            QNumber megoldasgy = solgy1 / solgy2;
            cout << "The solution is: " << endl;
            cout << megoldasgy.Convert(accp) <<" "<< rhs << endl;
            }
            break;

        default:
            // If the operator is other than +, -, * or /, error message is shown
            cout << "Error! operator is not correct";
            break;
    }
    
};

#endif /* Header_h */
