#ifndef RETPhysicsList_h
#define RETPhysicsList_h 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"

class RETPhysicsList: public G4VUserPhysicsList
{
public:
   RETPhysicsList();
   ~RETPhysicsList();
   
protected:
   // Construct particle and physics process
   void ConstructParticle();
   void ConstructProcess();
   void SetCuts();
   
protected:
   // these methods Construct particles 
   void ConstructBosons();
   void ConstructLeptons();
   void ConstructMesons();
   void ConstructBaryons();
	
protected:
	// these methods Construct physics processes and register them
   void ConstructGeneral();
   void ConstructEM();
   void AddStepMax();
};

#endif

