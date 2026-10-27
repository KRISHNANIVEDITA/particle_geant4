#ifndef RETEventAction_h
#define RETEventAction_h 1

#include "G4UserEventAction.hh"
#include "G4ThreeVector.hh"
#include "globals.hh"

class RETEventAction : public G4UserEventAction
{
  public:
    RETEventAction();
   ~RETEventAction();

  public:
    void BeginOfEventAction(const G4Event*);
    void   EndOfEventAction(const G4Event*);
    
    void AddEdep(G4double Edep)    {TotalEnergyDeposit += Edep;};
    G4double GetEnergyDeposit()    {return TotalEnergyDeposit;}; 
	
	 void AddnonIonEdep(G4double Edep)    {TotalNonIonizingEnergyDeposit += Edep;}; 
    G4double GetNonIonizingEnergyDeposit()    {return TotalNonIonizingEnergyDeposit;}; 
	
    void SetDrawFlag(G4String val) {drawFlag = val;};
    void SetPrintModulo(G4int val) {printModulo = val;};
	
	 void SetPrimaryVertex(G4ThreeVector val) {PrimaryVertex = val;};         
    G4ThreeVector GetPrimaryVertex() {return PrimaryVertex;};
	
  private:
    G4double                  TotalEnergyDeposit;
	 G4double                  TotalNonIonizingEnergyDeposit;
	 G4ThreeVector			      PrimaryVertex;	
    G4String                  drawFlag;
    G4int                     printModulo;                    
};

#endif

    
