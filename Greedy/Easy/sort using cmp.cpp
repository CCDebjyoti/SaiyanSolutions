struct Item {
    int profit, weight;
    // Constructor
    Item(int profit, int weight){
        this->profit = profit;
        this->weight = weight;
    }
};
// Comparison function to sort Item 
// according to profit/weight ratio
static bool cmp(struct Item a, struct Item b){
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}
sort(arr, arr + N, cmp);
