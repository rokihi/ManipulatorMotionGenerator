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

void MotionGeneratorServiceSVC_impl::openGripper()
{
	m_rtcPtr->openGripper();
}

void MotionGeneratorServiceSVC_impl::moveGripper(CORBA::Long percentage)
{
	m_rtcPtr->moveGripper(percentage);
}

// End of example implementational code



