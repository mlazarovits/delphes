//
// Author: Margaret Lazarovits (2022)
// A FastJet plug-in to geometrically incorporate timing into jet clustering via
// the Cambridge-Aachen algorithm.
//


#include "fastjet/GeometricTimePlugin.hh"
#include "fastjet/ClusterSequence.hh"
//to write - algorithm specific
#include "CA_GeometricAlgorithm.hh"

#include <iostream>
#include <sstream>

FASTJET_BEGIN_NAMESPACE

using namespace std;


// define description
string GeometricTimePlugin::description() const{
	ostringstream desc;
	desc << "Cambridge-Aachen algorithm with candidate times geometrically incorporated and ";
	desc << "R = " << Rmax() << ", "
	     << "time scale factor = " << weight();
	return desc.str();	
}


//define run_clustering
void GeometricTimePlugin::run_clustering(ClusterSequence &cs) const{
//get input pseudojets from cs
//declare input pseudojets

//run geo ca algo
//declare geo ca algo object
//run

//pass back to cs object via plugin_record_* (see: CDFMidpointPlugin.cc)





}

FASTJET_END_NAMESPACE
