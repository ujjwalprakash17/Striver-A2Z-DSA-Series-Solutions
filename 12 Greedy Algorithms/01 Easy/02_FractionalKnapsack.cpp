#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// bool basedOn()
// static bool basedOn(Item a, Item b) {
//     double ratio_a = static_cast<double>(a.value) / a.weight;
//     double ratio_b = static_cast<double>(b.value) / b.weight;
//     return ratio_a > ratio_b; // Sort in descending order
// }

// double fractionalKnapsack(int w, Item arr[], int n)
// {
//     // Your code here
//     sort(arr, arr + n , basedOn);
//     double result = 0;
//     for(int i = 0; i < n ; i++)
//     {
//         //if value is smaller then
//         if(w - arr[i].weight < 0)
//         {
//             result += (arr[i].value / arr[i].weight) * abs(w);
//             break;
//         }
//         else{
//         result += arr[i].value ;
//         w -= arr[i].weight;
//         }
//     }
//     return result;
// }

bool static comp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int w, Item arr[], int n)
{

    sort(arr, arr + n, comp);
    int currweight = 0;
    double totalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currweight + arr[i].weight <= w)
        {
            currweight += arr[i].weight;
            totalvalue += arr[i].value;
        }
        else
        {
            int remain = w - currweight;
            totalvalue += arr[i].value / (double)arr[i].weight * (double)remain;
            break;
        }
    }
    return totalvalue;
}

int main()
{
    Item arr[] = {60, 10, 100, 20, 120, 30};
    fractionalKnapsack(50, arr, 3);
    return 0;
}