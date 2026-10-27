#ifndef RETRunAction_h
#define RETRunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

class G4Run;
class RETDetectorConstruction;
class RETPrimaryGeneratorAction;

class RETRunAction : public G4UserRunAction
{
  public:
    RETRunAction(RETDetectorConstruction*, RETPrimaryGeneratorAction*);
   ~RETRunAction();

  public:
    void BeginOfRunAction(const G4Run*);
    void   EndOfRunAction(const G4Run*);
        
    void AddEdep(G4double val)     { edep += val;}
    void AddnonIonEdep(G4double val)     { nonionedep += val;}
                                  
  private:
    G4double        edep, nonionedep;
    RETDetectorConstruction*   detector;
    RETPrimaryGeneratorAction* primary;
};

#endif

