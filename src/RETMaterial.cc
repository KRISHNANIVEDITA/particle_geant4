#include "RETMaterial.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4SystemOfUnits.hh"
#include "G4MaterialPropertiesTable.hh"
#include "G4UnitsTable.hh"
#include "G4Element.hh"




RETMaterial::RETMaterial() {
    // Constructor implementation (if needed)
}

RETMaterial::~RETMaterial() {
    // Destructor implementation (if needed)
}



void RETMaterial::CreateMaterials()
{
  CreateAir();
  CreateIce();
  CreateSnow();
  CreateWater();
  CreatePlastic();
  CreateScintillatorMaterial();
  CreateStyrofoam();
  CreateWood();
  CreateAluminium();
}

void RETMaterial::CreateAir()
{
  G4NistManager* nistManager = G4NistManager::Instance();
  nistManager->ConstructNewGasMaterial("Air", "G4_AIR", (273.15 - 40.0) * kelvin, 670.0E-3 * bar);
}

void RETMaterial::CreateSnow()
{
  G4NistManager* nistManager = G4NistManager::Instance();
  G4Material* snow = new G4Material("Snow", 0.38 * g / cm3, 2, kStateSolid);
  snow->AddElement(nistManager->FindOrBuildElement("H"), 2);
  snow->AddElement(nistManager->FindOrBuildElement("O"), 1);
}

void RETMaterial::CreateIce()
{
  G4NistManager* nistManager = G4NistManager::Instance();
  G4Material* ice = new G4Material("Ice", 0.92 * g / cm3, 2, kStateSolid);
  ice->AddElement(nistManager->FindOrBuildElement("H"), 2);
  ice->AddElement(nistManager->FindOrBuildElement("O"), 1);

  const G4int ice_bins = 2;
  G4double ice_ephot[ice_bins] = {1.91 * eV, 4.13 * eV};
  G4double ice_refr[ice_bins] = {1.31, 1.31};
  G4MaterialPropertiesTable *mpt_ice = new G4MaterialPropertiesTable();
  mpt_ice->AddProperty("RINDEX", ice_ephot, ice_refr, ice_bins);
  ice->SetMaterialPropertiesTable(mpt_ice);
}

void RETMaterial::CreateWater()
{
  G4NistManager* nistManager = G4NistManager::Instance();
  G4Material* water = new G4Material("Water", 1.0 * g / cm3, 2, kStateLiquid);
  water->AddElement(nistManager->FindOrBuildElement("H"), 2);
  water->AddElement(nistManager->FindOrBuildElement("O"), 1);
}

void RETMaterial::CreatePlastic()
{
  G4NistManager* nistManager = G4NistManager::Instance();
  G4Material* plastic = new G4Material("Plastic", 1.425 * g / cm3, 3, kStateSolid);
  plastic->AddElement(nistManager->FindOrBuildElement("H"), 2);
  plastic->AddElement(nistManager->FindOrBuildElement("C"), 1);
  plastic->AddElement(nistManager->FindOrBuildElement("O"), 1);
}

void RETMaterial::CreateTyvek()
{
  G4NistManager* nistManager = G4NistManager::Instance();
  G4Material* tyvek = new G4Material("Tyvek", 0.304 * g / cm3, 2, kStateSolid);
  tyvek->AddElement(nistManager->FindOrBuildElement("H"), 4);
  tyvek->AddElement(nistManager->FindOrBuildElement("C"), 2);
}

void RETMaterial::CreatePerlite()
{
  G4Material* water = G4Material::GetMaterial("Water");
  if (!water) return;

  G4NistManager* nistManager = G4NistManager::Instance();
  G4Material* perlite = new G4Material("Perlite", 0.1598 * g / cm3, 13, kStateSolid);
  perlite->AddElement(nistManager->FindOrBuildElement("Si"), 0.0240);
  perlite->AddElement(nistManager->FindOrBuildElement("Al"), 0.0051);
  perlite->AddElement(nistManager->FindOrBuildElement("K"), 0.0025);
  perlite->AddElement(nistManager->FindOrBuildElement("Na"), 0.0024);
  perlite->AddElement(nistManager->FindOrBuildElement("Fe"), 0.0004);
  perlite->AddElement(nistManager->FindOrBuildElement("Ca"), 0.0004);
  perlite->AddElement(nistManager->FindOrBuildElement("Mg"), 0.0001);
  perlite->AddElement(nistManager->FindOrBuildElement("Mn"), 0.0001);
  perlite->AddMaterial(water, 0.0021);
}

