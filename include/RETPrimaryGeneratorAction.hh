#ifndef RETPrimaryGeneratorAction_h
#define RETPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;

class RETPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
   RETPrimaryGeneratorAction();
   RETPrimaryGeneratorAction(G4bool, G4double);
   RETPrimaryGeneratorAction(G4String, G4double, G4double, G4double);
   RETPrimaryGeneratorAction(G4String, G4double, G4double, G4double, G4double, G4double);
   ~RETPrimaryGeneratorAction();
   
public:
   void SetNewParticle(G4String, G4double, G4double, G4double);
   void GeneratePrimaries(G4Event* anEvent);
	
	G4ParticleGun* GetParticleGun() {return particleGun;}
   
private:
   G4ParticleGun* particleGun;
   G4bool genRandomDirs;
};

#endif

