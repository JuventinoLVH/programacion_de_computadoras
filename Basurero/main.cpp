#include <bits/stdc++.h>


using namespace std;

const int P0=40000;
const double k= log(2)/50;
const double e=exp(1);


double F(double t)
{
    return P0*pow(e,k*t);
}

const double k2=log(1+400/F(1));

double Fneta(double t)
{
    return (P0)*pow(e,k*t)+400*t*pow(e,k);
}

int main()
{
    double res=P0,resant=1;
    for(int i=0;i<=50;i++)
    {
        cout<<"Ano "<<i<<" Resultado manual: "<<res<<"\tResultado prop: "<<Fneta(i)<<'\n';
        res*=(pow(e,k));
        res+=400;

    }
    cout << e;
    return 0;
}
