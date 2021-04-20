#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Temp;
void AutoTest();
class VectorHori;

class Vector {
protected:
	vector<double> v;
	int n;
	string filename;
public:
	virtual int output(const string filename) = 0;

	const string GetFileName(){ 
		return filename; 
	};
	void SetFileName(const string s){ 
		filename = s; 
	};

	Vector(){ 
		SetZero(); 
	}
	~Vector(){ 
		Clean();
	}
	void Clean();
	void SetZero();
	Vector(const Vector& b);
	Vector(const vector<double> b, int n, string filename);
	Vector& operator=(const Vector& b);
	void CopyOnly(const Vector& b);
	void print();
	int length()const;
	void Setn(int m) { 
		Clean(); 
		n = m; 
		v.resize(n); 
	}
	vector<double> GetVector()const;
	const double& operator[](int i) const;
	double operator*(const Vector& b);
	Temp operator[](int i);
	friend class Temp;
	friend VectorHori operator+(const Vector& a, const Vector& b);
	friend VectorHori operator-(const Vector& a, const Vector& b);
};
