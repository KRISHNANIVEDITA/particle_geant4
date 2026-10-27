#ifndef RETSteppingAction_h
#define RETSteppingAction_h 1

#include "G4UserSteppingAction.hh"

class RETRunAction;
class RETEventAction;


class RETSteppingAction : public G4UserSteppingAction
{
public:
   RETSteppingAction(RETRunAction*, RETEventAction*);
   ~RETSteppingAction() {};
   
   void UserSteppingAction(const G4Step*);
   
private:
   RETRunAction*    runAction;
   RETEventAction*  eventAction;
};


#endif
