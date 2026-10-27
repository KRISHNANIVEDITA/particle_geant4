#include "RETEventAction.hh"
#include "G4Event.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4VVisManager.hh"
#include "G4UnitsTable.hh"

RETEventAction::RETEventAction()
:drawFlag("none"),printModulo(10000)
{

}


RETEventAction::~RETEventAction()
{
  //delete eventMessenger;
}


void RETEventAction::BeginOfEventAction(const G4Event* evt)
{          
 TotalEnergyDeposit = 0.;
 TotalNonIonizingEnergyDeposit = 0.;
}


void RETEventAction::EndOfEventAction(const G4Event* evt)
{

}




