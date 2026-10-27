#ifndef RETMATERIAL_HH  // Correct the include guard
#define RETMATERIAL_HH

#include "G4VUserDetectorConstruction.hh"  // Keep this if you plan to use it
#include "G4Material.hh"
#include "globals.hh"

class G4VPhysicalVolume;

class RETMaterial 
{
public:
    RETMaterial();  // Constructor
    virtual ~RETMaterial();  // Destructor
    void CreateMaterials();

private:
    // Private methods to create materials
    void CreateAir();
    void CreateSnow();
    void CreateIce();
    void CreateWater();
    void CreatePlastic();
    void CreateTyvek();
    void CreatePerlite();
    void CreateGlassSphere();
    void CreateEffectiveDOMMaterial();
    void CreateScintillatorMaterial();
    void CreateStyrofoam();
    void CreateWood();
    void CreateAluminium();
};

#endif // RETMATERIAL_HH
