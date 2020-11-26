//problem:-https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
// Complete the rotLeft function below.
vector<int> rotLeft(vector<int> a, int d) {
    int i=0;
    do{
        auto b=a.begin();
        a.push_back(*b);
        a.erase(a.begin());
        i++;
    }while(i<d);
    
    return a;
}

