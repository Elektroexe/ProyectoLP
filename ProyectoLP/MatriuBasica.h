#pragma once
#include <string>
using namespace std;
class MatriuBasic
{
public:
	MatriuBasic();
	MatriuBasic(string fitxert, int nFiles, int nColumnes);
	MatriuBasic(int nFiles, int nColumnes);
	MatriuBasic(const MatriuBasic& m);
	~MatriuBasic() { };

	void init(int nFiles, int nColumnes);
	void setValor(float valor);

	MatriuBasic& operator=(const MatriuBasic& m);
	MatriuBasic operator*(const MatriuBasic& m);
	MatriuBasic operator*(float s);

	bool esBuida() const;
	int getNFiles() const { return m_files; };
	int getNColumnes() const { return m_columnes; };
	float& operator()  (int fila, int columna);
	const float& operator()  (int fila, int columna)const;
private:
	float** m_matriuReals;
	int m_files;
	int m_columnes;

};