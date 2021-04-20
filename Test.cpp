#include "Vector.h"
#include "VectorHori.h"
void AutoTest() {
    vector<double>a(1);
    vector<double>b(1);
    a[0] = 0;
    b[0] = 1;
    string filename = "start";
    VectorHori A(a, 1, filename);
    VectorHori B(b, 1, filename);
    VectorHori C;
    C = A + B;
    if (C.GetVector()[0] == 1) {
        printf("Autotest passed.\n");
    }
    else {
        printf("Autotest failed.\n");
    }
}
