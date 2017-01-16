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
  m_manipulatorCommonInterface_CommonPort.registerConsumer("JARA_ARM_ManipulatorCommonInterface_Common", "JARA_ARM::ManipulatorCommonInterface_Common", m_manipulatorCommonInterface_Common);
  m_manipulatorCommonInterface_MiddleLevelPort.registerConsumer("JARA_ARM_ManipulatorCommonInterface_Middle", "JARA_ARM::ManipulatorCommonInterface_Middle", m_manipulatorCommonInterface_MiddleLevel);
  
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
         std::cout <<"waypoint: "<<manipPlan.manipPath.length()<<std::endl;
  	 for(int i =0;i<manipPlan.manipPath.length(); i++){
	   for(int j=0;j<manipPlan.manipPath[i].length();j++){
	          std::cout << manipPlan.manipPath[i][j].data << " ";
		  }
		  std::cout <<std::endl;
	  }

	JARA_ARM::JointPos_var jpos = new JARA_ARM::JointPos();
        //m_manipulatorCommonInterface_Common->getFeedbackPosJoint(jpos);
	jpos->length(manipPlan.manipPath[0].length());

	for (int i = 0; i<manipPlan.manipPath.length(); i++){
	        std::cout<<"waypoint: "<<i<<std::endl;
		for(int j=0; j<manipPlan.manipPath[i].length(); j++){
			jpos[j] = manipPlan.manipPath[i][j].data;
		}
		m_manipulatorCommonInterface_MiddleLevel->movePTPJointAbs(jpos);
	}

	Manipulation::ReturnValue_var result(new Manipulation::ReturnValue());
	result->id = Manipulation::OK;
	result->message = CORBA::string_dup("OK");
	return result._retn();
}

Manipulation::ReturnValue* ManipulatorMotionGeneratorRTC::getCurrentRobotJointInfo(Manipulation::JointAngleSeq_out jointAngles){
	JARA_ARM::JointPos_var pos = new JARA_ARM::JointPos();
	m_manipulatorCommonInterface_Common->getFeedbackPosJoint(pos);
    printf("current joint angles: %4.4f %4.4f %4.4f %4.4f %4.4f %4.4f\n", pos[0],pos[1],pos[2],pos[3],pos[4],pos[5]);

	Manipulation::JointAngleSeq_var tmpAngles;
	tmpAngles = new Manipulation::JointAngleSeq();
	tmpAngles->length(pos->length());

	for(int i=0; i<tmpAngles->length(); i++){
		tmpAngles[i].data = pos[i];
	}
	jointAngles = tmpAngles._retn();


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


