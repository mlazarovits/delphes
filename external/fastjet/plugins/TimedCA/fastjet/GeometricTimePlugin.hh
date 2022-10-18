//
// Author: Margaret Lazarovits (2022)
// A FastJet plug-in to geometrically incorporate timing into jet clustering via
// the Cambridge-Aachen algorithm.
//


#ifndef GEOMETRICTIMEPLUGIN_HH
#define GEOMETRICTIMEPLUGIN_HH

#include "fastjet/JetDefinition.hh"


FASTJET_BEGIN_NAMESPACE


class GeometricTimePlugin : public JetDefinition::Plugin{
	public:
		GeometricTimePlugin(double Rmax_in,
				    double weight_in = 2.99792458E8):
		_Rmax (Rmax_in),
		_weight (weight_in)
		{}
	//to return info on parameters
	double Rmax() const {return _Rmax;}
	double weight() const {return _weight;}

	//base class requirements
	virtual std::string description() const;
	virtual void run_clustering(ClusterSequence &) const;
	//virtual ~GeometricTimePlugin() {};
  	/// the plugin mechanism's standard way of accessing the jet radius
  	virtual double R() const {return _Rmax;}
	
	private:
		double _Rmax;
		double _weight;
		//double c_light = 2.99792458E8;

		//void _print_banner();









};

FASTJET_END_NAMESPACE




#endif
