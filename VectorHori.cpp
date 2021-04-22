#include "VectorHori.h"

int VectorHori::output(const string FileName){
	ofstream fout(FileName,ios_base::app);
	for (auto i = v.begin(); i != v.end(); ++i) {
		fout << *i << ' ';
	}
	fout << '\n' << '\n';
	fout.close();
    return 0;
}

VectorHori operator+(const Vector& a, const Vector& b) {
	string filename = "start";
	if (a.n != b.n) {
		printf("Error. Incorrect length\n");
		return a;
	}
	else{
		vector<double>d(a.n);
		for (int i = 0; i < a.n; i++) d[i] = a.v[i] + b[i];
		VectorHori res(d, a.n, filename);
		return res;
	}
}

VectorHori operator-(const Vector& a, const Vector& b) {
	string filename = "start";
	if (a.n != b.n) {
		printf("Error. Incorrect length\n");
		return a;
	}
	else {
		vector<double>d(a.n);
		for (int i = 0; i < a.n; i++) d[i] = a.v[i] - b[i];
		VectorHori res(d, a.n, filename);
		return res;
	}
}
