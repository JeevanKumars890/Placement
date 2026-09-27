// An agricultural produce market weighs every incoming tractor load twice, 
    // once loaded and once empty, and pays the farmer on the difference. 
    // Given the loaded weight in kg, the empty tractor weight in kg, 
    // and the rate payable per quintal, compute the net produce weight in kg, 
    // the same weight expressed in quintals, and the amount payable. One quintal is 100 kg.
    //  Read three values on one line: loaded weight in kg (whole number), empty tractor weight in kg (whole number), and rate per quintal (decimal). 
    //  Print the net weight in kg, the net weight in quintals to two decimal places, and the amount payable to two decimal places.
    #include <stdio.h>
    int main( void) {
        double ratePerQuinta;
        int loadedkg, emptykg;
        int read=scanf("%d %d %lf", &loadedkg, &emptykg, &ratePerQuinta);
        int netkg = loadedkg - emptykg;
        double netQuintals = (double)netkg / 100.0;
        double amount = netQuintals * ratePerQuinta;
        printf("%d\n%.2f\n%.2f\n", netkg, netQuintals, amount);
        return 0;
    }