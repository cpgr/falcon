#ifndef TEMPERATUREDIFFUSION
#define TEMPERATUREDIFFUSION

#include "Diffusion.h"
#include "Material.h"

class TemperatureDiffusion;

template<>
InputParameters validParams<TemperatureDiffusion>();

class TemperatureDiffusion : public Diffusion
{
public:

  TemperatureDiffusion(std::string name, MooseSystem & moose_system, InputParameters parameters);
    
  virtual void subdomainSetup();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  std::vector<Real> *_thermal_conductivity;
  
};
#endif //TEMPERATUREDIFFUSION
