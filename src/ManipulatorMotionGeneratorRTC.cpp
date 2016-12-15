// -*- C++ -*-
/*!
 * @file  ManipulatorMotionGeneratorRTC.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "ManipulatorMotionGeneratorRTC.h"

// Module specification
// <rtc-template block="module_spec">
static const char* manipulatormotiongeneratorrtc_spec[] =
  {
    "implementation_id", "ManipulatorMotionGeneratorRTC",
    "type_name",         "ManipulatorMotionGeneratorRTC",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "ogata-lab",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ManipulatorMotionGeneratorRTC::ManipulatorMotionGeneratorRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_ManipulatorCommonInterface_CommonPort("ManipulatorCommonInterface_Common"),
    m_ManipulatorCommonInterface_MiddleLevelPort("ManipulatorCommonInterface_MiddleLevel"),
    m_MotionGeneratorServicePort("MotionGeneratorService")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ManipulatorMotionGeneratorRTC::~ManipulatorMotionGeneratorRTC()
{
}



RTC::ReturnCode_t ManipulatorMotionGeneratorRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  m_MotionGeneratorServicePort.registerProvider("MotionGeneratorService", "Manipulation::MotionGeneratorService", m_MotionGeneratorService);
  
  // Set service consumers to Ports
  m_ManipulatorCommonInterface_CommonPort.registerConsumer("ManipulatorCommonInterface_Common", "JARA_ARM::ManipulatorCommonInterface_Common", m_ManipulatorCommonInterface_Common);
  m_ManipulatorCommonInterface_MiddleLevelPort.registerConsumer("ManipulatorCommonInterface_MiddleLevel", "JARA_ARM::ManipulatorCommonInterface_Middle", m_ManipulatorCommonInterface_MiddleLevel);
  
  // Set CORBA Service Ports
  addPort(m_ManipulatorCommonInterface_CommonPort);
  addPort(m_ManipulatorCommonInterface_MiddleLevelPort);
  addPort(m_MotionGeneratorServicePort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ManipulatorMotionGeneratorRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ManipulatorMotionGeneratorRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ManipulatorMotionGeneratorRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ManipulatorMotionGeneratorRTC::onActivated(RTC::UniqueId ec_id)
{
  m_MotionGeneratorService.setCompPtr(this);
  return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t ManipulatorMotionGeneratorRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ManipulatorMotionGeneratorRTC::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ManipulatorMotionGeneratorRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ManipulatorMotionGeneratorRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ManipulatorMotionGeneratorRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ManipulatorMotionGeneratorRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ManipulatorMotionGeneratorRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


void ManipulatorMotionGeneratorRTC::followManipPlan(const Manipulation::ManipulationPlan& manipPlan)
{
	   for(int i=0; i<manipPlan.robotJointInfoSeq.length(); i++){
           for(int j=0; j<manipPlan.robotJointInfoSeq[i].jointInfoSeq.length(); j++){
		       m_ManipulatorCommonInterface_MiddleLevel->movePTPJointAbs(manipPlan.robotJointInfoSeq[i].jointInfoSeq[j].jointAngle);
           }
       }
}

void ManipulatorMotionGeneratorRTC::getCurrentRobotJointInfo(const Manipulation::RobotIdentifier& robotID, Manipulation::RobotJointInfo_out robotJoint){
	   JARA_ARM::JointPos* pos = new JARA_ARM::JointPos();
	   m_ManipulatorCommonInterface_Common->getFeedbackPosJoint(pos);
	   for(int i=0; i<robotJoint->jointInfoSeq.length(); i++){
		   robotJoint->jointInfoSeq[i].jointAngle = (*pos)[i];
	   }
}


extern "C"
{
 
  void ManipulatorMotionGeneratorRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(manipulatormotiongeneratorrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<ManipulatorMotionGeneratorRTC>,
                             RTC::Delete<ManipulatorMotionGeneratorRTC>);
  }
  
};


