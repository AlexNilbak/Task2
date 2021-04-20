#include "Vector.h"
#include "Temp.h"

class Temp;

void Vector::Clean(){ 
	SetZero(); 
}
void Vector::SetZero(){ 
	v.clear(); n = 0; 
}

Vector::Vector(const Vector& b){
	CopyOnly(b); 
}

Vector& Vector::operator=(const Vector& b) {
	if (this != &b) {
		Clean();
		CopyOnly(b);
	}
	return *this;
}

Vector::Vector(const vector < double> b, int n, string filename) {
	this->n = n;
	v = b;
	this->filename = filename;
}

void Vector::CopyOnly(const Vector& b) {
	n = b.n;
	v = b.v;
}

void Vector::print() {
	for (auto i = v.begin(); i != v.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}

int Vector::length()const{ 
	return n; 
}

vector<double> Vector::GetVector()const{
	return v; 
}

const double& Vector::operator[](int i) const{
	if (i < 0 || i>=n) {
		printf("Incorrect index\n");
		throw - 4;
	}
	return v[i];
}

double Vector::operator*(const Vector& b) {
	if (n != b.n) {
		printf("Incorrect length\n");
		return 0;
	}
	else {
		double res=0;
		for (int i = 0; i < n; i++) {
			res += v[i] * b[i];
		}
		return res;
	}
}


Temp Vector::operator[](int i) {
	if (i < 0) {
		throw - 1;
	}
	return Temp(this, i);
}
