// -*-C++-*-
/*!
 * @file  TrajectoryPlannerSVC_impl.h
 * @brief Service implementation header of TrajectoryPlanner.idl
 *
 */

#include "BasicDataTypeSkel.h"
#include "ExtendedDataTypesSkel.h"
#include "InterfaceDataTypesSkel.h"

#include "TrajectoryPlannerSkel.h"

#ifndef TRAJECTORYPLANNERSVC_IMPL_H
#define TRAJECTORYPLANNERSVC_IMPL_H
 
/*!
 * @class CurrentStateServiceSVC_impl
 * Example class implementing IDL interface Manipulation::CurrentStateService
 */
class CurrentStateServiceSVC_impl
 : public virtual POA_Manipulation::CurrentStateService,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~CurrentStateServiceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   CurrentStateServiceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~CurrentStateServiceSVC_impl();

   // attributes and operations
   void getCurrentState(Manipulation::RobotJointInfo_out robotJoint);

};

/*!
 * @class MotionGeneratorServiceSVC_impl
 * Example class implementing IDL interface Manipulation::MotionGeneratorService
 */
class MotionGeneratorServiceSVC_impl
 : public virtual POA_Manipulation::MotionGeneratorService,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~MotionGeneratorServiceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   MotionGeneratorServiceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~MotionGeneratorServiceSVC_impl();

   // attributes and operations
   void followManipPlan(const Manipulation::ManipulationPlan& manipPlan);
   void getCurrentRobotJointInfo(const Manipulation::RobotIdentifier& robotID, Manipulation::RobotJointInfo_out robotJoint);

};



#endif // TRAJECTORYPLANNERSVC_IMPL_H


