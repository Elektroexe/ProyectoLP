#include "MatriuBasica.h"
#include <string>
using namespace std;
MatriuBasic::MatriuBasic()
{
	m_columnes = 0;
	m_files = 0;
	m_matriuReals = new float*[m_files];


}
MatriuBasic::MatriuBasic(string fitxert, int nFiles, int nColumnes)
{
	m_columnes = nColumnes;
	m_files = nFiles;

	m_matriuReals = new float*[nFiles];

	for (int fil = 0; fil < nFiles; fil++)
	{
		m_matriuReals[fil] = new float[nColumnes];
	}
	setValor(0);
	setValor(1);

}
MatriuBasic & MatriuBasic::operator=(const MatriuBasic & m)
{
	for (int fil = 0; fil < m_files; fil++)
	{
		delete[] m_matriuReals[fil];
	}
	delete[] m_matriuReals;


	m_files = m.m_files;
	m_columnes = m.m_columnes;
	m_matriuReals = m.m_matriuReals;
	for (int fil = 0; fil < m_files; fil++)
	{
		for (int col = 0; col < m_columnes; col++)
		{
			m_matriuReals[fil][col] = m.m_matriuReals[fil][col];
		}
	}



	return *this;
}

void MatriuBasic::init(int nFiles, int nColumnes)
{
	for (int fil = 0; fil < m_files; fil++) {
		delete[] m_matriuReals[fil];
	}
	delete[] m_matriuReals;

	m_files = nFiles;
	m_columnes = nColumnes;
	m_matriuReals = new float*[m_files];
	for (int fil = 0; fil < m_files; fil++)
	{
		m_matriuReals[fil] = new float[m_columnes];
	};

}

MatriuBasic MatriuBasic::operator*(float s)
{
	for (int fil = 0; fil < m_files; fil++) {
		for (int col = 0; col < m_columnes; col++) {
			m_matriuReals[fil][col] = s * m_matriuReals[fil][col];
		}
	}


	return *(this);
}
MatriuBasic MatriuBasic::operator*(const MatriuBasic & m)
{
	if (!(getNColumnes() == m.getNFiles()))
	{
		return MatriuBasic();
	};

	MatriuBasic mAuxiliar = MatriuBasic(getNFiles(), m.getNColumnes());

	for (int i = 0; i < getNFiles(); i++) {
		for (int j = 0; j < m.getNColumnes(); j++) {
			double suma = 0;



			for (int k = 0; k < getNColumnes(); k++) {

				suma += (*this)(i, k) * m(k, j);

			}
			mAuxiliar(i, j) = suma;
		}
	}
	return mAuxiliar;
}
bool MatriuBasic::esBuida() const
{
	if (m_files == 0 && m_columnes == 0)
	{
		return true;
	}
	return false;
}

void MatriuBasic::setValor(float valor)
{
	for (int fil = 0; fil < m_files; fil++)
	{
		for (int col = 0; col < m_columnes; col++)
		{
			m_matriuReals[fil][col] = valor;
		}
	}

}



float& MatriuBasic::operator()(int fila, int columna) {
	return m_matriuReals[fila][columna];
}

const float& MatriuBasic::operator()(int fila, int columna) const {
	return m_matriuReals[fila][columna];
}


MatriuBasic::MatriuBasic(const MatriuBasic & m)
{

	m_files = m.m_files;
	m_columnes = m.m_columnes;
	m_matriuReals = m.m_matriuReals;
	for (int fil = 0; fil < m_files; fil++)
	{
		for (int col = 0; col < m_columnes; col++)
		{
			m_matriuReals[fil][col] = m.m_matriuReals[fil][col];
		}
	}
}


MatriuBasic::MatriuBasic(int nFiles, int nColumnes)
{
	m_files = nFiles;
	m_columnes = nColumnes;
	m_matriuReals = new float*[nFiles];
	for (int i = 0; i < nFiles; i++)
	{
		m_matriuReals[i] = new float[nColumnes];
	}


}






