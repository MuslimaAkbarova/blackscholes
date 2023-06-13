#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

// Cumulative standard normal distribution function
double N(double x)
{
    const double pi = 3.14159265358979323846;
    return 0.5 * (1 + erf(x / sqrt(2)));
}

double calculateBlackScholesCallPrice(double S, double K, double r, double sigma, double T)
{
    // Calculate d1 and d2
    double d1 = (log(S / K) + (r + 0.5 * pow(sigma, 2)) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    // Calculate the call price using the Black-Scholes formula
    double callPrice = S * N(d1) - K * exp(-r * T) * N(d2);
    return callPrice;
}

double calculateBlackScholesPutPrice(double S, double K, double r, double sigma, double T)
{
    // Calculate d1 and d2
    double d1 = (log(S / K) + (r + 0.5 * pow(sigma, 2)) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    // Calculate the put price using the Black-Scholes formula
    double putPrice = K * exp(-r * T) * N(-d2) - S * N(-d1);
    return putPrice;
}

int main()
{
    // Input parameters
    double S;       // Current price of the underlying asset
    double K;       // Strike price of the option
    double r;      // Risk-free interest rate
    double sigma;   // Volatility of the underlying asset
    double T;         // Time to expiration (in years)

    cout << "Current price of the underlying asset:" <<endl;
    cin >> S;
    cout << "Strike price of the option:" <<endl;
    cin >> K;
    cout << "Risk-free interest rate:" <<endl;
    cin >> r;
    cout << "Volatility of the underlying asset:" <<endl;
    cin >> sigma;
    cout << "Time to expiration (in years):" <<endl;
    cin >> T;

    auto startTime = chrono::high_resolution_clock::now();
    // Calculate call and put prices using the Black-Scholes model
    double callPrice = calculateBlackScholesCallPrice(S, K, r, sigma, T);
    double putPrice = calculateBlackScholesPutPrice(S, K, r, sigma, T);

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
    // Output the results
    cout << "Call Price: " << callPrice << endl;
    cout << "Put Price: " << putPrice << endl;
    cout << "Execution Time: " << duration.count() << " milliseconds" << endl;

    return 0;
}
