//
// Author: Margaret Lazarovits (2022)
// A FastJet plug-in to geometrically incorporate timing into jet clustering via
// the Cambridge-Aachen algorithm.
//

#include "CA_GeometricAlgorithm.hh"
#include <iostream>
#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE


double CA_GeometricAlgorithm::DeltaR_T(LorentzVector particle1, LorentzVector particle2){
	double phi1 = particle1.phi();
	double phi2 = particle2.phi();
	double eta1 = particle1.eta();
	double eta2 = particle2.eta();
//	double t1 = particle1.

	return pow(((phi1-phi2)*(phi1-phi2) + (eta1-eta2)*(eta1-eta2)),0.5);
}

void CA_GeometricAlgorithm::run(std::vector<LorentzVector> particles, std::vector<LorentzVector> jets){
//debug first
//LorentzVector coordinates originally in pt, eta, phi, m space
//test what is returned (ie v.x() == v.px()? or v.E() == v.T()?)
	int nParticles;
	int maxParticles = 10;
	particles.size() < 10 ? nParticles = particles.size() : nParticles = maxParticles;
	for(int i = 0; i < nParticles; i++){
		std::cout << "x: " << particles[i].x() << " px: " << particles[i].px() << " M: " << particles[i].M() << " T: " << particles[i].T() << std::endl;
	}
/*
	nParticles = particles.size();
	double Rmin = 999.;
	double Rmax = 0.;
	double R;
	std::vector<map<std::pair<int,int>,double>> idxs;
	pair<int,int> min_idxs;
	LorentzVector newjet;
//	loop through all pseudojets to find the smallest R2 (Rmin)
		for(int i = 0; i < nParticles; i++){
			for(int j = 0; j < nParticles; j++){
				if(i >= j) continue;
				R = DeltaR_T(particles[i],particles[j]);
				if(R*R < Rmin){ Rmin = R*R; min_idxs = std::make_pair(j,i);}
			}
		}
		//cluster the particles with the smallest R2 (Rmin)
		newjet = particles[min_idxs.first] + particles[min_idxs.second];
	 	particles.erase(particles.begin()+min_idxs.first); particles.erase(particles.begin()+min_idxs.second);
		particles.push_back(newjet);
		//if pseudojet Rmin is below R0, keep clustering
		if(Rmin < R0) return CA(particles,R0);
		//otherwise return the pseudoparticles
		else return particles;
*/
}
		
	
	
	
FASTJET_END_NAMESPACE
