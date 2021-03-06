/* 
 * File:   ForbiddenZone.h
 * Author: michael
 *
 * Created on 26. mars 2013, 15:21
 */

#ifndef FORBIDDENZONE_H
#define	FORBIDDENZONE_H


#include "Polygon.h"


namespace ATCsim {  // Project ATCsim namespace.


class ForbiddenZone : public Polygon {
  
public:
  
  // Constructor takes x and y coordinates of a new forbidden zone.
  ForbiddenZone(const std::vector<int16_t>& xPoints,
                const std::vector<int16_t>& yPoints);
  
  // Use the default (member to member) copy ctor and copy assignment operator.
  ForbiddenZone(const ForbiddenZone& orig) = default;
  ForbiddenZone& operator=(const ForbiddenZone& orig) = default;
  // Use the default (member to member) move ctor and move assignment operator.
  ForbiddenZone(ForbiddenZone&& orig) = default;
  ForbiddenZone& operator=(ForbiddenZone&& orig) = default;
  
  // Default : call base class'es destructor and destructors of all members.
  // Does not throw any exception (which is what we want for a dtor).
  virtual ~ForbiddenZone() noexcept(true) = default;
  
  // Redeclaration of virtual methods inherited from Entity class.
  virtual void compute(PosTypes posType, int gameFieldWidth, int gameFieldHeight) final;
  
  // Redirection method used to implement double dispatching (visitor pattern).
  virtual void checkForCollisionDispatch(Entity& entity, PosTypes posType) const final;
  
protected:
  
private:

  // Prohibit default constructor usage.
  // Mark methods that won’t be implemented with '= delete' (C++11).
  ForbiddenZone() = delete;

};
  

}  // End of project ATCsim namespace.


#endif	/* FORBIDDENZONE_H */

