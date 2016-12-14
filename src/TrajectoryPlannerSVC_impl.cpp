// -*-C++-*-
/*!
 * @file  TrajectoryPlannerSVC_impl.cpp
 * @brief Service implementation code of TrajectoryPlanner.idl
 *
 */

#include "TrajectoryPlannerSVC_impl.h"

/*
 * Example implementational code for IDL interface Manipulation::CurrentStateService
 */
CurrentStateServiceSVC_impl::CurrentStateServiceSVC_impl()
{
  // Please add extra destructor code here.
}


CurrentStateServiceSVC_impl::~CurrentStateServiceSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
void CurrentStateServiceSVC_impl::getCurrentState(Manipulation::RobotJointInfo_out robotJoint)
{

}



// End of example implementational code

/*
 * Example implementational code for IDL interface Manipulation::MotionGeneratorService
 */
MotionGeneratorServiceSVC_impl::MotionGeneratorServiceSVC_impl()
{
  // Please add extra destructor code here.
}


MotionGeneratorServiceSVC_impl::~MotionGeneratorServiceSVC_impl()
{
  // Please add extra destructor code here.
}

/*
 * Methods corresponding to IDL attributes and operations
 */
void MotionGeneratorServiceSVC_impl::followManipPlan(const Manipulation::ManipulationPlan& manipPlan)
{
	m_rtcPtr->followManipPlan(manipPlan);
}

void MotionGeneratorServiceSVC_impl::getCurrentRobotJointInfo(const Manipulation::RobotIdentifier& robotID, Manipulation::RobotJointInfo_out robotJoint)
{
	m_rtcPtr->getCurrentRobotJointInfo(robotID,robotJoint);
}



// End of example implementational code



