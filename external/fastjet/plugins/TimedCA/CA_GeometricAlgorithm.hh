#ifndef CA_GEOMETRICALGORITHM_HH
#define CA_GEOMETRICALGORITHM_HH
//
// Author: Margaret Lazarovits (2022)
// A FastJet plug-in to geometrically incorporate timing into jet clustering via
// the Cambridge-Aachen algorithm.
//
#include <vector>
#include "Math/LorentzVector.h"
#include "Math/PtEtaPhiM4D.h"
#include "Math/Vector4D.h"
#include <fastjet/internal/base.hh>
FASTJET_BEGIN_NAMESPACE

//CDF declares these functions as part of its own namespace
//maybe we can try that later

typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<double>> LorentzVector;

class CA_GeometricAlgorithm
{
	public:
		CA_GeometricAlgorithm() :
			_Rmax(0.4),
			_weight(2.99792458E8){};

		CA_GeometricAlgorithm(double rmax, double weight) :
			_Rmax(rmax),
			_weight(weight){};

		void run(std::vector<LorentzVector> particles, std::vector<LorentzVector> jets);
	private:
		double _Rmax;
		double _weight;
		double DeltaR_T(LorentzVector particle1, LorentzVector particle2);

};

FASTJET_END_NAMESPACE
#endif
