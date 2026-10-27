#include "RETRunAction.hh"
#include "RETDetectorConstruction.hh"
#include "RETPrimaryGeneratorAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"

#include "Randomize.hh"
#include <iomanip>


RETRunAction::RETRunAction(RETDetectorConstruction* det, RETPrimaryGeneratorAction* kin)
:detector(det), primary(kin)
{ }


RETRunAction::~RETRunAction()
{ }


void RETRunAction::BeginOfRunAction(const G4Run* aRun)
{  

  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
  edep = 0.;
  nonionedep = 0.; 
}

void RETRunAction::EndOfRunAction(const G4Run* aRun)
{ 

}

