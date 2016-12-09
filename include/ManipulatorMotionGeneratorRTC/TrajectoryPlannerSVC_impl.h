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
 * @class ObjectDetectionServiceSVC_impl
 * Example class implementing IDL interface Manipulation::ObjectDetectionService
 */
class ObjectDetectionServiceSVC_impl
 : public virtual POA_Manipulation::ObjectDetectionService,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~ObjectDetectionServiceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   ObjectDetectionServiceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~ObjectDetectionServiceSVC_impl();

   // attributes and operations
   void detectObject(const Manipulation::ObjectIdentifier& objectID, Manipulation::ObjectInfo_out objInfo);
   void setGeometry(RTC::Geometry3D geometry);

};

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
 * @class CollisionDetectionServiceSVC_impl
 * Example class implementing IDL interface Manipulation::CollisionDetectionService
 */
class CollisionDetectionServiceSVC_impl
 : public virtual POA_Manipulation::CollisionDetectionService,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~CollisionDetectionServiceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   CollisionDetectionServiceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~CollisionDetectionServiceSVC_impl();

   // attributes and operations
   CORBA::Boolean isCollide(const Manipulation::RobotIdentifier& manipInfo, const Manipulation::RobotJointInfo& jointSeq, Manipulation::CollisionInfo_out collision);

};

/*!
 * @class ManipulationPlannerServiceSVC_impl
 * Example class implementing IDL interface Manipulation::ManipulationPlannerService
 */
class ManipulationPlannerServiceSVC_impl
 : public virtual POA_Manipulation::ManipulationPlannerService,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~ManipulationPlannerServiceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   ManipulationPlannerServiceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~ManipulationPlannerServiceSVC_impl();

   // attributes and operations
   void planManipulation(const Manipulation::RobotIdentifier& robotID, const Manipulation::RobotJointInfo& startRobotJointInfo, RTC::Pose3D goalPose, Manipulation::ManipulationPlan_out manipPlan);

};

/*!
 * @class ModelServerServiceSVC_impl
 * Example class implementing IDL interface Manipulation::ModelServerService
 */
class ModelServerServiceSVC_impl
 : public virtual POA_Manipulation::ModelServerService,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~ModelServerServiceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   ModelServerServiceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~ModelServerServiceSVC_impl();

   // attributes and operations
   void getModelInfo(const Manipulation::RobotIdentifier& robotID, Manipulation::RobotJointInfo_out robotInfo);
   void getMeshInfo(const Manipulation::RobotIdentifier& robotID, Manipulation::MeshInfo_out mesh);

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


