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


#include "ManipulatorMotionGeneratorRTC.h"
#ifndef TRAJECTORYPLANNERSVC_IMPL_H
#define TRAJECTORYPLANNERSVC_IMPL_H
class ManipulatorMotionGeneratorRTC;

/*!
 * @class MotionGeneratorServiceSVC_impl
 * Example class implementing IDL interface Manipulation::MotionGeneratorService
 */
class Manipulation_MotionGeneratorServiceSVC_impl
 : public virtual POA_Manipulation::MotionGeneratorService,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~MotionGeneratorServiceSVC_impl();
   ManipulatorMotionGeneratorRTC* m_rtcPtr;

 public:
  /*!
   * @brief standard constructor
   */
   Manipulation_MotionGeneratorServiceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~Manipulation_MotionGeneratorServiceSVC_impl();

   // attributes and operations
   Manipulation::ReturnValue* followManipPlan(const Manipulation::ManipulationPlan& manipPlan);
   Manipulation::ReturnValue* getCurrentRobotJointAngles(Manipulation::JointAngleSeq_out jointAngles);
   void setCompPtr(ManipulatorMotionGeneratorRTC* ptr){m_rtcPtr=ptr;}
};



#endif // TRAJECTORYPLANNERSVC_IMPL_H