void RETMaterial::CreateGlassSphere()
{
  G4NistManager* nistManager = G4NistManager::Instance();
  G4Material* glass = new G4Material("Glass", 2.254 * g / cm3, 2, kStateSolid);
  glass->AddElement(nistManager->FindOrBuildElement("Si"), 1);
  glass->AddElement(nistManager->FindOrBuildElement("O"), 2);
}

void RETMaterial::CreateEffectiveDOMMaterial()
{
  G4NistManager* nistManager = G4NistManager::Instance();
  G4Material* effectiveDOM = new G4Material("EffectiveDOM", 0.2 * g / cm3, 2, kStateSolid);
  effectiveDOM->AddElement(nistManager->FindOrBuildElement("Si"), 1);
  effectiveDOM->AddElement(nistManager->FindOrBuildElement("O"), 2);
}

void RETMaterial::CreateScintillatorMaterial()
{ 
  G4cout << "Created scintillator mat" << G4endl; // Debug message
  G4NistManager* nistManager = G4NistManager::Instance();
  G4double density_polystyrene = 1.06 * g / cm3;
  G4Material* polystyrene = new G4Material("Polystyrene", density_polystyrene, 2, kStateSolid);
  polystyrene->AddElement(nistManager->FindOrBuildElement("H"), 8);
  polystyrene->AddElement(nistManager->FindOrBuildElement("C"), 8);

  G4double density_POPOP = 1.204 * g / cm3;
  G4Material* POPOP = new G4Material("POPOP", density_POPOP, 4);
  POPOP->AddElement(nistManager->FindOrBuildElement("C"), 24);
  POPOP->AddElement(nistManager->FindOrBuildElement("H"), 16);
  POPOP->AddElement(nistManager->FindOrBuildElement("N"), 2);
  POPOP->AddElement(nistManager->FindOrBuildElement("O"), 2);

  G4double density_PPO = 1.094 * g / cm3;
  G4Material* PPO = new G4Material("PPO", density_PPO, 4);
  PPO->AddElement(nistManager->FindOrBuildElement("C"), 15);
  PPO->AddElement(nistManager->FindOrBuildElement("H"), 11);
  PPO->AddElement(nistManager->FindOrBuildElement("N"), 1);
  PPO->AddElement(nistManager->FindOrBuildElement("O"), 1);

  G4double density_scintillator = 1. / (0.987 / density_polystyrene + 0.01 / density_PPO + 0.003 / density_POPOP);
  G4Material* scintillator = new G4Material("Scintillator_material", density_scintillator, 3, kStateSolid);
  scintillator->AddMaterial(polystyrene, 0.987);
  scintillator->AddMaterial(PPO, 0.01);
  scintillator->AddMaterial(POPOP, 0.003);

  G4MaterialPropertiesTable* mpt_sct = new G4MaterialPropertiesTable();
  const G4int nEntries = 2;
  G4double sci_ephot[nEntries] = {1.91 * eV, 4.13 * eV};
  G4double sci_refr[nEntries] = {1.59, 1.59};
  G4double sci_att[nEntries] = {2500 * mm, 2500 * mm};
  
  mpt_sct->AddProperty("RINDEX", sci_ephot, sci_refr, nEntries);
  mpt_sct->AddProperty("ABSLENGTH", sci_ephot, sci_att, nEntries);
  mpt_sct->AddConstProperty("FASTTIMECONSTANT", 2.1 * ns,true);
  scintillator->SetMaterialPropertiesTable(mpt_sct);
}

void RETMaterial::CreateStyrofoam()
{ G4cout << "Created styrofoam" << G4endl; // Debug message
  G4NistManager* nistManager = G4NistManager::Instance();
  G4Material* styrofoam = new G4Material("Styrofoam", 0.1 * g / cm3, 3);
  styrofoam->AddElement(nistManager->FindOrBuildElement("C"), 8);
  styrofoam->AddElement(nistManager->FindOrBuildElement("H"), 8);
  styrofoam->AddElement(nistManager->FindOrBuildElement("O"), 2);
}

void RETMaterial::CreateWood()
{   G4cout << "Created wood" << G4endl; // Debug message
  G4NistManager* nistManager = G4NistManager::Instance();
  G4Material* wood = new G4Material("Wood", 0.9 * g / cm3, 3);
  wood->AddElement(nistManager->FindOrBuildElement("C"), 6);
  wood->AddElement(nistManager->FindOrBuildElement("H"), 10);
  wood->AddElement(nistManager->FindOrBuildElement("O"), 5);
}

void RETMaterial::CreateAluminium()
{ G4cout << "Created aluminium" << G4endl; // Debug message
  G4NistManager* nistManager = G4NistManager::Instance();
  nistManager->FindOrBuildMaterial("G4_Al");
}


