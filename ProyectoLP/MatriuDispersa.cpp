#include "MatriuDispersa.h"
//#include "MatriuDispersa.h"
//#include <string>
//using namespace std;
//MatriuDispersa::MatriuDispersa()
//{
//	m_columnes = 0;
//	m_files = 0;
//	m_matriuReals = new float*[m_files];
//
//
//}
//MatriuDispersa::MatriuDispersa(string fitxert, int nFiles, int nColumnes)
//{
//	m_columnes = nColumnes;
//	m_files = nFiles;
//
//	m_matriuReals = new float*[nFiles];
//
//	for (int fil = 0; fil < nFiles; fil++)
//	{
//		m_matriuReals[fil] = new float[nColumnes];
//	}
//	setVal(0);
//
//
//}
//MatriuDispersa::MatriuDispersa(string fitxert)
//{
//
//
//}
//MatriuDispersa & MatriuDispersa::operator=(const MatriuDispersa & m)
//{
//	for (int fil = 0; fil < m_files; fil++)
//	{
//		delete[] m_matriuReals[fil];
//	}
//	delete[] m_matriuReals;
//
//
//	m_files = m.m_files;
//	m_columnes = m.m_columnes;
//	m_matriuReals = m.m_matriuReals;
//	for (int fil = 0; fil < m_files; fil++)
//	{
//		for (int col = 0; col < m_columnes; col++)
//		{
//			m_matriuReals[fil][col] = m.m_matriuReals[fil][col];
//		}
//	}
//
//
//
//	return *this;
//}
//
//void MatriuDispersa::init(int nFiles, int nColumnes)
//{
//	for (int fil = 0; fil < m_files; fil++) {
//		delete[] m_matriuReals[fil];
//	}
//	delete[] m_matriuReals;
//
//	m_files = nFiles;
//	m_columnes = nColumnes;
//	m_matriuReals = new float*[m_files];
//	for (int fil = 0; fil < m_files; fil++)
//	{
//		m_matriuReals[fil] = new float[m_columnes];
//	};
//
//}
//
//void MatriuDispersa::setVal(const int& nFiles,const  int& nColumnes, const int& valor)
//{
//	m_matriuReals[nFiles][nColumnes] = valor;
//}
//
//MatriuDispersa MatriuDispersa::operator*(float s)
//{
//	for (int fil = 0; fil < m_files; fil++) {
//		for (int col = 0; col < m_columnes; col++) {
//			m_matriuReals[fil][col] = s * m_matriuReals[fil][col];
//		}
//	}
//
//
//	return *(this);
//}
//MatriuDispersa MatriuDispersa::operator*(const MatriuDispersa & m)
//{
//	if (!(getNColumnes() == m.getNFiles()))
//	{
//		return MatriuDispersa();
//	};
//
//	MatriuDispersa mAuxiliar = MatriuDispersa(getNFiles(), m.getNColumnes());
//
//	for (int i = 0; i < getNFiles(); i++) {
//		for (int j = 0; j < m.getNColumnes(); j++) {
//			double suma = 0;
//
//
//
//			for (int k = 0; k < getNColumnes(); k++) {
//
//				suma += (*this)(i, k) * m(k, j);
//
//			}
//			mAuxiliar(i, j) = suma;
//		}
//	}
//	return mAuxiliar;
//}
//bool MatriuDispersa::esBuida() const
//{
//	if (m_files == 0 && m_columnes == 0)
//	{
//		return true;
//	}
//	return false;
//}
//
//void MatriuDispersa::setVal(const int& valor)
//{
//	for (int fil = 0; fil < m_files; fil++)
//	{
//		for (int col = 0; col < m_columnes; col++)
//		{
//			m_matriuReals[fil][col] = valor;
//		}
//	}
//
//}
//
//int MatriuDispersa::getVal(int nFiles, int nColumnes)
//{
//	return m_matriuReals[nFiles][nColumnes];
//}
//
//bool MatriuDispersa::getVal(int nFiles, int nColumnes, float valor)
//{
//	bool trobat = false;
//	if (m_matriuReals[nFiles][nColumnes] ==valor)
//	{
//		trobat = true;
//	}
//	return trobat;
//}
//
//
//
//float& MatriuDispersa::operator()(int fila, int columna) {
//	return m_matriuReals[fila][columna];
//}
//
//const float& MatriuDispersa::operator()(int fila, int columna) const {
//	return m_matriuReals[fila][columna];
//}
//
//
//MatriuDispersa::MatriuDispersa(const MatriuDispersa & m)
//{
//
//	m_files = m.m_files;
//	m_columnes = m.m_columnes;
//	m_matriuReals = m.m_matriuReals;
//	for (int fil = 0; fil < m_files; fil++)
//	{
//		for (int col = 0; col < m_columnes; col++)
//		{
//			m_matriuReals[fil][col] = m.m_matriuReals[fil][col];
//		}
//	}
//}
//
//
//MatriuDispersa::MatriuDispersa(int nFiles, int nColumnes)
//{
//	m_files = nFiles;
//	m_columnes = nColumnes;
//	m_matriuReals = new float*[nFiles];
//	for (int i = 0; i < nFiles; i++)
//	{
//		m_matriuReals[i] = new float[nColumnes];
//	}
//
//
//}
//
//ostream & operator<<(ostream & out, const MatriuDispersa & md)
//{
//	out << "" << endl;
//
//
//	return out;
//}

MatriuDispersa::MatriuDispersa()
{
}

MatriuDispersa::MatriuDispersa(string fitxert)
{
}

void MatriuDispersa::setVal(const int & nFiles, const int & nColumnes, const int & valor)
{
}

void MatriuDispersa::setVal(const int & valor)
{
}

void MatriuDispersa::sortVectors() {
	int valorRow = 0;
	int valorCol = 0;
	int valorVal = 0;
	for (int a = 0; a < colVector.size() - 1; a++) {
		for (int b = 0; b < colVector.size() - (a + 1); b++) {
			if ((rowVector.at(b) > rowVector.at(b + 1)) ||
				(rowVector.at(b) == rowVector.at(b + 1) && colVector.at(b) > colVector.at(b + 1))) {
				valorRow = rowVector.at(b + 1);
				valorCol = colVector.at(b + 1);
				valorVal = valVector.at(b + 1);
				rowVector.at(b + 1) = rowVector.at(b);
				colVector.at(b + 1) = colVector.at(b);
				valVector.at(b + 1) = valVector.at(b);
				rowVector.at(b) = valorRow;
				colVector.at(b) = valorCol;
				valVector.at(b) = valorVal;
			}
		}
	}
}

ostream & operator<<(ostream & out, const MatriuDispersa & md)
{
	int pos = 0;
	int posRow = md.rowVector.at(pos);
	int posCol = md.colVector.at(pos);
	int posVal = md.valVector.at(pos);
	for (int row = 0; row < md.maxRowCol; row++) {
		out << "\n ";
		for (int col = 0; col < md.maxRowCol; col++) {
			if (row == posRow && col == posCol) {
				out << md.valVector.at(pos) << "   ";
				if (pos < (md.rowVector.size() - 1)) {
					pos++;
					posRow = md.rowVector.at(pos);
					posCol = md.colVector.at(pos);
					posVal = md.valVector.at(pos);
				}
			}
			else {
				out << "0   ";
			}
		}
		out << "\n";
	}
	return out;
}
