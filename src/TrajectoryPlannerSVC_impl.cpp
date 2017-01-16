// -*-C++-*-
/*!
 * @file  TrajectoryPlannerSVC_impl.cpp
 * @brief Service implementation code of TrajectoryPlanner.idl
 *
 */

#include "TrajectoryPlannerSVC_impl.h"


/*
 * Example implementational code for IDL interface Manipulation::MotionGeneratorService
 */
Manipulation_MotionGeneratorServiceSVC_impl::Manipulation_MotionGeneratorServiceSVC_impl()
{
  // Please add extra constructor code here.
}


Manipulation_MotionGeneratorServiceSVC_impl::~Manipulation_MotionGeneratorServiceSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
Manipulation::ReturnValue* Manipulation_MotionGeneratorServiceSVC_impl::followManipPlan(const Manipulation::ManipulationPlan& manipPlan)
{
  return m_rtcPtr->followManipPlan(manipPlan);
}

Manipulation::ReturnValue* Manipulation_MotionGeneratorServiceSVC_impl::getCurrentRobotJointAngles(Manipulation::JointAngleSeq_out jointAngles)
{
  return m_rtcPtr->getCurrentRobotJointInfo(jointAngles);
}

void Manipulation_MotionGeneratorServiceSVC_impl::openGripper()
{
	m_rtcPtr->openGripper();
}

void Manipulation_MotionGeneratorServiceSVC_impl::moveGripper(CORBA::Long percentage)
{
	m_rtcPtr->moveGripper(percentage);
}

// End of example implementational code



