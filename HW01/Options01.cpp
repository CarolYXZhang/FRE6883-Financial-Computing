//
//  Options01.cpp
//  HW1
//
//  Created by ZhangYixin on 2/4/20.
//  Copyright © 2020 NYU. All rights reserved.
//

#include "Options01.h"
#include "BinModel01.h"
#include <iostream>
#include <cmath>
using namespace std;
int GetInputData(int& N, double& K)
{
    cout<<"Enter steps to expiry N:";cin>>N;
    cout<<"Enter strike price K:";cin>>K;
    cout<<endl;
    return 0;
}

double CallPayoff(double z, double K)
{
    if(z>K) return z-K;
    return 0.0;
}

// fact is used to calculate factorial
int fact(int n)
{
    if (n==0 || n==1)
        return 1;
    else
        return n*fact(n-1);
}

double PriceByCRR(double S0, double U, double D, double R, int N, double K)
{
    double q=RiskNeutProb(U, D, R);
    double Price[N+1];
    double H0 = 0;
    for (int i=0;i<=N;i++)
    {
        Price[i]=CallPayoff(S(S0, U, D, N, i), K);
//    HW1: Using CRR formula
        H0 = H0 + fact(N)/fact(i)/fact(N-i)*pow(q,i)*pow(1-q,N-i)*Price[i];
    }
    H0 = H0/pow(1+R,N);
    return H0;
}
