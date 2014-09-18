/****************************************************************/
/*             DO NOT MODIFY OR REMOVE THIS HEADER              */
/*          FALCON - Fracturing And Liquid CONvection           */
/*                                                              */
/*       (c) pending 2012 Battelle Energy Alliance, LLC         */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

//! Authors: Yidong Xia (Yidong.Xia@inl.gov)
//! Created: 08/18/2014

#ifndef DGTEMPERATUREDIFFUSION_H
#define DGTEMPERATUREDIFFUSION_H

#include "DGKernel.h"
#include "Material.h"

//Forward Declarations
class DGTemperatureDiffusion;

template<>
InputParameters validParams<DGTemperatureDiffusion>();

class DGTemperatureDiffusion : public DGKernel
{
  public:

    DGTemperatureDiffusion(const std::string & name, InputParameters parameters);
    
  protected:

    virtual Real computeQpResidual(Moose::DGResidualType type);
    virtual Real computeQpJacobian(Moose::DGJacobianType type);

    MaterialProperty<Real> & _diff;
    MaterialProperty<Real> & _diff_neighbor;

  private:
  
    /*
     * Penalty parameter
    */
    Real _epsilon;

    /*
     * Stability parameter
    */
    Real _sigma;
};

#endif //DGTEMPERATUREDIFFUSION_H
