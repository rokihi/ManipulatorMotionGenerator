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
    m_manipulatorCommonInterface_CommonPort("manipulatorCommonInterface_Common"),
    m_manipulatorCommonInterface_MiddleLevelPort("manipulatorCommonInterface_MiddleLevel"),
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
  m_manipulatorCommonInterface_CommonPort.registerConsumer("manipulatorCommonInterface_Common", "JARA_ARM::ManipulatorCommonInterface_Common", m_manipulatorCommonInterface_Common);
  m_manipulatorCommonInterface_MiddleLevelPort.registerConsumer("manipulatorCommonInterface_MiddleLevel", "JARA_ARM::ManipulatorCommonInterface_Middle", m_manipulatorCommonInterface_MiddleLevel);
  
  // Set CORBA Service Ports
  addPort(m_manipulatorCommonInterface_CommonPort);
  addPort(m_manipulatorCommonInterface_MiddleLevelPort);
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


Manipulation::ReturnValue* ManipulatorMotionGeneratorRTC::followManipPlan(const Manipulation::ManipulationPlan& manipPlan)
{
	  for(int i =0;i<manipPlan.robotJointInfoSeq.length(); i++){
		  for(int j=0;j<6;j++){
			  std::cout << manipPlan.robotJointInfoSeq[i].jointInfoSeq[j].jointAngle << " ";
		  }
		  std::cout <<std::endl;
	  }

	JARA_ARM::JointPos_var jpos = new JARA_ARM::JointPos();
    m_manipulatorCommonInterface_Common->getFeedbackPosJoint(jpos);

	for (int i = 0; i<manipPlan.robotJointInfoSeq.length(); i++){
		for(int j=0; j<manipPlan.robotJointInfoSeq[i].jointInfoSeq.length(); j++){
			jpos[j] = manipPlan.robotJointInfoSeq[i].jointInfoSeq[j].jointAngle;
		}
		m_manipulatorCommonInterface_MiddleLevel->movePTPJointAbs(jpos);
	}

	Manipulation::ReturnValue_var result(new Manipulation::ReturnValue());
	result->id = Manipulation::OK;
	result->message = CORBA::string_dup("OK");
	return result._retn();
}

Manipulation::ReturnValue* ManipulatorMotionGeneratorRTC::getCurrentRobotJointInfo(Manipulation::JointAngleSeq_out jointAngles){
	   JARA_ARM::JointPos* pos = new JARA_ARM::JointPos();
	   m_manipulatorCommonInterface_Common->getFeedbackPosJoint(pos);
	   for(int i=0; i<jointAngles->length(); i++){
		   jointAngles[i].data = (*pos)[i];
	   }
	Manipulation::ReturnValue_var result(new Manipulation::ReturnValue());
	result->id = Manipulation::OK;
	result->message = CORBA::string_dup("OK");
	return result._retn();
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


