//
//  main.cpp
//  HW1
//
//  Created by ZhangYixin on 2/4/20.
//  Copyright © 2020 NYU. All rights reserved.
//

#include "BinModel01.h"
#include "Options01.h"
#include <iostream>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double S0=0, U=0, D=0, R=0;
    if(GetInputData(S0,U,D,R)==1) return 1;
    double K = 0; //strike price
    int N = 0; //stpes to expiry
    cout<<"Enter call option data:"<<endl;
    GetInputData(N,K);
    cout<<"European call option price = "<<PriceByCRR(S0,U,D,R,N,K)<<endl<<endl;
    return 0;
}
/*
 Enter S0:106
 Enter U:0.15125
 Enter D:-0.13138
 Enter R:0.00545
 
 Input data checked
 There is no arbitrage
 
 Enter call option data:
 Enter steps to expiry N:8
 Enter strike price K:100
 
 European call option price = 21.6811
 
 Program ended with exit code: 0
*/
