// -*-C++-*-
/*!
 * @file  TrajectoryPlannerSVC_impl.cpp
 * @brief Service implementation code of TrajectoryPlanner.idl
 *
 */

#include "TrajectoryPlannerSVC_impl.h"

/*
 * Example implementational code for IDL interface Manipulation::ObjectDetectionService
 */
ObjectDetectionServiceSVC_impl::ObjectDetectionServiceSVC_impl()
{
  // Please add extra constructor code here.
}


ObjectDetectionServiceSVC_impl::~ObjectDetectionServiceSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
void ObjectDetectionServiceSVC_impl::detectObject(const Manipulation::ObjectIdentifier& objectID, Manipulation::ObjectInfo_out objInfo)
{
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <void ObjectDetectionServiceSVC_impl::detectObject(const Manipulation::ObjectIdentifier& objectID, Manipulation::ObjectInfo_out objInfo)>"
#endif
}

void ObjectDetectionServiceSVC_impl::setGeometry(RTC::Geometry3D geometry)
{
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <void ObjectDetectionServiceSVC_impl::setGeometry(RTC::Geometry3D geometry)>"
#endif
}



// End of example implementational code

/*
 * Example implementational code for IDL interface Manipulation::CurrentStateService
 */
CurrentStateServiceSVC_impl::CurrentStateServiceSVC_impl()
{
  // Please add extra constructor code here.
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
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <void CurrentStateServiceSVC_impl::getCurrentState(Manipulation::RobotJointInfo_out robotJoint)>"
#endif
}



// End of example implementational code

/*
 * Example implementational code for IDL interface Manipulation::CollisionDetectionService
 */
CollisionDetectionServiceSVC_impl::CollisionDetectionServiceSVC_impl()
{
  // Please add extra constructor code here.
}


CollisionDetectionServiceSVC_impl::~CollisionDetectionServiceSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
CORBA::Boolean CollisionDetectionServiceSVC_impl::isCollide(const Manipulation::RobotIdentifier& manipInfo, const Manipulation::RobotJointInfo& jointSeq, Manipulation::CollisionInfo_out collision)
{
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <CORBA::Boolean CollisionDetectionServiceSVC_impl::isCollide(const Manipulation::RobotIdentifier& manipInfo, const Manipulation::RobotJointInfo& jointSeq, Manipulation::CollisionInfo_out collision)>"
#endif
  return 0;
}



// End of example implementational code

/*
 * Example implementational code for IDL interface Manipulation::ManipulationPlannerService
 */
ManipulationPlannerServiceSVC_impl::ManipulationPlannerServiceSVC_impl()
{
  // Please add extra constructor code here.
}


ManipulationPlannerServiceSVC_impl::~ManipulationPlannerServiceSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
void ManipulationPlannerServiceSVC_impl::planManipulation(const Manipulation::RobotIdentifier& robotID, const Manipulation::RobotJointInfo& startRobotJointInfo, RTC::Pose3D goalPose, Manipulation::ManipulationPlan_out manipPlan)
{
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <void ManipulationPlannerServiceSVC_impl::planManipulation(const Manipulation::RobotIdentifier& robotID, const Manipulation::RobotJointInfo& startRobotJointInfo, RTC::Pose3D goalPose, Manipulation::ManipulationPlan_out manipPlan)>"
#endif
}



// End of example implementational code

/*
 * Example implementational code for IDL interface Manipulation::ModelServerService
 */
ModelServerServiceSVC_impl::ModelServerServiceSVC_impl()
{
  // Please add extra constructor code here.
}


ModelServerServiceSVC_impl::~ModelServerServiceSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
void ModelServerServiceSVC_impl::getModelInfo(const Manipulation::RobotIdentifier& robotID, Manipulation::RobotJointInfo_out robotInfo)
{
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <void ModelServerServiceSVC_impl::getModelInfo(const Manipulation::RobotIdentifier& robotID, Manipulation::RobotJointInfo_out robotInfo)>"
#endif
}

void ModelServerServiceSVC_impl::getMeshInfo(const Manipulation::RobotIdentifier& robotID, Manipulation::MeshInfo_out mesh)
{
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <void ModelServerServiceSVC_impl::getMeshInfo(const Manipulation::RobotIdentifier& robotID, Manipulation::MeshInfo_out mesh)>"
#endif
}



// End of example implementational code

/*
 * Example implementational code for IDL interface Manipulation::MotionGeneratorService
 */
MotionGeneratorServiceSVC_impl::MotionGeneratorServiceSVC_impl()
{
  // Please add extra constructor code here.
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
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <void MotionGeneratorServiceSVC_impl::followManipPlan(const Manipulation::ManipulationPlan& manipPlan)>"
#endif
}

void MotionGeneratorServiceSVC_impl::getCurrentRobotJointInfo(const Manipulation::RobotIdentifier& robotID, Manipulation::RobotJointInfo_out robotJoint)
{
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <void MotionGeneratorServiceSVC_impl::getCurrentRobotJointInfo(const Manipulation::RobotIdentifier& robotID, Manipulation::RobotJointInfo_out robotJoint)>"
#endif
}



// End of example implementational code



